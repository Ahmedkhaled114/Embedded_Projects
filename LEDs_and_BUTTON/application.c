/* 
 * File:   application.c
 * Author: Ahmed khaled
 *
 * Created on March 11, 2021, 7:39 PM
 */



#include "application.h"
#include "device_confg.h"
#include "ecu/led/ecu_led.h"
#include "ecu/button/ecu_button.h"
#include "ecu/relay/ecu_relay.h"
#include "ecu/dc_motor/ecu_dc_motor.h"
 /*void perform_led_seq (led_t led_arr[] , uint8_t led_pat[][LED_SEQ_NUMBER] , uint8_t seq_len );*/
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
/*
uint8_t led_seq[][LED_SEQ_NUMBER]={
    {1, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 0, 0, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1}
};
 */

button_t btn1 = {.port_name = PORTD_INDEX , .pin = PIN0 , .button_status =BUTTON_NOT_PRESSED};
 
 uint8_t btn1_status = ZERO_INIT;
 

int main() {
    
    
    
    
    
    
    
    
    button_initialize( &btn1);
 
    uint8_t l_inti_counter = ZERO_INIT ;
    for (l_inti_counter = ZERO_INIT ; l_inti_counter <3 ; l_inti_counter++){
        
        led_initalize(&led_array[l_inti_counter]);
    }
    
    while ( TRUE ) {
        
        static uint8_t flag =ZERO_INIT;
        button_get_status(&btn1 , &btn1_status);
          
        if (btn1_status == TRUE && flag == ZERO_INIT ){
            
            led_turn_on(&led_array[0]);
            __delay_ms(500);
            led_turn_off(&led_array[0]);
            flag++;
            
        }
        else if (btn1_status == TRUE && flag ==1 ){
            
            uint8_t counter = ZERO_INIT;
            for (counter = ZERO_INIT ; counter <=1 ; counter++ )
            {led_turn_on(&led_array[1]);
            __delay_ms(500);
            led_turn_off(&led_array[1]);
            __delay_ms(500);
              }
            flag++;
            
            }
             
        else if (btn1_status == TRUE && flag ==2 ){
            
            uint8_t counter = ZERO_INIT;
            for (counter = ZERO_INIT ; counter <=2 ; counter++ )
            {led_turn_on(&led_array[2]);
            __delay_ms(500);
            led_turn_off(&led_array[2]);
            __delay_ms(500);
            }
            flag++;
            
            }
        else if (btn1_status == TRUE && flag ==3 ){
            
            led_turn_on(&led_array[0]);
            led_turn_on(&led_array[1]);
            led_turn_on(&led_array[2]);
            flag++;
            __delay_ms(250);
            
            }
        else if (btn1_status == TRUE && flag ==4 ){
            
            led_turn_off(&led_array[0]);
            led_turn_off(&led_array[1]);
            led_turn_off(&led_array[2]);
            flag =0;
            __delay_ms(250);
            
            }
            
        };
    
    
    return (EXIT_SUCCESS);
}







/*

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
        
        __delay_ms(250);
    } 
};
 */