/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
#include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
#include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */
#include "user.h"
#include "system.h"   

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

/* Baseline devices don't have interrupts. Note that some PIC16's 
 * are baseline devices.  Unfortunately the baseline detection macro is 
 * _PIC12 */
#ifndef _PIC12

void interrupt isr(void) {
    /* This code stub shows general interrupt handling.  Note that these
    conditional statements are not handled within 3 seperate if blocks.
    Do not use a seperate if block for each interrupt flag to avoid run
    time errors. */

#if 1

    /* TODO Add interrupt routine code here. */
    /* Determine which flag generated the interrupt */
    if (PIR_INTERRUPT_FLAG) {
        bool TDOOR = DOOR;
        __delay_ms(10);
        TDOOR = TDOOR && DOOR;
        if (TDOOR == DOOR_OPENED) {
            RELAY = (PIR == PIR_ACTIVE) ? RELAY_ON : !RELAY_ON;
        }
        PIR_INTERRUPT_FLAG = 0; /* Clear Interrupt Flag  */
    }

#endif

}
#endif


