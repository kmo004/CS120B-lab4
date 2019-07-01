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
 enum States{start,begin,on,off,wait1} state;
 void tick();
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif

int main(void){
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x01;
	state = start;
	
	while(1){
		tick();
	}	
	return 1;
}

void tick(){
	switch(state){
		case start:
		PORTB = 0x01;
		state = begin;
			
		break;
		
		case begin:
		if((~PINA & 0x01) == 0x01){
			state = off;
			break;
		}
		else{
			state = begin;
			break;
		}
		
		case off:
		if((~PINA & 0x01) == 0x01){
			state = wait1;
			break;
		}
		else{
			state = off;
			break;
		}
		case on:
		if((~PINA & 0x01) == 0x00){
			state = wait1;
			break;
		}
		else{
			state = on;
			break;
		}
		
		case wait1:
		if((~PINA & 0x01) == 0x01){
			state = on;
			break;
		}
		else{
			state = wait1;
			break;
		}
		
		default:
		break;
	}
	switch(state){
		case start:
		break;
		
		case begin:
		PORTB = 0x01;
		break;
		
		case on:
		PORTB = 0x01;
		break;
		
		case off:
		PORTB = 0x02;
		break;
		
		case wait1:
		break;
		
		default:
		break;
	}
}
