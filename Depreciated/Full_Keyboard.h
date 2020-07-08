//Keyboard.h
//Benjamin Ropple

void pin_enable(char *pin_num, int bytes);
void pin_direction(char * pin_num, char * direction, char* path, char *dir, int bytes, int str_pos);
void pin_value(char * pin_num, char * value, char * path, char *val, int str_pos);
int pin_read(char * pin_num, char * value, char * path, int str_pos);
void pin_active_low(char * pin_num, char * active_low, char * path, char * val, int str_pos);
char * insert_string(char * str1, char * str2, char * str3, int location);
void keyboard_setup(char * path, char * direction, char * value, char* active_low, int str_pos);
