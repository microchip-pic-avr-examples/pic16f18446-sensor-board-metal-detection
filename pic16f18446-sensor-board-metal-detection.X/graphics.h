/**
   Graphic Primitives
   Created on December 15, 2016, 1:45 PM  
 
   @Company
     Microchip Technology Inc.

   @Author
     C16490

   @File Name
     graphics.h

   @Summary
     This is the graphic primitives for the 1.8" TFT display

   @Description
     This header file provides implementations for driver APIs for 
     the graphic primitives used on the 1.8" TFT display.

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

#ifndef GFX_H
#define	GFX_H

#include <stdint.h>
#include "font.h"
#include "images.h"

// circle quadrants for circle and arc drawing routines
#define QUADRANT_I      1
#define QUADRANT_II     2
#define QUADRANT_III    4
#define QUADRANT_IV     8
  
/*
     
 */
void GFX_Initialize(void);
    
/*
     
 */
void GFX_ClearScreen(uint16_t color);

/*
 
 */
void GFX_SetFgColor(uint16_t color);

/*
 
 */
void GFX_SetBgColor(uint16_t color);

/*
     
 */
void GFX_DrawPixel(uint8_t x, uint8_t y, uint16_t color);

/*
 
 */
void GFX_DrawLine(uint8_t xStart, uint8_t yStart, uint8_t xEnd, uint8_t yEnd, uint16_t color);

/*
 
 */
void GFX_DrawFastHLine(uint8_t x, uint8_t y, uint8_t width, uint16_t color);

/*
 
 */
void GFX_DrawFastVLine(uint8_t x, uint8_t y, uint8_t height, uint16_t color);

/*
 
 */
void GFX_DrawRectangle(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t color);

/*
 
 */
void GFX_FillRectangle(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t color);

/*
 
 */
void GFX_DrawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);

/*
 
 */
void GFX_FillTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);

/*
 
 */
void GFX_DrawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color);

/*
 
 */
void GFX_FillCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color);

/*
 
 */
void GFX_DrawArc(uint8_t x, uint8_t y, uint8_t radius, uint8_t quadrants, uint16_t color);

/*
 
 */
void GFX_DrawBitmap(uint8_t x, uint8_t y, IMAGE *imageData);

/*
 
 */
void GFX_DrawIndexedBitmap(uint8_t x, uint8_t y, uint8_t *indexedImageData);

/*
 
 */
void GFX_SetFont(FONT *font);

/*
 
 */
void GFX_DrawText(uint8_t x, uint8_t y, char *string, uint16_t fgColor, uint16_t bgColor);

#endif	/* GFX_H */

