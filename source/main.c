/*	Author: kmo004
 *  Partner(s) Name: Moker(Ke) Bellomo
 *	Lab Section:
 *	Assignment: Lab # 4 Exercise #3
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
enum States {START,INIT,S1,S2,S3,OPEN} state;

int main(void) {

	DDRA= 0xFF; PORTA = 0x00;
	DDRB= 0x00; PORTB = 0xFF;
	
	
	while (1) {
		tick();
	}
	
	return 1;
}

void tick(){
	
	switch(state) {
		case START:
		state = INIT;
		break;
		
		case INIT:
		if(PINA == 1){
			state= S1;
		}
		else{
			state= INIT;
		}
		break;
		
		case S1:
		if(PINA == 0){
			state = S2;
		}
		else if(PINA == 1){
			state= S1;
		}
		else{
			state= INIT;
		}
		break;
		
		case S2:
		if (PINA == 0){
			state = S2;
		}
		else if(PINA == 2){
			state = S3;
		}
		else {
			state= INIT;
		}
		break;
		
		case S3:
		if (PINA == 0){
			state = OPEN;
		}
		else if (PINA == 2){
			state = S3;
		}
		else{
			state = INIT;
		}
		break;
		
		case OPEN:
		if (PINA == 0x80){
			state = INIT;
		}
		else{
			state = OPEN;
		}
		break;
	}
	
	switch(state) {
		case START:
		break;
		
		case INIT:
		PORTB = 0x00;
		break;
		
		case S1:
		break;
		
		case S2:
		break;
		
		case S3:
		break;
		
		case OPEN:
		PORTB = 0x01;
		break;
		
	}
}
