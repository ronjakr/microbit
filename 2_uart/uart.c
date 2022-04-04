#include "uart.h"
#include "gpio.h"

void uart_init(void){
    GPIO0->PIN_CNF[6] = 0;  // RX, input
    GPIO1->PIN_CNF[8] = 1;  // TX, output
    UART->PSEL_TXD = 8 | 1 << 5;
    UART->PSEL_RXD = 6;
    UART->BAUDRATE = 0x00275000;
    UART->PSEL_RTS = 1 << 31;
    UART->PSEL_CTS = 1 << 31;
    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;

    return;
}

void uart_send(char letter) {
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while(!(UART->EVENTS_TXDRDY)) {
        continue;     
    }
    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;

    return;
}

char uart_read(void) {
    UART->EVENTS_RXDRDY = 0;
    UART->TASKS_STARTRX = 1;
    if(UART->EVENTS_RXDRDY) {
        return UART->RXD;
    }

    return '\0';
}