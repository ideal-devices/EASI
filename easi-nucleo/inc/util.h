/*
    util.h - header file for LL driver wrappers
*/

#ifndef UTIL_H
#define UTIL_H

#include "stm32l4xx_ll_gpio.h"

/*
    Wait n milliseconds
*/
void delayms(uint32_t n);

/*
    LL wrappers for accessing STM32L4xx pins
*/
void writepin(GPIO_TypeDef * port, uint32_t pin, uint32_t value);

uint32_t readpin(GPIO_TypeDef * port, uint32_t pin);

#endif
