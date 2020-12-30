/*
    util.c - source file for LL driver wrappers
*/

#include "util.h"

#define ONE_MS (72724*2/91) // 1msec, tuned at 80 MHz

/*
    Wait n milliseconds
*/
void
delayms (uint32_t n)
{
    uint32_t volatile time;
    while(n--){
        time = ONE_MS;
        while(time--);
    }
}

/*
    LL wrappers for accessing STM32L4xx pins
*/
inline void
writepin(GPIO_TypeDef * port, uint32_t pin, uint32_t value)
{
    if (value) {
        port->BSRR |= pin;
    } else {
        port->BRR |= pin;
    }
}

inline uint32_t
readpin(GPIO_TypeDef * port, uint32_t pin)
{
    return (((port->IDR) & pin) == pin);
}
