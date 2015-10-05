/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */



void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */
    PORTA = 0;
    PORTC = 0;
    LATA = 0;
    LATC = 0;
    
    ANSELA = 0;    // Digital I/0
    ANSELC = 0;    // Digital I/0
    
    RELAY_TRIS = 0; //Output
    DOOR_TRIS  = 1; //Input
    PIR_TRIS   = 1; //Input
    
    /* Setup analog functionality and port direction */

    /* Initialize peripherals */
    WPUA = 0;     // WEAK PULL-UP disable for PORTA
    WPUC = 0;     // WEAK PULL-UP disable for PORTC
    DOOR_WPU = 1; // WEAK PULL-UP enable FOR DOOR
    //PIR_WPU = 1;  // WEAK PULL-UP enable FOR PIR
    OPTION_REGbits.nWPUEN=0;  // GLOBAL ENABLE WEAK PULL-UP

    /* Enable interrupts */
    
    PIR;
    IOCAPbits.IOCAP2  = 1;  //enable a pin to detect a rising edge
    IOCANbits.IOCAN2  = 1;  //enable a pin to detect a falling edge
    IOCAFbits.IOCAF = 0;    //INTERRUPT ON CHANGE FLAG CLEAR
    INTCONbits.IOCIE = 1;   //INTERRUPT ON CHANGE ENABLE
    INTCONbits.GIE = 1;     //GLOBAL INTERRUPT ENABLE
    
}

