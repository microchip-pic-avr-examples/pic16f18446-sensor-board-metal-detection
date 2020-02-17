/*
 * File:   metal_detector.c
 * Author: M19219
 *
 * Created on January 17, 2018, 2:19 PM
 */


#include "metal_detector.h"

#define SCAN_FREQ_MIN 30000
#define SCAN_FREQ_MAX 45000

static int32_t scanFreqMin, scanFreqMax, scanFreqStep;

int32_t	peakFreq = 0;
static int32_t	peakAmpl;
static int32_t	offsetAmpl;
static int32_t	offsetFreq;


int32_t md10bit, md12bit;
int32_t md10bitOffset, md12bitOffset;



void setNcoFreq(uint32_t freq) { // for 32MHz System Clock
    
    //freq = freq/15.26;// >> 4; // /16
    
    freq *= 100;
    freq /= 1526;

    NCO1INCU = ((freq >> 16) & 0xFF);
    NCO1INCH = ((freq >>  8) & 0xFF);
    NCO1INCL = ((freq      ) & 0xFF);
}



void enableNco() {
    NCO1CONbits.EN = 1;
}


void disableNco() {
    NCO1CONbits.EN = 0;
}



void updateScanFreqStep() {
    scanFreqStep = (scanFreqMax - scanFreqMin) / 25;
    if(scanFreqStep < 4) {
        scanFreqStep = 4;
    }  
}


void initMetalDetect() {
    
    scanFreqMin = SCAN_FREQ_MIN;
    scanFreqMax = SCAN_FREQ_MAX;
    
    updateScanFreqStep();
    
    metalDetectorDrawFreqScanning();    
    metalDetectorGetPeakFreq();
}


void metalDetectorDrawFreqScanning() {
    GFX_DrawText(0, 0, "Metal Detector", 0xFF00, 0x0000);
    GFX_DrawText(0, 15, "Freq.:  SCANNING", 0xFF00, 0x0000);
}


void metalDetectorDrawPFreq() {
    GFX_DrawText(0, 0, "Metal Detector", 0xFF00, 0x0000);
    GFX_DrawText(0, 15, "Freq.:        Hz", 0xFF00, 0x0000);
    
    metalDetectorDrawPeakFreq(70, 15, 0xFF00);
}


void metalDetectorGetPeakFreq() {
    uint16_t scf, i;   
    uint32_t res = 0;
    
    ADREF = 0x00; // ADNREF VSS; ADPREF VDD
    
    enableNco();
    
    peakFreq = 0;			// reset peak tracking frequency
	peakAmpl = 0;			// reset peak tracking amplitude
    
    
    
    
    for(scf = scanFreqMin; scf < scanFreqMax; scf += scanFreqStep) {
          
        setNcoFreq(scf);
        
        __delay_us(250);
        
        res = 0;
        for(i=0; i<8; i++) {
            ADCC_GetSingleConversion(channel_MetalDetector);
            res += ADCC_GetAccumulatorValue() >> 6;
        }
        res = res >> 3;
       
        if(res > peakAmpl) {
            peakAmpl = res;
            peakFreq = scf;   
        }        
    }
    
    setNcoFreq(peakFreq);
    __delay_us(250);
    
    readMetalDetector();  
    md10bitOffset = md10bit;
    md12bitOffset = md12bit; 
    
}





void metalDetectorDrawPeakFreq(uint8_t x, uint8_t y, uint16_t color) {
    
    uint8_t st[8];
    int32_t a;
    uint8_t i;
    
    a = peakFreq;
 
    i = 0;
    st[i++] = ((a/10000)%10) + '0';
    st[i++] = ((a/1000)%10) + '0';
    st[i++] = ((a/100)%10) + '0';
    st[i++] = ((a/10)%10) + '0';
    st[i++] = ((a/1)%10) + '0';
    st[i] = 0;
              
    i = 0;
    if(a<10000) st[i++] = ' ';
    if(a<1000) st[i++] = ' ';
    if(a<100) st[i++] = ' ';
    if(a<10) st[i] = ' ';
    
    GFX_DrawText(x, y, st, color, 0x0000);  
    
}



void readMetalDetector() {   
    uint32_t res;
    uint16_t i;
    
    //ADREF = 0x03; // ADNREF VSS; ADPREF FVR
    ADREF = 0x00; // ADNREF VSS; ADPREF VDD
  
    res = 0;
    
    for(i=0; i<32; i++) {
        ADCC_GetSingleConversion(channel_MetalDetector); 
        res += (ADCC_GetAccumulatorValue() >> 6);
    }

    res = res >> 5;
    
    
    /*ADCC_GetSingleConversion(channel_MetalDetector);
    res = ADCC_GetAccumulatorValue() >> 6;
    
    if(mdami==-1) {
        mdamAcc = 0;
        for(i=0; i<MD_ADC_MEM_SIZE; i++) {
            mdAdcMem[i] = res;
            mdamAcc += res;
        }
        mdami = 0;
    } else {
        mdamAcc -= mdAdcMem[mdami];
        mdAdcMem[mdami] = res;
        mdamAcc += mdAdcMem[mdami];
        mdami++;
        mdami = mdami % MD_ADC_MEM_SIZE;
    }
    
    res = mdamAcc/MD_ADC_MEM_SIZE;*/
    
    res = 4095 - res;
      
    md10bit = (res & 0xFFFFFFFC);
    md12bit =  res              ;    
}



void drawMetalDetectorValue(uint8_t x, uint8_t y, uint16_t color) {
    
    uint8_t st[16];
    uint32_t a;
    
    a = md12bit;
    
    st[ 0] = ((a/1000000)%10) + '0';
    st[ 1] = ((a/100000)%10) + '0';
    st[ 2] = ((a/10000)%10) + '0';
    st[ 3] = ((a/1000)%10) + '0';
    st[ 4] = ((a/100)%10) + '0';
    st[ 5] = ((a/10)%10) + '0';  
    st[ 6] = ((a/1)%10) + '0';  
    st[ 7] = 0;  
  
    if(a<1000000) st[0] = ' ';
    if(a<100000) st[1] = ' ';
    if(a<10000) st[2] = ' ';
    if(a<1000) st[3] = ' ';
    if(a<100) st[4] = ' ';
    if(a<10) st[5] = ' ';
    
    GFX_DrawText(x, y, st, color, 0x0000);    
}



void initMetalDetectorPlots() {
    
    clearPlot(&plot1, 64);
    clearPlot(&plot2, 64);
    
}


void drawMetalDetectorPlots(uint8_t x, uint8_t y, uint16_t color) {
    
    int32_t v;
    
    v = 64 + (md12bit - md12bitOffset)*5;
    
    if(v<0) v = 0;
    if(v>255) v = 255;
    
    addToPlot(&plot1, (uint8_t)v);           
    drawPlot(&plot1, x, y, 65, color);
    
    
    v = 64 + (md10bit - md10bitOffset)*5;
    
    if(v<0) v = 0;
    if(v>255) v = 255;
    
    addToPlot(&plot2, (uint8_t)v);           
    drawPlot(&plot2, x, y+65, 65, color);
    
}




volatile uint16_t tBeep = 0xF9E5;
volatile uint16_t tSilence = 0x85EE; // 2s
volatile uint8_t tState = 0;


void tmr3isr() {
    
    tState = !tState;
    if(tState) { // beep
        TMR3_WriteTimer(tBeep);
        BUZZ_P_TRIS = 0;
        BUZZ_N_TRIS = 0;
    } else {
        TMR3_WriteTimer(tSilence);
        BUZZ_P_TRIS = 1;
        BUZZ_N_TRIS = 1;
    } 
}


void metalDetectorBuzzerEnable(void)
{
    BUZZ_P_TRIS = 1; // still OFF (ISR will turn it ON)
    BUZZ_N_TRIS = 1;
    CCP1_SetCompareCount(1050); // tone for the beeps
    TMR3_SetInterruptHandler(tmr3isr);   
    TMR3_StartTimer();
}


void metalDetectorBuzzerDisable(void)
{
    BUZZ_P_TRIS = 1;
    BUZZ_N_TRIS = 1;
    TMR3_SetInterruptHandler(TMR3_DefaultInterruptHandler);
    TMR3_StopTimer();
}



// 20*(0 .. 100)^(1/3)
const uint8_t scale[101] =
{0, 20, 25, 28, 31, 34, 36, 38, 40, 41, 43, 44, 45, 47,
48, 49, 50, 51, 52, 53, 54, 55, 56, 56, 57, 58, 59, 60,
60, 61, 62, 62, 63, 64, 64, 65, 66, 66, 67, 67, 68, 68,
69, 70, 70, 71, 71, 72, 72, 73, 73, 74, 74, 75, 75, 76,
76, 76, 77, 77, 78, 78, 79, 79, 80, 80, 80, 81, 81, 82,
82, 82, 83, 83, 83, 84, 84, 85, 85, 85, 86, 86, 86, 87,
87, 87, 88, 88, 88, 89, 89, 89, 90, 90, 90, 91, 91, 91, 92, 92, 92};


void metalDetectorBuzz(void)
{
    
    readMetalDetector();
    
    int16_t a = 50 + (md12bit - md12bitOffset);
    int16_t v2 = a - 50;
    
    if (a < 0)
    {
        a = 0;
    }

    if (a > 199)
    {
        a = 199;
    }
    
    a = 200 - a;
    
    a *= 15;
    
    if (a == 3000)
    {
        a = 0x7FFF;
    }
    
    //CCP1_SetCompareCount(a);
    
    if (v2 < 0)
    {
        v2 = 0;
    }
    else
    {
        if (v2 > 100)
        {
            v2 = 100;
        }
    }
    
    
    
    // v2  tBeep  tSilence
    // 0   0.1     2
    // 100 0.1     0.1
    
    tSilence = 34286 + scale[v2]*339;
    
    if(TMR3_ReadTimer() < tSilence) {
        TMR3_WriteTimer(tSilence);
    }
  
    
}