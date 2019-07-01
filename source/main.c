/*	Author: kmo004
 *  Partner(s) Name: Moker(Ke) Bellomo
 *	Lab Section:
 *	Assignment: Lab # 4 Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 #include <avr/io.h>
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif

enum states {START, INIT, PLUS, MINUS, RESET} state;

int main(void){
	
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x07;
	state = START;
	
	while(1){
		tick();
	}
	return 1;
}



void tick(){
	switch(state){
		case START:
		state = INIT;
		break;
		
		case INIT:
		if(PINA == 0){
			state = RESET;
		}
		else if (PINA == 1){
			state = PLUS;
		}
		else if (PINA == 2){
			state = MINUS;
		}
		else{
			state = INIT;
		}
		break;
		
		case PLUS:
		state = INIT;
		break;
		
		case MINUS:
		state = INIT;
		break;
		
		case RESET:
		state = INIT;
		break;
	}
	switch(state){
		case START:
		break;
		
		case INIT:
		break;
		
		case PLUS:
		if(PORTC < 9){
			PORTC = PORTC + 1;
		}
		break;
		
		case MINUS:
		if(PORTC > 0){
			PORTC = PORTC - 1;
		}
		break;
		
		case: RESET:
			PORTC = 0x00;
		break;
	}
}

