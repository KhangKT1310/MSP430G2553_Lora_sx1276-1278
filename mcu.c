/*
 * File Name: mcu.c
 * Project: MSP430 Programing
 * File Created: 25-08-2022  10:53:56:PM
 * Author: <<KhangKT>>
 * AuthorEmail: khangkieutrong@gmail.com
 * Phone:0964991713
 */

#include <msp430g2553.h>
#include <stdint.h>
#include "mcu.h"

void mcu_init()
{
  WDTCTL = WDTPW + WDTHOLD; // Disable watchdog
  BCSCTL1 = CALBC1_16MHZ;   // Set range
  DCOCTL = CALDCO_16MHZ;    // Set DCO step + modulation

  P1OUT &= 0x00; // Shut down everything
  P1DIR &= 0x00;
}

void mcu_delayms(uint32_t ms)
{
  while (ms)
  {
    __delay_cycles(16 * 998);
    ms--;
  }
}

void mcu_delayus(uint32_t us)
{
  while (us)
  {
    __delay_cycles(14); // for 16MHz
    us--;
  }
}

void mcu_memcpy1(uint8_t *dst, const uint8_t *src, uint16_t size)
{
  while (size--)
    *dst++ = *src++;
}
