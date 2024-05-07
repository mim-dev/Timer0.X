/*
 * File:   main.c
 * Author: luther stanton
 *
 */

#include "system.h"
#include "timer.h"
#include "gpio.h"

void main(void) {
    
    initializeSystem();
    
    configureGPIO();
    configureTimer0();
    
    startTimer0();
    
    int currentT0OutputState = 0;
    
    while(1) {
        
        if(currentT0OutputState != T0CON0bits.T0OUT)
        {
            LATA ^= 0xF0;
            currentT0OutputState ^= 1;
        }
    }
    
    return;
}
