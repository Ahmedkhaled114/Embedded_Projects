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

dc_motor_t dc_motor_1 = {{.port_name = PORTC_INDEX, .pin = PIN0, .relay_status = RELAY_OFF},
                         {.port_name = PORTC_INDEX, .pin = PIN1, .relay_status = RELAY_OFF}};
dc_motor_t dc_motor_2 = {{.port_name = PORTC_INDEX, .pin = PIN2, .relay_status = RELAY_OFF},
                         {.port_name = PORTC_INDEX, .pin = PIN3, .relay_status = RELAY_OFF}};
dc_motor_t dc_motor_3 = {{.port_name = PORTC_INDEX, .pin = PIN4, .relay_status = RELAY_OFF},
                         {.port_name = PORTC_INDEX, .pin = PIN5, .relay_status = RELAY_OFF}};
dc_motor_t dc_motor_4 = {{.port_name = PORTC_INDEX, .pin = PIN6, .relay_status = RELAY_OFF},
                         {.port_name = PORTC_INDEX, .pin = PIN7, .relay_status = RELAY_OFF}};

button_t btn_forward = {.port_name = PORTD_INDEX, .pin = PIN0, .button_status = BUTTON_NOT_PRESSED};
button_t btn_backward = {.port_name = PORTD_INDEX, .pin = PIN1, .button_status = BUTTON_NOT_PRESSED};
button_t btn_right = {.port_name = PORTD_INDEX, .pin = PIN2, .button_status = BUTTON_NOT_PRESSED};
button_t btn_left = {.port_name = PORTD_INDEX, .pin = PIN3, .button_status = BUTTON_NOT_PRESSED};
button_status btn_forward_status = 0, btn_backward_status = 0;
button_status btn_right_status = 0  , btn_left_status     = 0;

void robot_move_forward(void){
    dc_motor_rotate_right(&dc_motor_1);
    dc_motor_rotate_right(&dc_motor_2);
    dc_motor_rotate_right(&dc_motor_3);
    dc_motor_rotate_right(&dc_motor_4);
}

void robot_twist_right(void){
    dc_motor_rotate_right(&dc_motor_1);
    dc_motor_rotate_left(&dc_motor_2);
    dc_motor_rotate_left(&dc_motor_3);
    dc_motor_rotate_right(&dc_motor_4);
}

void robot_twist_left(void){
    dc_motor_rotate_left(&dc_motor_1);
    dc_motor_rotate_right(&dc_motor_2);
    dc_motor_rotate_right(&dc_motor_3);
    dc_motor_rotate_left(&dc_motor_4);
}

void robot_move_backward(void){
    dc_motor_rotate_left(&dc_motor_1);
    dc_motor_rotate_left(&dc_motor_2);
    dc_motor_rotate_left(&dc_motor_3);
    dc_motor_rotate_left(&dc_motor_4);
}

void robot_move_stop(void){
    dc_motor_stop(&dc_motor_1);
    dc_motor_stop(&dc_motor_2);
    dc_motor_stop(&dc_motor_3);
    dc_motor_stop(&dc_motor_4);
}


int main() {

    dc_motor_initialize(&dc_motor_1);
    dc_motor_initialize(&dc_motor_2);
    dc_motor_initialize(&dc_motor_3);
    dc_motor_initialize(&dc_motor_4);
    
    button_initialize(&btn_forward);
    button_initialize(&btn_backward);
    button_initialize(&btn_right);
    button_initialize(&btn_left);
    
    while(TRUE){
       
        
        button_get_status(&btn_forward, &btn_forward_status);
        button_get_status(&btn_backward, &btn_backward_status);
        button_get_status(&btn_right, &btn_right_status);
        button_get_status(&btn_left, &btn_left_status);
        
        if(btn_forward_status == BUTTON_PRESSED && btn_backward_status == BUTTON_NOT_PRESSED
           &&btn_right_status == BUTTON_NOT_PRESSED && btn_left_status == BUTTON_NOT_PRESSED){
            robot_move_forward();
        }
        else if(btn_forward_status ==BUTTON_NOT_PRESSED  && btn_backward_status == BUTTON_PRESSED
                &&btn_right_status == BUTTON_NOT_PRESSED && btn_left_status == BUTTON_NOT_PRESSED){
            robot_move_backward();
        }
        else if(btn_forward_status == BUTTON_NOT_PRESSED && btn_backward_status == BUTTON_NOT_PRESSED
           &&btn_right_status == BUTTON_PRESSED && btn_left_status == BUTTON_NOT_PRESSED){
           robot_twist_right();
        }
        else if(btn_forward_status == BUTTON_NOT_PRESSED && btn_backward_status == BUTTON_NOT_PRESSED
           &&btn_right_status == BUTTON_NOT_PRESSED && btn_left_status == BUTTON_PRESSED){
             robot_twist_left();
        }
        else{
            robot_move_stop();
        }
    }
    return (EXIT_SUCCESS);
}

