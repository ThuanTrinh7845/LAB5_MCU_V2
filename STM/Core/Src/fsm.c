/*
 * fsm.c
 *
 *  Created on: Dec 6, 2024
 *      Author: THUAN
 */

#include "fsm.h"


void command_parser_fsm(void){
	switch(command_state){
		case CDM_INT:
			command_flag = command_data = 0;
			if(buffer[current_index_buffer] == '!')
				command_state = RECEIVED_EXCLAMATION_MARK;

			break;
		case RECEIVED_EXCLAMATION_MARK:
			if(buffer[current_index_buffer] == 'R')
				command_state = RECEIVED_R;
			else if(buffer[current_index_buffer] == 'O')
				command_state = RECEIVED_O;
			else command_state = CDM_INT;

			break;
		case RECEIVED_R:
			if(buffer[current_index_buffer] == 'S')
				command_state = RECEIVED_S;
			else command_state = CDM_INT;

			break;
		case RECEIVED_S:
			if(buffer[current_index_buffer] == 'T')
				command_state = RECEIVED_T;
			else command_state = CDM_INT;

			break;
		case RECEIVED_T:
			if(buffer[current_index_buffer] == '#'){
				command_flag = 1;
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}
			command_state = CDM_INT;

			break;
		case RECEIVED_O:
			if(buffer[current_index_buffer] == 'K')
				command_state = RECEIVED_K;
			else command_state = CDM_INT;

			break;
		case RECEIVED_K:
			if(buffer[current_index_buffer] == '#'){
				command_data = 1;
				HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
			}

			command_state = CDM_INT;

			break;
		default:
			break;
	}
}


void uart_communication_fsm(void){

	switch(communication_state){
		case UART_INIT:
			isSendADC_flag = isReadADC_flag = 0;
			if(command_flag == 1) {
				isReadADC_flag = 1;
				communication_state = COMMU_ADC;
			}
			break;
		case COMMU_ADC:
			isSendADC_flag = 1;
			if(command_data == 1) communication_state = UART_INIT;
			break;
		default:
			break;
	}
}
