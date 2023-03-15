/*
 * dcmotor.h
 *
 *  Created on: Oct 8, 2022
 *      Author: Weli
 */

#ifndef DCMOTORH
#define DCMOTORH

#include "std_types.h"


typedef enum
{
	STOP, CLOCKWISE, ANTICLOCKWISE
}DCMOTOR_STATE;

void DcMotor_Init(void);

void DcMotor_Rotate(DCMOTOR_STATE state,uint8 speed);




#endif
