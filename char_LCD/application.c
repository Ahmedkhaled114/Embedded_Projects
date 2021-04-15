/* 
 * File:   application.c
 * Author: Ahmed khaled
 *
 * Created on March 11, 2021, 7:39 PM
 */

#include "application.h"

/*
 * 
 */       



#if CHAR_LCD_MODE==4
char_lcd_t lcd_1 = {
    .lcd_data_port = PORTC_INDEX,
    .lcd_data_pin4 = PIN0,
    .lcd_data_pin5 = PIN1,
    .lcd_data_pin6 = PIN2,
    .lcd_data_pin7 = PIN3,
    .lcd_rs_pin    = PIN4,
    .lcd_en_pin    = PIN5
};

char_lcd_t lcd_2 = {
    .lcd_data_port = PORTD_INDEX,
    .lcd_data_pin4 = PIN0,
    .lcd_data_pin5 = PIN1,
    .lcd_data_pin6 = PIN2,
    .lcd_data_pin7 = PIN3,
    .lcd_rs_pin    = PIN4,
    .lcd_en_pin    = PIN5
};
#endif


void application_init(void){
#if CHAR_LCD_MODE==4
    lcd_intialize(&lcd_1);
    lcd_intialize(&lcd_2);
#endif
    
#if CHAR_LCD_MODE==8
    lcd_intialize(&lcd_1);
#endif
}
/*
uint8_t seconds = ZERO_INIT ; uint8_t minutes = ZERO_INIT ; uint8_t houres = ZERO_INIT ;
uint8_t seconds_txt [4];       uint8_t minutes_txt  [4];    uint8_t houres_txt  [4];
 */

const char character1[] = {14,10,17,17,17,17,31,0};
const char character2[] = {14,10,17,17,17,31,31,0};
const char character3[] = {14,10,17,17,31,31,31,0};
const char character4[] = {14,10,17,31,31,31,31,0};
const char character5[] = {14,10,31,31,31,31,31,0};
const char character6[] = {14,14,31,31,31,31,31,0};
const char blt[]        = {6,21,13,6,13,21,6,0};

const char Shab[]      = {31,21,14,4,4,4,4,0};
const char shab_bat1[] = {24,24,24,24,24,24,24,0};
const char shab_bat2[] = {28,28,28,28,28,28,28,0};
const char shab_bat3[] = {63,63,63,63,63,63,63,0};
const char mesg1[]     = {31,24,22,17,16,31,0,0};
const char mesg2[]     = {31,3,13,17,1,31,0,0};

int main() {

      application_init();
      lcd_send_string_data_pos(&lcd_2, 2, 0, " .. AHMED KHALED ..");
    lcd_send_custome_char(&lcd_1, 1, 16, mesg1, 5);
    lcd_send_custome_char(&lcd_1, 1, 17, mesg2, 6);
    lcd_send_custome_char(&lcd_1, 4, 1, Shab, 2);
    lcd_send_custome_char(&lcd_1, 3, 1, shab_bat1, 3);
    lcd_send_custome_char(&lcd_1, 2, 1, shab_bat2, 4);
    lcd_send_custome_char(&lcd_1, 1, 1, shab_bat3, 7);
    
lcd_send_custome_char(&lcd_1 ,1 ,18 ,blt ,1);
    while(TRUE){

        lcd_send_custome_char(&lcd_1 ,1 ,19 ,character1 ,0); __delay_ms(250);
        lcd_send_custome_char(&lcd_1 ,1 ,19 ,character2 ,0); __delay_ms(250);
        lcd_send_custome_char(&lcd_1 ,1 ,19 ,character3 ,0); __delay_ms(250);
        lcd_send_custome_char(&lcd_1 ,1 ,19 ,character4 ,0); __delay_ms(250);
        lcd_send_custome_char(&lcd_1 ,1 ,19 ,character5 ,0); __delay_ms(250);
        lcd_send_custome_char(&lcd_1 ,1 ,19 ,character6 ,0); __delay_ms(250);
        }
    
    return (EXIT_SUCCESS);
}





     /*
      *        for(houres = ZERO_INIT ; houres <= 24 ; houres ++){
            for(minutes = ZERO_INIT ; minutes <= 60 ; minutes ++){
                for(seconds = ZERO_INIT ; seconds <= 60 ; seconds ++){
                    
                    byte_to_string( houres , houres_txt);
                    byte_to_string( minutes , minutes_txt);
                    byte_to_string( seconds , seconds_txt);
                    
                    lcd_send_string_data_pos( &lcd_1 , 1 , 6  ,  houres_txt);
                   lcd_send_string_data_pos( &lcd_1 , 1 , 12 , minutes_txt);
                    lcd_send_string_data_pos( &lcd_1 , 1 , 18 , seconds_txt);
             }
           }
          } 
*/


     /*
        */