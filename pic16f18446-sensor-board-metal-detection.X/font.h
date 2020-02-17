/**
   Font Primitives
   Created on December 15, 2016, 3:22 PM  
 
   @Company
     Microchip Technology Inc.

   @Author
     C16490

   @File Name
     font.h

   @Summary
     This is the font primitives for the graphics library

   @Description
     This header file provides implementations for driver APIs for 
     the font primitives used in the graphics library.

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

#ifndef FONT_H
#define	FONT_H

// FONT - This is the bit mapped single color font
#define FONT_INTERNAL  0   // Internal FLASH Used - Currently only option supported
#define FONT_EXTERNAL  1   // External FLASH (SPI or I2C bus FLASH)
#define FONT_FILE      2   // SD CARD used

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct
{
    uint8_t w;           // Character width in pixels (Steps of 8 for this library!).
    uint8_t h;           // Character Height in pixels (Steps of 1).
    uint8_t ASCII_Start; // First ASCII code in the font
    uint8_t ASCII_End;   // Last ASCII code in the font
    uint8_t DType;       // INTERNAL / EXTERNAL / FILE  - Currently Internal only
    uint8_t *data;       // pointer to internal data or external or file
}FONT;

// Example Font:
// const uint8_t GiggleData[8*128]=
// {
//    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // NULL Character
//    ......  
//    0x00,0x18,0x08,0x08,0x08,0x08,0x0C,0x00,    // 'l' Character
//    ......
// };
// const FONT Giggles = { 8, 8, 0, 127, FONT_INTERNAL, GiggleData}; // 8x8 font, ASCI characters 0 to 127 

#ifdef	__cplusplus
}
#endif

#endif	/* FONT_H */

