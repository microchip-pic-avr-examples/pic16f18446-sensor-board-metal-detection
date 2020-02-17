/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC16F18446
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.10 and above
        MPLAB 	          :  MPLAB X 5.30	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set BUZZ_P aliases
#define BUZZ_P_TRIS                 TRISAbits.TRISA1
#define BUZZ_P_LAT                  LATAbits.LATA1
#define BUZZ_P_PORT                 PORTAbits.RA1
#define BUZZ_P_WPU                  WPUAbits.WPUA1
#define BUZZ_P_OD                   ODCONAbits.ODCA1
#define BUZZ_P_ANS                  ANSELAbits.ANSA1
#define BUZZ_P_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BUZZ_P_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BUZZ_P_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BUZZ_P_GetValue()           PORTAbits.RA1
#define BUZZ_P_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BUZZ_P_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BUZZ_P_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define BUZZ_P_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define BUZZ_P_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define BUZZ_P_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define BUZZ_P_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define BUZZ_P_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set BUZZ_N aliases
#define BUZZ_N_TRIS                 TRISAbits.TRISA2
#define BUZZ_N_LAT                  LATAbits.LATA2
#define BUZZ_N_PORT                 PORTAbits.RA2
#define BUZZ_N_WPU                  WPUAbits.WPUA2
#define BUZZ_N_OD                   ODCONAbits.ODCA2
#define BUZZ_N_ANS                  ANSELAbits.ANSA2
#define BUZZ_N_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define BUZZ_N_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define BUZZ_N_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define BUZZ_N_GetValue()           PORTAbits.RA2
#define BUZZ_N_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define BUZZ_N_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define BUZZ_N_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define BUZZ_N_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define BUZZ_N_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define BUZZ_N_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define BUZZ_N_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define BUZZ_N_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()              PORTBbits.RB4
#define RB4_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()             do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()           do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode()         do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()        do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set S2 aliases
#define S2_TRIS                 TRISBbits.TRISB5
#define S2_LAT                  LATBbits.LATB5
#define S2_PORT                 PORTBbits.RB5
#define S2_WPU                  WPUBbits.WPUB5
#define S2_OD                   ODCONBbits.ODCB5
#define S2_ANS                  ANSELBbits.ANSB5
#define S2_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define S2_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define S2_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define S2_GetValue()           PORTBbits.RB5
#define S2_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define S2_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define S2_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define S2_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define S2_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define S2_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define S2_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define S2_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set LCD_RESET aliases
#define LCD_RESET_TRIS                 TRISBbits.TRISB7
#define LCD_RESET_LAT                  LATBbits.LATB7
#define LCD_RESET_PORT                 PORTBbits.RB7
#define LCD_RESET_WPU                  WPUBbits.WPUB7
#define LCD_RESET_OD                   ODCONBbits.ODCB7
#define LCD_RESET_ANS                  ANSELBbits.ANSB7
#define LCD_RESET_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define LCD_RESET_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define LCD_RESET_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define LCD_RESET_GetValue()           PORTBbits.RB7
#define LCD_RESET_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define LCD_RESET_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define LCD_RESET_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define LCD_RESET_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define LCD_RESET_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define LCD_RESET_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define LCD_RESET_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define LCD_RESET_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set channel_MetalDetector aliases
#define channel_MetalDetector_TRIS                 TRISCbits.TRISC0
#define channel_MetalDetector_LAT                  LATCbits.LATC0
#define channel_MetalDetector_PORT                 PORTCbits.RC0
#define channel_MetalDetector_WPU                  WPUCbits.WPUC0
#define channel_MetalDetector_OD                   ODCONCbits.ODCC0
#define channel_MetalDetector_ANS                  ANSELCbits.ANSC0
#define channel_MetalDetector_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define channel_MetalDetector_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define channel_MetalDetector_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define channel_MetalDetector_GetValue()           PORTCbits.RC0
#define channel_MetalDetector_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define channel_MetalDetector_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define channel_MetalDetector_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define channel_MetalDetector_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define channel_MetalDetector_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define channel_MetalDetector_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define channel_MetalDetector_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define channel_MetalDetector_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 procedures
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()              PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()             do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()           do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetAnalogMode()         do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()        do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set LCD_BACKLIGHT aliases
#define LCD_BACKLIGHT_TRIS                 TRISCbits.TRISC2
#define LCD_BACKLIGHT_LAT                  LATCbits.LATC2
#define LCD_BACKLIGHT_PORT                 PORTCbits.RC2
#define LCD_BACKLIGHT_WPU                  WPUCbits.WPUC2
#define LCD_BACKLIGHT_OD                   ODCONCbits.ODCC2
#define LCD_BACKLIGHT_ANS                  ANSELCbits.ANSC2
#define LCD_BACKLIGHT_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LCD_BACKLIGHT_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LCD_BACKLIGHT_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LCD_BACKLIGHT_GetValue()           PORTCbits.RC2
#define LCD_BACKLIGHT_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LCD_BACKLIGHT_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LCD_BACKLIGHT_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LCD_BACKLIGHT_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LCD_BACKLIGHT_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LCD_BACKLIGHT_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LCD_BACKLIGHT_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LCD_BACKLIGHT_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set S3 aliases
#define S3_TRIS                 TRISCbits.TRISC4
#define S3_LAT                  LATCbits.LATC4
#define S3_PORT                 PORTCbits.RC4
#define S3_WPU                  WPUCbits.WPUC4
#define S3_OD                   ODCONCbits.ODCC4
#define S3_ANS                  ANSELCbits.ANSC4
#define S3_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define S3_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define S3_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define S3_GetValue()           PORTCbits.RC4
#define S3_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define S3_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define S3_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define S3_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define S3_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define S3_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define S3_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define S3_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set LCD_CS aliases
#define LCD_CS_TRIS                 TRISCbits.TRISC7
#define LCD_CS_LAT                  LATCbits.LATC7
#define LCD_CS_PORT                 PORTCbits.RC7
#define LCD_CS_WPU                  WPUCbits.WPUC7
#define LCD_CS_OD                   ODCONCbits.ODCC7
#define LCD_CS_ANS                  ANSELCbits.ANSC7
#define LCD_CS_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define LCD_CS_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define LCD_CS_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define LCD_CS_GetValue()           PORTCbits.RC7
#define LCD_CS_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define LCD_CS_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define LCD_CS_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define LCD_CS_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define LCD_CS_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define LCD_CS_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define LCD_CS_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define LCD_CS_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF5 pin functionality
 * @Example
    IOCBF5_ISR();
 */
void IOCBF5_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF5 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF5 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF5_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF5 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_InterruptHandler);

*/
extern void (*IOCBF5_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF5 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF5_SetInterruptHandler() method.
    This handler is called every time the IOCBF5 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF5_SetInterruptHandler(IOCBF5_DefaultInterruptHandler);

*/
void IOCBF5_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF4 pin functionality
 * @Example
    IOCCF4_ISR();
 */
void IOCCF4_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF4 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF4 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF4_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF4 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_InterruptHandler);

*/
extern void (*IOCCF4_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF4 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF4_SetInterruptHandler() method.
    This handler is called every time the IOCCF4 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF4_SetInterruptHandler(IOCCF4_DefaultInterruptHandler);

*/
void IOCCF4_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/