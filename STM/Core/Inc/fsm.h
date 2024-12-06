/*
 * fsm.h
 *
 *  Created on: Dec 6, 2024
 *      Author: THUAN
 */

#ifndef INC_UART_FSM_H_
#define INC_UART_FSM_H_

#include "main.h"

#define MAX_BUFFER_SIZE			30



void uart_fsm_init(void);

void command_parser_fsm(void);
void uart_communication_fsm(void);

extern uint8_t buffer_flag;
extern uint8_t isSendADC_flag, isReadADC_flag;

extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t previous_index_buffer;
extern uint8_t index_buffer;
extern uint32_t ADC_VALUE;
#endif /* INC_UART_FSM_H_ */
