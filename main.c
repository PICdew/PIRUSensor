/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

int32_t loops;

/******************************************************************************/
/* Main Program                                                               */

/******************************************************************************/
void main(void) {
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    //unsigned long seconds=0;

    RELAY = RELAY_ON;
    loops = 0;

    while (1) {
        CLRWDT();
        SLEEP();
        NOP();
        // safety check max time
        if (RELAY == RELAY_ON) {
            if (++loops >= MAX_RELAY_ON_LOOP) {
                RELAY=!RELAY_ON;
            }
        } else {
            loops = 0;
        }
    }

}

