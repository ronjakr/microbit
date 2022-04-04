#include "uart.h"
#include "gpio.h"

int main(){
	int sleep = 0;
	while(1){
        // sends A if button A is pressed
        if(!(GPIO0->IN & (1 << 23))) {  // button active low
            uart_send('A');
        }
        
        // sends B if button B in pressed 
        else if (!(GPIO0->IN & (1 << 14))) {    // button active low
            uart_send('B');
        }


		sleep = 10000;
		while(--sleep);
	}
	return 0;
}