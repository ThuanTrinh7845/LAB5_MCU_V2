/*
 * global.c
 *
 *  Created on: Dec 6, 2024
 *      Author: THUAN
 */

#include "global.h"

int command_state = CDM_INT;
int communication_state = UART_INIT;

uint8_t buffer[MAX_BUFFER_SIZE];
uint8_t current_index_buffer = 0;
uint8_t next_index_buffer = 0;
uint8_t buffer_flag = 0, command_flag = 0, command_data = 0;
uint8_t isSendADC_flag = 0, isReadADC_flag = 0;

uint32_t ADC_VALUE = 0;
