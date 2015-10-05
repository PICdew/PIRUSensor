/******************************************************************************/
/*Files to Include                                                            */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#endif

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#include "system.h"

/* Refer to the device datasheet for information about available
oscillator configurations. */
void ConfigureOscillator(void)
{
    /* TODO Add clock switching code if appropriate.  */

    /* Typical actions in this function are to tweak the oscillator tuning
    register, select new clock sources, and to wait until new clock sources
    are stable before resuming execution of the main project. */
    
    OSCCONbits.SCS=0b00;  // The System Clock Select by bits in the Configuration Word 1.
    OSCCONbits.IRCF=0b0111; // 500 kHz (Default after Reset)
    
    //WDTCONbits.WDTPS=  0b01100;  //Watchdog Timer Period Select bits 1:131072 (2^17) (Interval 4s typ)
    //WDTCONbits.WDTPS=  0b01010;  //Watchdog Timer Period Select bits 1:32768 (Interval 1s typ)
    WDTCONbits.WDTPS=  0b01110;    //Watchdog Timer Period Select bits 1:524288 (Interval 16s typ)
    
   
}
