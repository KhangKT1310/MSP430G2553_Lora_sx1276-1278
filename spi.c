
/*
 * File Name: spi.c
 * Project: MSP430 Programing
 * File Created: 25-08-2022  10:53:56:PM
 * Author: <<KhangKT>>
 * AuthorEmail: khangkieutrong@gmail.com
 * Phone:0964991713
 */

#include <msp430g2553.h>
#include <stdint.h>
#include "Include/spi.h"

volatile uint8_t spi_buf = 0;

#define SCLK BIT5
#define MISO BIT6
#define MOSI BIT7
#define CS BIT2

void spi_init()
{
  UCB0CTL1 = UCSWRST;
  UCB0CTL0 = UCSYNC + UCSPB + UCMSB + UCCKPH; // UCMSB + UCMST + UCSYNC; // 3-pin, 8-bit SPI master,2 bit stop
  UCB0CTL1 |= UCSSEL_2;                       // SMCLK
  UCB0BR0 = 0x02;                             // Frequency CPU / 2 (16Mhz / 2 = 8 Mhz SPI)
  UCB0BR1 = 0;

  P1SEL |= SCLK | MISO | MOSI; // P1.6 is MISO and P1.7 is MOSI
  P1SEL2 |= SCLK | MISO | MOSI;

  P1DIR |= SCLK | MOSI;
  P1DIR &= ~MISO;

  P2DIR |= CS; // | CS2;                           // P2.2 CS (chip select)
  P2OUT |= CS; // | CS2;

  UCB0CTL1 &= ~UCSWRST; // Initialize USCI state machine
}

void spi_txready()
{
  while (!(IFG2 & UCB0TXIFG))
    ; // TX buffer ready?
}

void spi_rxready()
{
  while (!(IFG2 & UCB0RXIFG))
    ; // RX Received?
}

void spi_send(uint8_t data)
{
  spi_txready();
  UCB0TXBUF = data; // Send data over SPI to Slave
}

void spi_recv()
{
  spi_rxready();
  spi_buf = UCB0RXBUF; // Store received data
}

void spi_transfer(uint8_t data)
{
  spi_send(data);
  spi_recv();
}

void spi_chipEnable()
{
  P2OUT &= ~CS;
}

void spi_chipDisable()
{
  P2OUT |= CS;
}
