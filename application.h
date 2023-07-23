/* 
 * File:   application.h
 * Author: Hesham
 *
 * Created on July 21, 2023, 7:18 PM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H

#include "MCAL_Layer/std_libraries.h"
#include "MCAL_Layer/DIO/mcal_dio.h"
#include "HAL_Layer/LED/hal_led.h"
#include "HAL_Layer/button/hal_button.h"
#include "HAL_Layer/7_Segment/hal_seven_segment.h"


Std_ReturnType application_initialize(void);


#endif	/* APPLICATION_H */

