#include "uart.h"
#include "gpio.h"

void uart_init(void){
    GPIO0->PIN_CNF[6] = 0;
    GPIO1->PIN_CNF[8] = 1;
    UART->PSEL_TXD = 0x06;
    UART->PSEL_RXD = 0;

    return;
}