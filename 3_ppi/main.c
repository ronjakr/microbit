#include "gpio.h"
#include "ppi.h"
#include "gpiote.h"

int main(){
    
    /*GPIO0->OUT = (1 << 28);
    GPIO0->OUT = (1 << 11);
    GPIO0->OUT = (1 << 31);
    GPIO1->OUT = (1 << 5);
    GPIO0->OUT = (1 << 30);*/

    GPIO0->PIN_CNF[28] = 1;
    GPIO0->PIN_CNF[11] = 1;
    GPIO0->PIN_CNF[31] = 1;
    GPIO1->PIN_CNF[5] = 1;
    GPIO0->PIN_CNF[30] = 1;

    gpioteInit();
    init_PPI();

    

    while(1){
 
    }


    return 0;
}