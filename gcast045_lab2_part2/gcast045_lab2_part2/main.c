/*
 * Partner: Jesse Garcia, jgarc269@ucr.edu 
 * Lab Section: 027
 * Assignment: Lab 2 Exercise 2
 * Exercise Description: Number of parking spaces available.
 * 
 * I acknowledge all content contained herein, excluding template or example code, is my own original work. 
 */ 

#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	
	DDRA = 0x00; PORTA = 0xFF; //Input
	DDRC = 0xFF; PORTC = 0x00; //Output Parking space sensor
	
	unsigned char space0 = 0x00;
	unsigned char space1 = 0x00;
	unsigned char space2 = 0x00;
	unsigned char space3 = 0x00;
	
	unsigned char cntavail = 0x00;
	
    while (1) 
    {
		space0 = PINA & 0x01;
		space1 = PINA & 0x02;
		space2 = PINA & 0x04;
		space3 = PINA & 0x08;	
		
		cntavail = space0 + (space1 >> 1) + (space2 >> 2) + (space3 >> 3);	//Shift every space to the bit 0x01. 1 + 1 + 1 + 1 = 4
		
		PORTC = 0x04 - cntavail;												//Start with 4 spaces available and subtract spaces taken.
    }
}

