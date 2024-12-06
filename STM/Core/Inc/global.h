/*
 * global.h
 *
 *  Created on: Dec 6, 2024
 *      Author: THUAN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "fsm.h"
#include <stdio.h>

#define MAX_BUFFER_SIZE				30

#define CDM_INT						0
#define RECEIVED_EXCLAMATION_MARK	1
#define RECEIVED_R					2
#define RECEIVED_S					3
#define RECEIVED_T					4
#define RECEIVED_O					5
#define RECEIVED_K					6

#define UART_INIT					10
#define COMMU_ADC					11

extern int command_state;
extern int communication_state;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t current_index_buffer;
extern uint8_t next_index_buffer;
extern uint8_t buffer_flag;
extern uint8_t command_flag;
extern uint8_t command_data;
extern uint8_t isSendADC_flag;
extern uint8_t isReadADC_flag;

extern uint32_t ADC_VALUE;

#endif /* INC_GLOBAL_H_ */
