#include <stdio.h> 
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#include "YM2612.h"
#include "YM2612_Songs.h"
#include "Keyboard.h"
#include "i2c_1602.h"
#include "mcps.h"
#include "Clock.h"
 
static char timestr[16] = "foo";
static char datestr[16] = "bar";
static char * twelvehr;

static char alarmstr[10] = "temp";

static int alarm_hour = 8;
static int alarm_minute = 30;

static char alarm_hour_disp[2] = "8";		//default alarm time is 8:30 AM
static char alarm_minute_disp[2] = "30";
static char alarm_second_disp[2] = "00";
static char alarm_twelvehr[2] = "AM";

 
int display_clock(char * path, char * direction, char * value, char* active_low, int str_pos){
	setup_chips(); //setup YM2612 for the alarm function
	int clockmode = 1;
	int menu = 0;
	int alarm_set = 0;
	int alarm_activated = 0;
	char * time_str;
	LCD_sendString("                ", 1);
	LCD_sendString("                ", 2);
	while(clockmode == 1){
		clock_begin:
		LCD_sendString(get_date(), 1);
		LCD_sendString(get_time(), 2);
		LCD_WritePos(1, 12, "    "); //keep menu text from staying on the screen
		LCD_WritePos(2, 11, "     "); //keep menu text from staying on the screen
		
		
		if(pin_read("18", value, path, str_pos) == 0x31){
			//something?
		}
		if(pin_read("14", value, path, str_pos) == 0x31){
			usleep(150000);
			if(alarm_set == 0) alarm_set = 1; //enable alarm for the default or picked time
			else alarm_set = 0; //disable alarm if it is already set
		}
		if(pin_read("15", value, path, str_pos) == 0x31){
			usleep(150000);
			menu = clock_menu(path, direction, value, active_low, str_pos);
			if(menu == 1){
				menu = 0;
				goto clock_begin;
			}
			if(menu == 2){
				alarm_set = 1; //an alarm time has been set, so code now watches out for that trigger
			}
			if(menu == 3){
				clockmode = 0;
				goto clock_close;
			}
		}	
		
		if(alarm_set == 1){
			LCD_WritePos(1, 15, "A");
			sprintf(alarmstr, "%s:%s:%s %s", alarm_hour_disp, alarm_minute_disp, alarm_second_disp, alarm_twelvehr);
			//printf("%s\n", alarmstr); //debug, see the alarm string in terminal
			if(strcmp(alarmstr, get_time()) == 0){
				alarm_activated = 1;
				while(alarm_activated == 1){
					Alarm_2612();
					if(pin_read("15", value, path, str_pos) == 0x31){
						usleep(150000);
						reset_2612();
						alarm_activated = 0;
						alarm_set = 0;
						goto clock_begin;
					}	
				}
			}
		}
		else LCD_WritePos(1, 15, " ");
		
		usleep(150000);
		
		
		
	}
	clock_close:
	return 0;
} 
 
char * get_time(void) {
    
    time_t rawtime = time(NULL);
    char space[1] = " ";
    
    if (rawtime == -1) {
        
        puts("The time() function failed!\n");
        return "time() fail!";
    }
    
    struct tm *ptm = localtime(&rawtime);
    
    if (ptm == NULL) {
        
        puts("The localtime() function failed!\n");
        return "localtime() fail!";
    }
    
    if(ptm->tm_hour < 12){
		twelvehr = "AM";
	}
	if(ptm->tm_hour > 12){
		ptm->tm_hour = ptm->tm_hour - 12;
		twelvehr = "PM";
	}
    if(ptm->tm_hour == 0){
		ptm->tm_hour = 12;
	}
	
	if(ptm->tm_hour < 10) sprintf(space, "%s", " ");
	else sprintf(space, "%s", "");
    
    sprintf(timestr, "%s%d:%02d:%02d %s",space, ptm->tm_hour, 
             ptm->tm_min, ptm->tm_sec, twelvehr);
    
    return timestr;
}

char * get_date(void){
	 time_t rawtime = time(NULL);
	 
	 if (rawtime == -1) {
        
        puts("The time() function failed!\n");
        return "time() fail!";
    }
    
    struct tm *ptm = localtime(&rawtime);
    
    if (ptm == NULL) {
        
        puts("The localtime() function failed!\n");
        return "localtime() fail!";
    }
	
	sprintf(datestr, "%s %d, %d", month_picker(ptm->tm_mon), ptm->tm_mday, ptm->tm_year + 1900);
	
	return datestr;
}

int clock_menu(char * path, char * direction, char * value, char* active_low, int str_pos) {
	clock_menu_begin:
	LCD_sendString("Clock Menu       ", 1);
	int menu = 1;
	int setalarm = 0;
	int selection = 0;
	while(menu == 1){
		while(selection == 0){
			LCD_sendString("->Return   Alarm", 2);
			if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					selection = 2;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					selection = 1;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					return 1;
				}
		}
		while(selection == 1){
			LCD_sendString("  Return ->Alarm", 2);
			if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					selection = 0;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					selection = 2;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					setalarm = Set_Alarm(path, direction, value, active_low, str_pos);
					if(setalarm == 1){
						return 2;
					}
				}
		}
		while(selection == 2){
			LCD_sendString("  Alarm   ->Main", 2);
			if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					selection = 1;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					selection = 0;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					return 3;
				}
		}
	}
	clock_menu_end:
	return 1;
}

int Set_Alarm(char * path, char * direction, char * value, char* active_low, int str_pos){ //set hour and minute and AM/PM for alarm
	alarm_begin: ;
	
	int state = 0;
	int set_state = 0;
	char hour[2] = "00"; //initializing the arrays with temp values
	char minute[2] = "00";
	char ampm[2] = "AM";
	char select_string[16] = "temp";
	
	int hour_selector = alarm_hour; //corresponds with hour
	int minute_selector = alarm_minute; //corresponds with minute
	int ampm_selector; //0 for AM, 1 for PM
	
	if(strcmp(alarm_twelvehr, "AM") == 0) {
		sprintf(ampm, "%s", "AM");
		ampm_selector = 0;
	}
	else {
		sprintf(ampm, "%s", "PM");
		ampm_selector = 1;
	}
	
	sprintf(hour, "%d", hour_selector);  //get the current alarm setting, whether if its the preset or a previously set value
	sprintf(minute, "%d", minute_selector);
	sprintf(ampm, "%s", alarm_twelvehr); //grab from alarm string, non-numeric binary choice
	
	while(state == 0){
		LCD_sendString(select_string, 1);
		LCD_sendString("                ", 2);
		if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					hour_selector--;
					if(hour_selector < 1) hour_selector = 12;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					hour_selector++;
					if(hour_selector > 12) hour_selector = 1;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					state = 1;
				}
				if(minute_selector < 10) sprintf(minute, "%d%d", 0, minute_selector); //update minute text;
				if(hour_selector < 10) sprintf(hour, "%s%d", " ", hour_selector); //update hour text;
				else sprintf(hour, "%d", hour_selector); //update hour text;
				sprintf(select_string, "->%s :  %s   %s", hour, minute, ampm);
			}
	while(state == 1){
		LCD_sendString(select_string, 1);
		if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					minute_selector--;
					if(minute_selector > 59) minute_selector = 1;
					else if(minute_selector < 0) minute_selector = 59;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					minute_selector++;
					if(minute_selector > 59) minute_selector = 0;
					else if(minute_selector < 0) minute_selector = 59;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					state = 2;
				}
				if(minute_selector < 10) sprintf(minute, "%d%d", 0, minute_selector); //update minute text;
				else sprintf(minute, "%d", minute_selector); //update minute text;
				sprintf(select_string, "  %s :->%s   %s", hour, minute, ampm);
			}
	while(state == 2){
		LCD_sendString(select_string, 1);
		if(pin_read("18", value, path, str_pos) == 0x31){
					usleep(150000);
					ampm_selector--;
					if(ampm_selector < 0) ampm_selector = 1;
				}
				if(pin_read("14", value, path, str_pos) == 0x31){
					usleep(150000);
					ampm_selector++;
					if(ampm_selector > 1) ampm_selector = 0;
				}
				if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					state = 3;
				}
				if(ampm_selector == 0) {
					sprintf(ampm, "%s", "AM");
					sprintf(select_string, "  %s :  %s ->%s", hour, minute, ampm);
				}
				else {
					sprintf(ampm, "%s", "PM");
					sprintf(select_string, "  %s :  %s ->%s", hour, minute, ampm);
				}
			}
	while(state == 3){
		while(set_state == 0) {
			LCD_sendString(select_string, 1);
			LCD_sendString("Set? ->Yes    No", 2);
			
			if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					
					alarm_hour = hour_selector;	//set the int quantities to correct values
					alarm_minute = minute_selector;
					
					
					sprintf(alarm_hour_disp, "%s", hour);  //set the alarm disp variables to the set quantities
					sprintf(alarm_minute_disp, "%s",minute);
					sprintf(alarm_twelvehr, "%s", ampm);
					return 1; //exit alarm function, go straight back to clock screen and set alarm to ON
			}
			if(pin_read("18", value, path, str_pos) == 0x31 || (pin_read("14", value, path, str_pos) == 0x31)){
				usleep(150000);
				set_state = 1;
			}
		}
		while(set_state == 1) {
			LCD_sendString(select_string, 1);
			LCD_sendString("Set?   Yes  ->No", 2);
			
			if(pin_read("15", value, path, str_pos) == 0x31){
					usleep(150000);
					goto alarm_begin; //reset the time if a mistake was made
			}
			if(pin_read("18", value, path, str_pos) == 0x31 || (pin_read("14", value, path, str_pos) == 0x31)){
				usleep(150000);
				set_state = 0;
			}
		}
	}
}

char * month_picker(int month_num){
	switch(month_num){
		case 0: return "Jan";
		case 1: return "Feb";
		case 2: return "Mar";
		case 3: return "Apr";
		case 4: return "May";
		case 5: return "Jun";
		case 6: return "Jul";
		case 7: return "Aug";
		case 8: return "Sep";
		case 9: return "Oct";
		case 10: return "Nov";
		case 11: return "Dec";
		default: return "ERR";
	}
}
