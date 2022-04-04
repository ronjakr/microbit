#include "uart.h"
#include "gpio.h"
#include <stdio.h>

size_t _write(int fd, const void *buf, size_t count) {
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++) {
        uart_send(*letter);
        letter++;
    }

    return count;
}

int main(){

    gpio_init();
    uart_init();
	int sleep = 0;
	while(1){
        // sending letters from micro:bit to computer
        // sends A if button A is pressed
        if(!(GPIO0->IN & (1 << 14))) {  // button active low
            uart_send('A');
        }
        
        // sends B if button B in pressed 
        else if (!(GPIO0->IN & (1 << 23))) {    // button active low
            uart_send('B');
        }

        // listening for letters sent from computer to micro:bit
        if(uart_read() != '\0') {
            // turning lights off if a led (pin 21) is on
            if(GPIO0->IN & (1 << 21)) {
                gpio_lights_off();
            }

            // turning lights on if a led (pin 21) is off
            else {
                gpio_lights_on();
            }
        }

        iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235, 2019, 2018, 'C');


		sleep = 10000;
		while(--sleep);
	}
	return 0;
}