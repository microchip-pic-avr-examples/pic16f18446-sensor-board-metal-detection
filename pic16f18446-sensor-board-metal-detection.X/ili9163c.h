/**
   ili9163c TFT Display Driver File
   Created on December 8, 2016, 3:02 PM  
 
   @Company
     Microchip Technology Inc.

   @Author
     C16490

   @File Name
     ili9163c.h

   @Summary
     This is the driver implementation file for the TFT Display

   @Description
     This header file provides implementations for driver APIs for 
     the 1.8" TFT display.

 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef ILI9163C_H
#define	ILI9163C_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef	__cplusplus
extern "C" {
#endif

// Port D setup as data bus
#define DATABUS_PORTD PORTD
#define DATABUS_TRISD TRISD
#define DATABUS_LATD  LATD
    
// maybe these should go into a display configuration file that gets included
#define DISPLAY_WIDTH       128     // actual display size X
#define DISPLAY_HEIGHT      160     // actual display size Y
#define ORGIN               0       // orgin of display X and Y
#define MAX_WIDTH           127     // 1 less for loops and arrays
#define MAX_HEIGHT          159     // 1 less for loops and arrays

    
void lcdBacklight(uint8_t intensity);


/*
 * Initialize the ili9163c chip connected to the 1.8 inch TFT display
 */
void LCD_Initialize(void);

/* 
 * Write the data for the previous command
 */
void LCD_WriteCmdData(uint8_t cmdData);

/* 
 * Write the command to the display 
 */
void LCD_WriteCmd(uint8_t command);

/* 
 * Write display data as 2 bytes 
 */
void LCD_WriteData(uint8_t dataHighByte, uint8_t dataLowByte);

/* 
 * Write display data as a 16-bit word 
 */
void LCD_WriteData16bits(uint16_t data);

/* 
 * Set the position on the LCD where the next data will be written 
 */
void LCD_SetPosition(uint8_t x0, uint8_t x1, uint16_t y0, uint16_t y1);

/* 
 * Clear the LCD screen to a predefined color 
 */
void LCD_ClearScreen(uint16_t bColor);

/*
 
 */
void LCD_InvertDisplay(bool invert);

/*
 
 */
void LCD_SetRotation(uint8_t rotate);

/* 
 * Set the display to an RGB version of gray 
 */
void LCD_RGBGrayTest(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ILI9163C_H */

