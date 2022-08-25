/*
 * File Name: uart.h
 * Project: MSP430 Programing
 * File Created: 25-08-2022  10:53:56:PM
 * Author: <<KhangKT>>
 * AuthorEmail: khangkieutrong@gmail.com
 * Phone:0964991713
 */

#include <stdint.h>

#ifndef UART_H
#define UART_H

void uart_init();
void uart_read(char str[]);
void uart_write(char str[]);
void uart_writen(char *str, int n);
void uart_writec(char data);
void uart_printhex8(uint8_t n);
void uart_printhex32(uint32_t n);

#endif
