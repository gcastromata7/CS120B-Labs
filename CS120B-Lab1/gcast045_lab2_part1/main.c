/*
 * Partner: Jesse Garcia, jgarc269@ucr.edu 
 * Lab Section: 027
 * Assignment: Lab 2 Exercise 1
 * Exercise Description: Garage door sensor
 * 
 * I acknowledge all content contained herein, excluding template or example code, is my own original work. 
 */ 

#include <avr/io.h>


int main(void)
{
    DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs 
    DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s - LED
	
	unsigned char garageDoor = 0x00;
	unsigned char lightSensor = 0x00;
    while(1)
    {
	    garageDoor = PINA & 0x01;
		lightSensor = PINA & 0x02;
		
		if((garageDoor == 0) && (lightSensor == 0))
		{
			PORTB = 0;
		}
		else if((garageDoor == 1) && (lightSensor == 0))
		{
			PORTB = 1;
		}
		else if((garageDoor == 0) && (lightSensor == 1))
		{
			PORTB  = 0;
		}
		else
		{
			PORTB = 0;
		}
		
    }
}

