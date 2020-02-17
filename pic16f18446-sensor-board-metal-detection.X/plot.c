/*
 * File:   plot.c
 * Author: M19219
 *
 * Created on November 20, 2017, 4:20 PM
 */

#include <stdint.h>
#include "plot.h"
#include "graphics.h"


plot_t plot1, plot2;

void addToPlot(plot_t* plot, int16_t sample) {
    
    if(sample<0) {
        sample = 0;
    }
    if(sample>255) {
        sample = 255;
    }
    
    plot->oldPlotBuf[plot->plotBufIndex] = plot->plotBuf[(plot->plotBufIndex+127)%128];
    plot->plotBuf[plot->plotBufIndex] = sample;
    plot->plotBufIndex++;
    plot->plotBufIndex = plot->plotBufIndex % 128;  
}

void clearPlot(plot_t* plot, uint8_t value) {
    for(uint8_t i=0; i<128; i++) {
        plot->oldPlotBuf[i] = value;
        plot->plotBuf[i] = value;
    }
    plot->plotBufIndex = 0;
}


void drawPlot(plot_t* plot, uint8_t x, uint8_t y, uint8_t h, uint16_t color) {
    uint16_t sample;
    
    uint8_t x1, y1; //, x2, y2;
    
    
    //GFX_FillRectangle(x, y, 128, h, 0x0000);
    for(uint16_t i=0; i<127; i++) {
        
        x1 = x+i;
        //x2 = x1+1;
       
        sample = 255 - plot->oldPlotBuf[(plot->plotBufIndex+i)%128];
        sample *= h;
        sample = sample >> 8;
        if(sample>h-1) {
            sample = h-1;
        }
        y1 = y+sample;
        
        /*sample = 255 - plot->oldPlotBuf[(plot->plotBufIndex+i+1)%128];
        sample *= h;
        sample = sample >> 8;
        if(sample>h-1) {
            sample = h-1;
        }
        y2 = y+sample;*/
        
        GFX_DrawPixel(x1, y1, 0x0000);
        //GFX_DrawLine(x1, y1, x2, y2, 0x0000);
      
        
        
        
        sample = 255 - plot->plotBuf[(plot->plotBufIndex+i)%128];
        sample *= h;
        sample = sample >> 8;  
        if(sample>h-1) {
            sample = h-1;
        }
        y1 = y+sample;
        
        /*sample = 255 - plot->plotBuf[(plot->plotBufIndex+i+1)%128];
        sample *= h;
        sample = sample >> 8;
        if(sample>h-1) {
            sample = h-1;
        }
        y2 = y+sample;*/
     
        GFX_DrawPixel(x1, y1, color);
        //GFX_DrawLine(x1, y1, x2, y2, 0xFF00);
        
    }
}