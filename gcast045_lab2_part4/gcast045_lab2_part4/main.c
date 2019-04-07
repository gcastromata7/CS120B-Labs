/*
 * Partner: Jesse Garcia, jgarc269@ucr.edu 
 * Lab Section: 027
 * Assignment: Lab 2 Exercise 4
 * Exercise Description: Amusement park ride.
 * 
 * I acknowledge all content contained herein, excluding template or example code, is my own original work. 
 */ 
#include <avr/io.h>
#include <stdio.h>
int main(void)
{
	//Inputs
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	
	//Output
	DDRD = 0xFF; PORTD = 0x00;
	
	
	unsigned char totalWeight = 0x00;
	unsigned char unbalancedWeight = 0x00;
	
    while (1) 
    {

		totalWeight = (PINA + PINB + PINC) > 140 ? 0x01: 0x00;		//Checks if the total weight exceeds 140kg.
		unbalancedWeight = (PINA - PINC) > 80 ? 0x02: 0x00;			//Checks if the difference between PINA and PINC exceed 80kg.
		
		
		PORTD = (totalWeight + unbalancedWeight);						//Sets the bits on PORTD to indicate whether the weight exceeds 140kg or 80kg, or both.
		
		printf("Average weight: %d", (PINA + PINB + PINC) >> 2);		//Shifting right by 2 to get the average. 
    }
}

