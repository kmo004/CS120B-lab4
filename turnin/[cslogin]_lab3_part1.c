/*	Author: kmo004
 *  Partner(s) Name: Moker(Ke) Bellomo
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 #include <avr/io.h>
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	unsigned char numTotal = 0x00;
	
while(1){
	
	if(PINA & 0x01){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x02){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x04){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x08){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x10){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x20){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x40){
		numTotal = numTotal + 0x01;
	}
	if(PINA & 0x80){
		numTotal = numTotal + 0x01;
	}
	
	if(PINB & 0x01){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x02){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x04){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x08){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x10){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x20){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x40){
		numTotal = numTotal + 0x01;
	}
	if(PINB & 0x80){
		numTotal = numTotal + 0x01;
	}
	
	PORTC = numTotal;
	numTotal = 0;
}
	
	return 1;
}
