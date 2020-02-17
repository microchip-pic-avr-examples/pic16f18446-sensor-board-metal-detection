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

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include "images.h"
#include "font.h"
#include "color.h"
#include "ili9163c.h"
#include "graphics.h"

// might change this to uint8_t because of the display size and x/y values
#ifndef _swap_uint8_t
#define _swap_uint8_t(a,b) {uint8_t t = a; a = b; b = t;}
#endif

// pointer to currently set font - not sure if this is needed
FONT *gfxFont;

// currently set fore and background colors - not sure if needed
uint16_t foreColor = WHITE; // white
uint16_t backColor = BLACK; // black

// Range check is an internal only function - clips values to a limited range
// Returns 0 if in range, else returns bit pattern of which axis clipped
uint8_t RangeCheck_XYWH(uint8_t *x, uint8_t *y, uint8_t *w, uint8_t *h)
{
    uint8_t clip = 0;
    
    if(*x > DISPLAY_WIDTH)
    {
        *x = DISPLAY_WIDTH;
        clip |= 1;
    }
    
    if(*y > DISPLAY_HEIGHT)
    {
        *y = DISPLAY_HEIGHT;
        clip |= 2;
    }
    
    if((*x + *w) > DISPLAY_WIDTH)
    {
        *w = DISPLAY_WIDTH - *x;
        clip |= 4;
    }
    
    if((*y + *h) > DISPLAY_HEIGHT)
    {
        *h = DISPLAY_HEIGHT - *y;
        clip |= 8;
    }
    
    return clip;
}

void GFX_Initialize(void)
{
    LCD_Initialize();
}
    
void GFX_ClearScreen(uint16_t color)
{
    LCD_ClearScreen(color);
}

void GFX_SetFgColor(uint16_t color)
{
    foreColor = color;
}

void GFX_SetBgColor(uint16_t color)
{
    backColor = color;
}

void GFX_DrawPixel(uint8_t x, uint8_t y, uint16_t color)
{
    // might need to do some bounds checking of x and y
    if(x>127) x = 127;
    if(y>159) y = 159;
    
    LCD_SetPosition(x, x, y, y);
    LCD_WriteData16bits(color);
}

// this assumes x and y start are smaller than x and y end - need a way to
// draw a line no matter the values of x and y start and end
void GFX_DrawLine(uint8_t xStart, uint8_t yStart, uint8_t xEnd, uint8_t yEnd, uint16_t color)
{
    uint8_t deltaX = abs(xEnd - xStart);
    int8_t  signX  = xStart < xEnd ? 1 : -1;
    uint8_t deltaY = abs(yEnd - yStart);
    int8_t  signY  = yStart < yEnd ? 1 : -1;
    int8_t  error  = (deltaX > deltaY ? deltaX : -deltaY) >> 1;
    int8_t  error2;
    
    uint8_t i=0;
    
    for(;;)
    {
        i++;
        if(i==255) {
            break;
        }
        
        GFX_DrawPixel(xStart, yStart, color);
        if(xStart == xEnd && yStart == yEnd)
            break;
        error2 = error;
        if(error2 > -deltaX)
        {
            error -= deltaY;
            xStart += signX;
        }
        if(error2 < deltaY)
        {
            error += deltaX;
            yStart += signY;
        }
    }
}

void GFX_DrawFastHLine(uint8_t x, uint8_t y, uint8_t width, uint16_t color)
{
    GFX_DrawLine(x, y, x + width - 1, y, color);
}

void GFX_DrawFastVLine(uint8_t x, uint8_t y, uint8_t height, uint16_t color)
{
    GFX_DrawLine(x, y, x, y + height - 1, color);
}

void GFX_DrawRectangle(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t color)
{
    GFX_DrawFastHLine(x, y, width, color);
    GFX_DrawFastHLine(x, y + height - 1, width, color);
    GFX_DrawFastVLine(x, y, height, color);
    GFX_DrawFastVLine(x + width - 1, y, height, color);
}

void GFX_FillRectangle(uint8_t x, uint8_t y, uint8_t width, uint8_t height, uint16_t color)
{
    uint16_t column, row;
    LCD_SetPosition(x, x + width - 1, y, y + height - 1);
    for(row = y; row < y + height; row++)
    {
        for(column = x; column < x + width; column++)
        {
            LCD_WriteData16bits(color);
        }
    }
}

void GFX_DrawTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
    GFX_DrawLine(x0, y0, x1, y1, color);
    GFX_DrawLine(x1, y1, x2, y2, color);
    GFX_DrawLine(x2, y2, x0, y0, color);
}

void GFX_FillTriangle(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color)
{
    
}

void GFX_DrawCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color)
{
    uint8_t inx = radius;
    uint8_t iny = 0;
    int8_t  error = 0;
    
    while(inx >= iny)
    {
        // lower right
        GFX_DrawPixel(x + inx, y + iny, color);
        GFX_DrawPixel(x + iny, y + inx, color);
        
        // lower left
        GFX_DrawPixel(x - iny, y + inx, color);
        GFX_DrawPixel(x - inx, y + iny, color);
        
        // top left
        GFX_DrawPixel(x - inx, y - iny, color);
        GFX_DrawPixel(x - iny, y - inx, color);
        
        // top right
        GFX_DrawPixel(x + iny, y - inx, color);
        GFX_DrawPixel(x + inx, y - iny, color);
        
        if(error <= 0)
        {
            iny += 1;
            error += 2 * iny + 1;
        }
        if(error > 0)
        {
            inx -= 1;
            error -= 2 * inx + 1;
        }
    }
}

void GFX_FillCircle(uint8_t x, uint8_t y, uint8_t radius, uint16_t color)
{
    
}

void GFX_DrawArc(uint8_t x, uint8_t y, uint8_t radius, uint8_t quadrants, uint16_t color)
{
    uint8_t inx = radius;
    uint8_t iny = 0;
    int8_t  error = 0;
    
    // need to test quadrants to see if it is a valid number (1, 2, 4, or 8)
    
    while(inx >= iny)
    {
        if(quadrants & 0x1)
        {
            // top right
            GFX_DrawPixel(x + iny, y - inx, color);
            GFX_DrawPixel(x + inx, y - iny, color);
        }
        if(quadrants & 0x2)
        {
            // top left
            GFX_DrawPixel(x - inx, y - iny, color);
            GFX_DrawPixel(x - iny, y - inx, color);  
        }
        if(quadrants & 0x4)
        {
            // lower left
            GFX_DrawPixel(x - iny, y + inx, color);
            GFX_DrawPixel(x - inx, y + iny, color);
        }
        if(quadrants & 0x8)
        {
            // lower right
            GFX_DrawPixel(x + inx, y + iny, color);
            GFX_DrawPixel(x + iny, y + inx, color);
        }
        
        if(error <= 0)
        {
            iny += 1;
            error += 2 * iny + 1;
        }
        if(error > 0)
        {
            inx -= 1;
            error -= 2 * inx + 1;
        }
    }
}

void GFX_DrawBitmap(uint8_t x, uint8_t y, IMAGE *imageData)
{
    uint16_t count, rgb;
    uint8_t  width, height, m, n;
    uint8_t  *data;
    
    width = imageData->width;
    height = imageData->height;
    data = imageData->pixel_data;
    
    RangeCheck_XYWH(&x, &y, &width, &height);
    
    LCD_SetPosition(x, x + width - 1, y, y + height - 1);
    
    for(count = width * height; count != 0; count--)
    {
        m = *data;
        data++;
        n = *data;
        data++;
        
        rgb = (uint16_t)n << 8;
        rgb |= m;
        
        // Some how figure out what the current background color is and put it in rgb
        // Would like to have a frame buffer and an alpha channel, then we could show the background
        if(rgb == 0x0000)
        {
            rgb = backColor;
        }
        
        LCD_WriteData16bits(rgb);
    }
}

void GFX_DrawIndexedBitmap(uint8_t x, uint8_t y, uint8_t *indexedImageData)
{
    uint8_t  width, height, colorCount;
    uint8_t  *data;
    uint16_t colors[32]; // max 32 colors
    
    width = indexedImageData[0];
    height = indexedImageData[1];
    colorCount = indexedImageData[2];
    
    for(uint8_t i=0; i<colorCount; i++) {
        uint8_t a = indexedImageData[3+4*i];
        uint8_t r = indexedImageData[3+4*i+1];
        uint8_t g = indexedImageData[3+4*i+2];
        uint8_t b = indexedImageData[3+4*i+3];
        
        // convert transparency to black:
        if(a<128) {
            r = g = b = 0;
        }
        
        // RGB24 to 565:
        r = (r >> 3) & 0b11111;
        g = (g >> 2) & 0b111111;
        b = (b >> 3) & 0b11111;
        
        colors[i] = r;
        colors[i] = (colors[i] << 6) + g;
        colors[i] = (colors[i] << 5) + b;
    }
    
    //colors[0] = 0b1111100000000000;
    //colors[1] = 0b1111100000011111;
    //colors[2] = 0b0000011111100000;
    //colors[3] = 0b0000000000011111;
    
    data = indexedImageData+3+(4*colorCount);
        
    RangeCheck_XYWH(&x, &y, &width, &height);
    
    LCD_SetPosition(x, x + width - 1, y, y + height - 1);
    
    uint16_t pixelCount = width * height;
    
    for(uint16_t i=0; i<pixelCount; i++)
    {
        uint8_t cIndex = (data[i >> 2] >> (2*(3-i%4))) & 0x03;
        LCD_WriteData16bits(colors[cIndex]);  
    }
}

void GFX_SetFont(FONT *font)
{
    if(font != NULL)
    {
        gfxFont = font;
    }
}

void GFX_DrawText(uint8_t x, uint8_t y, char *string, uint16_t fgColor, uint16_t bgColor)
{
    uint8_t width, height, count, bitCount, *ch, d, step;
    
    if(gfxFont == NULL)
    {
        return;         // exit if the font is not set
    }
    
    width = gfxFont->w;
    height = gfxFont->h;
    step = (width/8) * height;
    
    while(*string)
    {
        if(*string >= gfxFont->ASCII_Start && *string <= gfxFont->ASCII_End)
        {
            // Point to the start of the Character
            ch = &gfxFont->data[ (*string - gfxFont->ASCII_Start) * step ];
        }
        else
        {
            // Make it a space
            ch = &gfxFont->data[ ( ' ' - gfxFont->ASCII_Start) * step ];
        }
        string++;    
        
        // Write each character
        if(RangeCheck_XYWH(&x,&y,&width,&height) == 0)
        {
            // Set the box to draw in
            LCD_SetPosition(x, x + width - 1, y, y + height - 1); 
          
            // Draw the character
            for(count = 0; count < step; count++)
            {
                d = *ch;
                for(bitCount=0; bitCount < 8; bitCount++)
                {
                    if(d & 0x80) 
                        LCD_WriteData16bits(fgColor);
                    else 
                        LCD_WriteData16bits(bgColor);  // Should skip pixel if possible, or get current background color to write
                    d <<= 1; 
                }
                ch++;
            }
            x += width; // Move to next character position
        }
        else
        {  
            break;      // Out of range so do not display any more characters
        }
    }
}

