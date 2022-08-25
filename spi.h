/*
 * File Name: spi.h
 * Project: MSP430 Programing
 * File Created: 25-08-2022  10:53:56:PM
 * Author: <<KhangKT>>
 * AuthorEmail: khangkieutrong@gmail.com
 * Phone:0964991713
 */

#include <stdint.h>

#ifndef SPI_H
#define SPI_H

extern volatile uint8_t spi_buf;

void spi_init();
void spi_txready();
void spi_rxready();
void spi_send(uint8_t data);
void spi_recv();
void spi_transfer(uint8_t data);
void spi_chipEnable();
void spi_chipDisable();

#endif
