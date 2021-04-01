/*!**********************************************************************************************************************
@file main.c                                                                
@brief Main system file for the ENCM 369 firmware.  
***********************************************************************************************************************/

#include "configuration.h"


/***********************************************************************************************************************
Global variable definitions with scope across entire project.
All Global variable names shall start with "G_"
***********************************************************************************************************************/
/* New variables */
volatile u32 G_u32SystemTime1ms = 0;     
volatile u32 G_u32SystemTime1s  = 0;     
volatile u32 G_u32SystemFlags   = 0;     

/*--------------------------------------------------------------------------------------------------------------------*/
/* External global variables defined in other files (must indicate which file they are defined in) */


/***********************************************************************************************************************
Global variable definitions with scope limited to this local application.
Variable names shall start with "Main_" and be declared as static.
***********************************************************************************************************************/


/*!**********************************************************************************************************************
@fn void main(void)
@brief Main program where all tasks are initialized and executed.


***********************************************************************************************************************/

void main(void)
{
  G_u32SystemFlags |= _SYSTEM_INITIALIZING;

  ClockSetup();
  SysTickSetup();
  GpioSetup();
  
  UserAppInitialize();

  while(1)
  {
    UserAppRun();
#if 1
    HEARTBEAT_OFF();
    SystemSleep();
    
    TimeXus(11); 
    while ( PIR3bits.TMR0IF == 0);  
    HEARTBEAT_ON();
#endif
  } 
  
} /* end main() */




/*--------------------------------------------------------------------------------------------------------------------*/
/* End of File */
/*--------------------------------------------------------------------------------------------------------------------*/
