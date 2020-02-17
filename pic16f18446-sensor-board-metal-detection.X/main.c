/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.79.0
        Device            :  PIC16F18446
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "graphics.h"
#include "plot.h"
#include "ili9163c.h"
#include "metal_detector.h"
#include "gui.h"
#include "color.h"
#include "font.h"

/*
                         Main application
 */
#define MAX_SUPPORTED_MODE              (1)


volatile int8_t mode = 0;

volatile uint8_t s2Pressed = 0;
volatile uint8_t s3Pressed = 0;

extern const FONT font8x12;


void onModeChanged(void)
{
    GFX_ClearScreen(0x0000);
  
    
    if ( (mode != 1) ) // if not metal detector buzzer
    {
        metalDetectorBuzzerDisable();
    }
    
    

    
    switch(mode)
    {
        
            
		case 0:
            // metal detector
		
            if(peakFreq==0) {
                initMetalDetect();
            }
            metalDetectorDrawPFreq();
            
            
            initMetalDetectorPlots();
            break;
                    
        
        case 1: 
            // metal detector buzz
         
			if(peakFreq==0) {
                initMetalDetect();
            }
            
            metalDetectorBuzzScreenStatic();          
            metalDetectorBuzzerEnable();          
            break;      

        default:
            break;
    }

}




void onS2Action(void)
{
    if (S2_GetValue() == 0)
    {
        s2Pressed = 1;
    }
}

void onS3Action(void)
{
    if (S3_GetValue() == 0)
    {
        s3Pressed = 1;
    }
}



void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    metalDetectorBuzzerDisable();

    IOCBF5_SetInterruptHandler(onS2Action);
    IOCCF4_SetInterruptHandler(onS3Action);

    GFX_Initialize();
    GFX_SetFont(&font8x12);

    GFX_ClearScreen(0x0000);

    LCD_BACKLIGHT_SetHigh();

    onModeChanged();
    
    

    while (1) {
    
        if (s2Pressed)
        {
            mode--;
            if (mode < 0)
            {
                mode = MAX_SUPPORTED_MODE;
            }
            onModeChanged();
            s2Pressed = 0;
        }

        if (s3Pressed)
        {
            mode++;
            if (mode > MAX_SUPPORTED_MODE)
            {
                mode = 0;
            }
            onModeChanged();
            s3Pressed = 0;
        }
            
            
        switch (mode)
        {

            case 0:
                // read metal detector and draw
                metalDetectorScreenTasks();
                break;

            case 1:
                // read metal detector sensor and draw
                // "metal detector buzz" text on small LCD,
                // gauge on big LCD
                // + buzzer: variable interval beep
                metalDetectorBuzz();
                break;

            default:
                break;
        }
        
        
    }
}

/**
 End of File
*/