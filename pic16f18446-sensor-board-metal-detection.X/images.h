/**
   Image Primitives
   Created on December 15, 2016, 3:06 PM  
 
   @Company
     Microchip Technology Inc.

   @Author
     C14106, C16490

   @File Name
     images.h

   @Summary
     This is the image/bitmap primitives for the graphics library

   @Description
     This header file provides implementations for driver APIs for 
     the image primitives used in the graphics library.

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

#ifndef IMAGES_H
#define	IMAGES_H

#include <stdint.h>

// This is for Function Calls only, please use the struct based on your 
// actual image size
 typedef struct
{
  uint8_t  width;
  uint8_t  height;         
  uint8_t  bytes_per_pixel; // 1: 323 or Indexed,  2:RGB 565, 3:RGB 888, 4:RGBA 8888  
  uint8_t  pixel_data[];
}IMAGE;   

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[16 * 16 * 2 + 1];  // 513 Bytes
}IMAGE16;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[32 * 32 * 2 + 1]; // 2049 bytes
}IMAGE32;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[5 * 10 * 2 + 1]; // 2049 bytes
}IMAGE5x10;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[10 * 10 * 2 + 1]; // 2049 bytes
}IMAGE10;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[20 * 20 * 2 + 1]; // 2049 bytes
}IMAGE20;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[16 * 19 * 2 + 1];  // 513 Bytes
}IMAGE16x19;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[50 * 60 * 2 + 1]; // 6001 bytes
}IMAGE50x60;

typedef struct
{
  uint8_t  width;
  uint8_t  height;
  uint8_t  bytes_per_pixel; /* 2:RGB16, 3:RGB, 4:RGBA */ 
  uint8_t  pixel_data[70 * 30 * 2 + 1]; // 9101 bytes
}IMAGE70x65;

typedef struct
{
  uint8_t  width;
  uint8_t  height;        
  uint8_t  bytes_per_pixel; // 1: 323 or Indexed,  2:RGB 565, 3:RGB 888, 4:RGBA 8888  
  uint8_t  pixel_data[100 * 20 * 2 + 1]; // 4001 bytes
}IMAGE100x20;

//typedef struct
//{
//  uint8_t  width;
//  uint8_t  height;         
//  uint8_t  bytes_per_pixel; // 1: 323 or Indexed,  2:RGB 565, 3:RGB 888, 4:RGBA 8888  
//  uint8_t  pixel_data[120 * 160 * 2 + 1]; //38401 bytes
//}IMAGE120x160;     

#endif	/* IMAGES_H */

