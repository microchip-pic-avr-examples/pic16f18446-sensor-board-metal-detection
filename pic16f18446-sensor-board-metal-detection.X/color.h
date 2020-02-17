/**
   Color
   Created on December 24, 2016, 4:11 PM  
 
   @Company
     Microchip Technology Inc.

   @Author
     C16490, include Mike Pearce

   @File Name
     color.h

   @Summary
     This is the color primatives for the display

   @Description
     This header file provides the color primatives for the display. Colors
     are defined and a macro to convert colors into RGB565 format are included.

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

#ifndef COLOR_H
#define	COLOR_H

#include <stdint.h>

// 16 bit color format
typedef union
{
    uint16_t color;
    struct                  // Breakdown of the RGB565
    {
        unsigned  R : 5;
        unsigned  G : 6;
        unsigned  B : 5;
    };
}COLOR16;

// 8 bit color format
typedef union 
{
    uint8_t color;
    struct
    {
        unsigned int R : 3;
        unsigned int G : 3;
        unsigned int B : 2;
    };
    
}COLOR8;

// Default color that matches the display
#define color_t uint16_t

// RGB565 Format converter
#define RGB565(r,g,b) (((uint16_t)r & 0x00F8) << 8) | (((uint16_t)g & 0x00FC) << 3) | (((uint16_t)b & 0x00F8) >> 3)  

//==== STANDARD HTML/CSS/RGB COLOR NAMES BELOW =====
// Reds
#define INDIAN_RED              RGB565(205,  92,  92)
#define LIGHT_CORAL             RGB565(240, 128, 128)
#define SALMON                  RGB565(250, 128, 114)
#define DARK_SALMON             RGB565(233, 150, 122)
#define LIGHT_SALMON            RGB565(255, 160, 122)
#define CRIMSON                 RGB565(220,  20,  60)
#define RED                     RGB565(255,   0,   0)
#define FIRE_BRICK              RGB565(178,  34,  34)
#define DARK_RED                RGB565(139,   0,   0)
#define MAROON                  RGB565(128,   0,   0)

// Pinks
#define PINK                    RGB565(255, 192, 203)
#define LIGHT_PINK              RGB565(255, 182, 193)
#define HOT_PINK                RGB565(255, 105, 180)
#define DEEP_PINK               RGB565(255, 201, 147)
#define MEDIUM_VIOLET_RED       RGB565(199, 211, 133)
#define PALE_VIOLET_RED         RGB565(219, 112, 147)

// Oranges
#define LIGHT_SALMON            RGB565(255, 160, 122)
#define CORAL                   RGB565(255, 127,  80)
#define TOMATO                  RGB565(255,  99,  71)
#define ORANGE_RED              RGB565(255,  69,   0)
#define DARK_ORANGE             RGB565(255, 140,   0)
#define ORANGE                  RGB565(255, 165,   0)

// Yellows
#define GOLD                    RGB565(255, 215,   0)
#define YELLOW                  RGB565(255, 255,   0)
#define LIGHT_YELLOW            RGB565(255, 255, 244)
#define LEMON_CHIFFON           RGB565(255, 250, 205)
#define LIGHT_GOLDENROD_YELLOW 	RGB565(250, 250, 210)
#define PAPAYA_WHIP             RGB565(255, 239, 213)
#define MOCCASIN                RGB565(255, 228, 181)
#define PEACH_PUFF              RGB565(255, 218, 185)
#define PALE_GOLDENROD          RGB565(238, 232, 170)

// Greens
#define GREEN_YELLOW            RGB565(173, 255,  47)
#define CHARTREUSE              RGB565(127, 255,    )
#define LAWN_GREEN              RGB565(124, 255,   0)
#define LIME                    RGB565(  0, 255,   0)
#define LIME_GREEN              RGB565( 50, 205,  50)
#define PALE_GREEN              RGB565(152, 251, 152)
#define LIGHT_GREEN             RGB565(144, 238, 144)
#define MEDIUM_SPRING_GREEN 	RGB565(  0, 250, 154)
#define SPRING_GREEN            RGB565(  0, 255, 127)
#define MEDIUM_SEA_GREEN        RGB565( 60, 179, 113)
#define SEA_GREEN               RGB565( 46, 139,  87)
#define FOREST_GREEN            RGB565( 34, 139,  34)
#define GREEN                   RGB565(  0, 128,   0)
#define DARK_GREEN              RGB565(  0, 100,   0)
#define YELLOW_GREEN            RGB565(154, 205,  50)
#define OLIVE_DRAB              RGB565(107, 142,  35)
#define OLIVE                   RGB565(128, 128,   0)
#define DARK_OLIVE_GREEN        RGB565( 85, 107,  47)
#define MEDIUM_AQUAMARINE       RGB565(102, 205, 170)
#define DARK_SEA_GREEN          RGB565(143, 188, 143)
#define LIGHT_SEA_GREEN         RGB565( 32, 178, 170)

// Blues/Cyans
#define AQUA                    RGB565(  0, 255, 255)
#define CYAN                    RGB565(  0, 255, 255)
#define LIGHT_CYAN              RGB565(224, 255, 255)
#define DARK_CYAN               RGB565(  0, 139, 139)
#define TEAL                    RGB565(  0, 128, 128)
#define PALE_TURQUOISE          RGB565(175, 238, 238)
#define AQUAMARINE              RGB565(127, 255, 212)
#define TURQUOISE               RGB565( 64, 224, 208)
#define MEDIUM_TURQUOISE        RGB565( 72, 209, 204)
#define DARK_TURQUOISE          RGB565(  0, 206, 209)
#define CADET_BLUE              RGB565( 95, 158, 160)
#define STEEL_BLUE              RGB565( 70, 130, 180)
#define LIGHT_STEEL_BLUE        RGB565(176, 196, 222)
#define POWDER_BLUE             RGB565(176, 224, 230)
#define LIGHT_BLUE              RGB565(173, 216, 230)
#define SKY_BLUE                RGB565(135, 206, 235)
#define LIGHT_SKY_BLUE          RGB565(135, 206, 250)
#define DEEP_SKY_BLUE           RGB565(  0, 191, 255)
#define DODGER_BLUE             RGB565( 30, 144, 255)
#define CORNFLOWER_BLUE         RGB565(100, 149, 237)
#define MEDIUM_SLATE_BLUE       RGB565(123, 104, 238)
#define ROYAL_BLUE              RGB565( 65, 105, 225)
#define BLUE                    RGB565(  0,   0, 255)
#define MEDIUM_BLUE             RGB565(  0,   0, 205)
#define DARK_BLUE               RGB565(  0,   0, 139)
#define NAVY                    RGB565(  0,   0, 128)
#define MIDNIGHT_BLUE           RGB565( 25,  25, 112)

// Purples
#define LAVENDER                RGB565(230, 230, 250
#define THISTLE                 RGB565(216, 191, 216)
#define PLUM                    RGB565(221, 160, 221)
#define VIOLET                  RGB565(238, 130, 238)
#define ORCHID                  RGB565(218, 112, 214)
#define FUCHSIA                 RGB565(255,   0, 255)
#define MAGENTA                 RGB565(255,   0, 255)
#define MEDIUM_ORCHID           RGB565(186,  85, 211)
#define MEDIUM_PURPLE           RGB565(147, 112, 219)
#define AMETHYST                RGB565(153, 102, 204)
#define BLUE_VIOLET             RGB565(138,  43, 226)
#define DARK_VIOLET             RGB565(148,   0, 211)
#define DARK_ORCHID             RGB565(153,  50, 204)
#define DARK_MAGENTA            RGB565(139,   0, 139)
#define PURPLE                  RGB565(128,   0, 128)
#define INDIGO                  RGB565( 75,   0, 130)
#define SLATE_BLUE              RGB565(106,  90, 205)
#define DARK_SLATE_BLUE         RGB565( 72,  61, 139)
#define MEDIUM_SLATE_BLUE       RGB565(123, 104, 238)

// Browns
#define KHAKI                   RGB565(240, 230, 140)
#define DARK_KHAKI              RGB565(189, 183, 107)
#define CORNSILK                RGB565(255, 248, 220)
#define BLANCHED_ALMOND         RGB565(255, 235, 205)
#define BISQUE                  RGB565(255, 228, 196)
#define NAVAJO_WHITE            RGB565(255, 222, 173)
#define WHEAT                   RGB565(245, 222, 179)
#define BURLY_WOOD              RGB565(222, 184, 135)
#define TAN                     RGB565(210, 180, 140)
#define ROSY_BROWN              RGB565(188, 143, 143)
#define SANDY_BROWN             RGB565(244, 164,  96)
#define GOLDENROD               RGB565(218, 165,  32)
#define DARK_GOLDENROD          RGB565(184, 134,  11)
#define PERU                    RGB565(205, 133,  63)
#define CHOCOLATE               RGB565(210, 105,  30)
#define SADDLE_BROWN            RGB565(139,  69,  19)
#define SIENNA                  RGB565(160,  82,  45)
#define BROWN                   RGB565(165,  42,  42)

// Whites
#define WHITE                   RGB565(255, 255, 255)
#define SNOW                    RGB565(255, 250, 250)
#define HONEYDEW                RGB565(240, 255, 240)
#define MINT_CREAM              RGB565(245, 255, 250)
#define AZURE                   RGB565(240, 255, 255)
#define ALICE_BLUE              RGB565(240, 248, 255)
#define GHOST_WHITE             RGB565(248, 248, 255)
#define WHITE_SMOKE             RGB565(245, 245, 245)
#define SEASHELL                RGB565(255, 245, 238)
#define BEIGE                   RGB565(245, 245, 220)
#define OLD_LACE                RGB565(253, 245, 230)
#define FLORAL_WHITE            RGB565(255, 250, 240)
#define IVORY                   RGB565(255, 255, 240)
#define ANTIQUE_WHITE           RGB565(250, 235, 215)
#define LINEN                   RGB565(250, 240, 230)
#define LAVENDER_BLUSH          RGB565(255, 240, 245)
#define MISTY_ROSE              RGB565(255, 228, 225)

// Grays and Black
#define WHISPER                 RGB565(239, 230, 230)
#define GAINSBORO               RGB565(220, 220, 220)
#define LIGHT_GRAY              RGB565(211, 211, 211)
#define VERY_LIGHT_GRAY      	RGB565(205, 205, 205)
#define SILVER                  RGB565(192, 192, 192)
#define DARK_GRAY               RGB565(169, 169, 169)
#define NOBEL                   RGB565(169, 157, 157)
#define GRAY                    RGB565(128, 128, 128)
#define DIM_GRAY                RGB565(105, 105, 105)
#define ZAMBEZI                 RGB565( 96,  96,  96)
#define LIGHT_SLATE_GRAY        RGB565(119, 136, 153)
#define SLATE_GRAY              RGB565(112, 128, 144)
#define DARK_SLATE_GRAY         RGB565( 47,  79,  79)
#define ECLIPSE                 RGB565( 64,  64,  64)
#define NERO                    RGB565( 32,  32,  32)
#define BLACK                   RGB565(  0,   0,   0)

#endif	/* COLOR_H */

