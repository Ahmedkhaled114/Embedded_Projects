/* 
 * File:   std_types.h
 * Author: Ahmed khaled
 *
 * Created on March 11, 2021, 7:47 PM
 */

#ifndef STD_TYPES_H
#define	STD_TYPES_H

#include "xc.h"
#include "pic18.h"

typedef unsigned char uint8_t;
typedef unsigned short uint16_t ;
typedef unsigned int uint32_t ;

typedef signed char suint8_t ;
typedef signed short suint16_t;
typedef signed int suint32_t ;

#define _XTAL_FREQ 8000000UL
#define ZERO_INIT   0 
#define TRUE        1
#define FALSE       0 
 
typedef enum  {
    R_NOK ,
    R_OK        
} ret_status ;
 
//#define ZERO_INT 0 
#endif	/* STD_TYPES_H */

