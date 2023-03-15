/*
 * main.c
 *
 *  Created on: Oct 8, 2022
 *      Author: Weli
 */

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */
#include "gpio.h"
#include "dcmotor.h"
#include "lm35_sensor.h"
#include "std_types.h"
#include "lcd.h"

typedef enum
{
	OFF,ON
}FANSTATE;

int main(void)
{
	FANSTATE FAN;
	uint8 Temp;
	LCD_init();

	ADC_init();
	DcMotor_Init();
	LCD_displayStringRowColumn(0,4,"Fan is: ");
	LCD_displayStringRowColumn(1,4,"Temp is: ");


	while(1)
	{
		Temp = LM35_getTemperature();
		if(FAN==ON)
		{
			LCD_displayStringRowColumn(0,13,"ON");

		}
		else {
			LCD_displayStringRowColumn(0,13,"OFF");
		}



		if(Temp<30){

			FAN=OFF;
			DcMotor_Rotate(STOP,0);
		}
		else if (Temp>=30 && Temp <60)
		{
			FAN=ON;
			DcMotor_Rotate(CLOCKWISE,25);
		}
		else if(Temp>=60 && Temp <90)
		{
			FAN=ON;
			DcMotor_Rotate(CLOCKWISE,50);


		}
		else if(Temp>=90 && Temp <120)
		{
			FAN=ON;
			DcMotor_Rotate(CLOCKWISE,75);

		}
		else if(Temp>=120)
		{
			FAN=ON;
			DcMotor_Rotate(CLOCKWISE,100);

		}

		LCD_moveCursor(1,13);
		if(Temp >= 100)
		{
			LCD_intgerToString(Temp);
		}
		else
		{
			LCD_intgerToString(Temp);
			LCD_displayCharacter(' '); // If temperature is less than 3 digits
		}
	}
}
