/* 
 * File:   application.c
 * Author: Ahmed khaled
 *
 * Created on March 11, 2021, 7:39 PM
 */

#include "application.h"

 void perform_led_seq (led_t led_arr[] , uint8_t led_pat[][LED_SEQ_NUMBER] , uint8_t seq_len );
/*
 * 
 */       
 
 led_t led_array [LED_SEQ_NUMBER]  = {  
    { .port_name = PORTC_INDEX , .pin = PIN0 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN1 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN2 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN3 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN4 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN5 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN6 , .led_status = LED_OFF },
    { .port_name = PORTC_INDEX , .pin = PIN7 , .led_status = LED_OFF }
} ;

uint8_t led_seq[][LED_SEQ_NUMBER]={
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};
 


 void perform_led_seq (led_t led_arr[] , uint8_t led_pat[][LED_SEQ_NUMBER] , uint8_t seq_len ){

    uint8_t l_led_counter = ZERO_INIT , l_led_pos =ZERO_INIT ;
    for(l_led_counter= ZERO_INIT ; l_led_counter <seq_len; l_led_counter ++ ){
        led_initalize(&led_arr[l_led_counter]);
    }
    
    for (l_led_counter= ZERO_INIT ; l_led_counter <seq_len; l_led_counter ++ ){
        
        
        for(l_led_pos=ZERO_INIT ; l_led_pos <LED_SEQ_NUMBER ;l_led_pos ++){
            
            if (led_pat [l_led_counter][l_led_pos] == 1){
                led_turn_on(&led_arr[l_led_pos]);
            
            }
            else {
                led_turn_off(&led_arr[l_led_pos]);
            }
        }
        
        __delay_ms(150);
    } 
};


int main() {

       
 
 
            while ( TRUE ) {
        
        perform_led_seq( led_array , led_seq ,8  );
            
        };
    
    
    return (EXIT_SUCCESS);
}









