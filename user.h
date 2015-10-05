/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/

/* TODO Application specific user parameters used in user.c may go here */

/******************************************************************************/
/* User Function Prototypes                                                   */
/******************************************************************************/

/* TODO User level functions prototypes (i.e. InitApp) go here */

#define RELAY       LATAbits.LATA5
#define RELAY_TRIS  TRISAbits.TRISA5
#define DOOR        PORTCbits.RC0
#define DOOR_WPU    WPUCbits.WPUC0
#define DOOR_TRIS   TRISCbits.TRISC0
#define PIR         PORTAbits.RA2
#define PIR_WPU     WPUAbits.WPUA2
#define PIR_TRIS    TRISAbits.TRISA2
#define PIR_INTERRUPT_FLAG IOCAFbits.IOCAF2

#define DOOR_OPENED 1
#define RELAY_ON    1
#define PIR_ACTIVE  1

#define LOOP_TIME     16   //seconds
#define MAX_RELAY_ON  80   //60*60    // seconds, 1 hour
#define MAX_RELAY_ON_LOOP       MAX_RELAY_ON/LOOP_TIME 


void InitApp(void);         /* I/O and Peripheral Initialization */


