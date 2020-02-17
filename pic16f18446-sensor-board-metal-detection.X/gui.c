/*
 * File:   gui.c
 * Author: M19219
 *
 * Created on December 6, 2017, 10:02 AM
 */

#include "gui.h"



void metalDetectorScreenTasks() {
    
    //readBattery();
    //drawBatteryIcon(110, 1, 16, 8, 0xFF00);
     
    readMetalDetector();
    drawMetalDetectorPlots(0, 30, 0xFF00);  
      
}



void metalDetectorBuzzScreenStatic() {
    
    GFX_DrawText(0, 0, "Metal Detector", 0xFF00, 0x0000);
    GFX_DrawText(0, 15, "Buzz            ", 0xFF00, 0x0000);  
    
}