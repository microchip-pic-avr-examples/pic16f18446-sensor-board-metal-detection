/**
   ili9163c TFT Display Driver File
   Created on December 8, 2016, 3:02 PM  
 
   @Company
     Microchip Technology Inc.

   @Author
     C16490

   @File Name
     ili9163c.c

   @Summary
     This is the driver implementation file for the TFT Display

   @Description
     This source file provides APIs for the 1.8" TFT display.

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


#include "ili9163c.h"
#include "mcc_generated_files/mcc.h"

// Command defines only useful for this display controller chip
#define ILI9163C_NOP        0x00    // no operation
#define ILI9163C_SWRESET    0x01    // software reset
#define ILI9163C_RDDID      0x04    // read display ID
#define ILI9163C_RDDST      0x09    // read display status
#define ILI9163C_RDMODE     0x0A    // read display power mode
#define ILI9163C_RDMADCTL   0x0B    // read display MADCTL
#define ILI9163C_RDPIXFMT   0x0C    // read display pixel format
#define ILI9163C_RDIMGFMT   0x0D    // read display image mode
#define ILI9163C_RDDSM1     0x0E    // read display signal mode register 1
#define ILI9163C_RDDSM2     0x0F    // read display signal mode register 2
#define ILI9163C_RDSELFDIAG 0x0F    // ?

#define ILI9163C_SLPIN      0x10    // sleep in  (enter sleep mode)
#define ILI9163C_SLPOUT     0x11    // sleep out (exit sleep mode)

#define ILI9163C_PTLON      0x12    // partial mode on
#define ILI9163C_NORON      0x13    // normal display mode on
#define ILI9163C_INVOFF     0x20    // display inversion off
#define ILI9163C_INVON      0x21    // display inversion on
#define ILI9163C_GAMMASET   0x26    // gamma set
#define ILI9163C_DISPOFF    0x28    // display off
#define ILI9163C_DISPON     0x29    // display off

#define ILI9163C_CASET      0x2A    // column address set
#define ILI9163C_PASET      0x2B    // page address set
#define ILI9163C_RAMWR      0x2C    // memory write
#define ILI9163C_COLORSET   0x2D    // color setting (4K, 65K, and 262K color)
#define ILI9163C_RAMRD      0x2E    // memory read

#define ILI9163C_PTLAR      0x30    // partial area
#define ILI9163C_VRTSCLDEF  0x33    // vertical scrolling definition
#define ILI9163C_TELINEOFF  0x34    // tearing effect line off
#define ILI9163C_TELINEON   0x35    // tearing effect line on
#define ILI9163C_MADCTL     0x36    // memory access control
#define ILI9163C_VSSTRADD   0x37    // vertical scrolling start address
#define ILI9163C_IMOFF      0x38    // idle mode off
#define ILI9163C_IMON       0x39    // idle mode on
#define ILI9163C_PIXFMT     0x3A    // interface pixel formet

#define ILI9163C_FRMCTR1    0xB1    // frame rate control (normal mode)
#define ILI9163C_FRMCTR2    0xB2    // frame rate control (idle mode)
#define ILI9163C_FRMCTR3    0xB3    // frame rate control (partial mode)
#define ILI9163C_INVCTR     0xB4    // display inversion control
#define ILI9163C_RGB_IBP    0xB5    // RGB interface blanking porch setting
#define ILI9163C_DFUNCTR    0xB6    // display function set
#define ILI9163C_SDDC       0xB7    // source driver direction control
#define ILI9163C_GDDC       0xB8    // gate driver direction control

#define ILI9163C_PWCTR1     0xC0    // power control 1
#define ILI9163C_PWCTR2     0xC1    // power control 2
#define ILI9163C_PWCTR3     0xC2    // power control 3
#define ILI9163C_PWCTR4     0xC3    // power control 4
#define ILI9163C_PWCTR5     0xC4    // power control 5
#define ILI9163C_VMCTR1     0xC5    // VCOM control 1
#define ILI9163C_VMCTR2     0xC7    // VCOM offset control 2

#define ILI9163C_WRID4      0xD3    // write ID4 value
#define ILI9163C_NVMFC1     0xD5    // NV memory function controller 1
#define ILI9163C_NVMFC2     0xD6    // NV memory function controller 2
#define ILI9163C_NVMFC3     0xD7    // NV memory function controller 3
#define ILI9163C_RDID1      0xDA    // read ID 1
#define ILI9163C_RDID2      0xDB    // read ID 2
#define ILI9163C_RDID3      0xDC    // read ID 3
#define ILI9163C_RDID4      0xDD    // read ID 4

#define ILI9163C_GMCTRP1    0xE0    // positive gamma correction setting
#define ILI9163C_GMCTRN1    0xE1    // negative gamma correction setting
#define ILI9163C_GAMRSEL    0xF2    // gamma r select


void lcdSelect() {
    LCD_CS_LAT = 0;
}

void lcdDeselect() {
    LCD_CS_LAT = 1;
}


void lcdClkDelay() {
    __delay_us(1);
}

/*void lcdClkPulse() {
    //lcdClkDelay();
    LCD_SCL_LAT = 1;
    //lcdClkDelay();
    LCD_SCL_LAT = 0;
}*/


uint8_t flip8(uint8_t d) {
    uint8_t res = 0;
    uint8_t i;
    
    for(i=0; i<8; i++) {
        res = (res << 1) + (d & 1);
        d = d >> 1;
    }
    return res;
}


void LCD_Write(uint8_t dcx, uint8_t d) {
    
    // disable HW SDO:
    CLC2POLbits.LC2G2POL = 1;
    
    // write first bit (out of 9):  
    CLC2POLbits.LC2G4POL = dcx;  
    
    // CLK pulse:
    //MDCONbits.MDBIT = 1;
    //MDCONbits.MDBIT = 0;
    CLC1POLbits.LC1POL = 1;
    CLC1POLbits.LC1POL = 0;
    
    // disable SW SDO:
    CLC2POLbits.LC2G4POL = 0;
    
    // enable HW SDO:
    CLC2POLbits.LC2G2POL = 0;
   
    SPI1_Open(SPI1_DEFAULT);
    SPI1_ExchangeByte(d);
    SPI1_Close();
    
    /*d = flip8(d);
    
    for(uint8_t i=0; i<8; i++) {
        LCD_SDIO_LAT = d & 1;
        d = d >> 1;
        lcdClkPulse();
    }*/
    
}

void LCD_WriteCmd(uint8_t d) {
    LCD_Write(0, d);
}

void LCD_WriteCmdData(uint8_t d) {
    LCD_Write(1, d);
}


void LCD_Initialize(void)
{
    //LCD_BACKLIGHT_LAT = 0;
            
    LCD_CS_LAT = 1; // A1 (pin12) (ch1)
    
    
    // LCD reset sequence
    LCD_RESET_LAT = 0;
    __delay_ms(100); // was 50
    LCD_RESET_LAT = 1;
    __delay_ms(300); // was 150
    
    
    // LCD initialization requirements
    lcdSelect(); 
                                       
    LCD_WriteCmd(ILI9163C_SLPOUT);      // Exit sleep mode     
    __delay_ms(50);
    
    LCD_WriteCmd(ILI9163C_GAMMASET);    // Set default gamma     
    LCD_WriteCmdData(0x04);
    
    LCD_WriteCmd(ILI9163C_FRMCTR1);     // Frame Rate Control     
    LCD_WriteCmdData(0x10);             // *** This should be 0x10
    LCD_WriteCmdData(0x08);             // *** This should be 0x08
    
    LCD_WriteCmd(ILI9163C_PWCTR1);      // Set VRH1[4:0] & VC[2:0] for VCI1 & GVDD
    LCD_WriteCmdData(0x0C);
    LCD_WriteCmdData(0x05);
    
    LCD_WriteCmd(ILI9163C_PWCTR2);      // Set BT[2:0] for AVDD & VCL & VGH & VGL
    LCD_WriteCmdData(0x02);
    
    LCD_WriteCmd(ILI9163C_VMCTR1);      // Set VMH[6:0] & VML[6:0] for VOMH & VCOML
    LCD_WriteCmdData(0x4E);
    LCD_WriteCmdData(0x30);
    
    LCD_WriteCmd(ILI9163C_VMCTR2);      // VCOM Offset - Set VMA[6:0]
    LCD_WriteCmdData(0xC0);
    
    LCD_WriteCmd(ILI9163C_PIXFMT);      // Set Pixel Format
    LCD_WriteCmdData(0x05);             // 16-bits per pixel (565 color)
    
    LCD_WriteCmd(ILI9163C_CASET);       // Set Column Address
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(0x7F);
    
    LCD_WriteCmd(ILI9163C_PASET);       // Set Page Address
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(0x9F);
    
    //LCD_WriteCmd(ILI9163C_INVCTR);      // Frame inversion
    //LCD_WriteCmdData(0x07);
    
    LCD_WriteCmd(ILI9163C_MADCTL);      // Set Scanning Direction - memory access control
    LCD_WriteCmdData(0xC0);
    
    LCD_WriteCmd(ILI9163C_GAMRSEL);     // Enable Gamma bit
    LCD_WriteCmdData(0x01);

    LCD_WriteCmd(ILI9163C_GMCTRP1);     // Positive Gamma correction
    LCD_WriteCmdData(0x3F);             // p1   VP63[5:0]
    LCD_WriteCmdData(0x31);             // p2   VP62[5:0]
    LCD_WriteCmdData(0x2D);             // p3   VP61[5:0]
    LCD_WriteCmdData(0x2F);             // p4   VP59[5:0]
    LCD_WriteCmdData(0x28);             // p5   VP57[5:0]
    LCD_WriteCmdData(0x0D);             // p6   VP50[4:0]
    LCD_WriteCmdData(0x59);             // p7   VP43[6:0]
    LCD_WriteCmdData(0xA8);             // p8   VP36[3:0]   VP27[3:0]
    LCD_WriteCmdData(0x44);             // p9   VP20[6:0]
    LCD_WriteCmdData(0x18);             // p10  VP13[4:0]
    LCD_WriteCmdData(0x1F);             // p11  VP6[5:0]
    LCD_WriteCmdData(0x10);             // p12  VP4[5:0]
    LCD_WriteCmdData(0x07);             // p13  VP2[5:0]
    LCD_WriteCmdData(0x02);             // p14  VP1[5:0]
    LCD_WriteCmdData(0x00);             // p15  VP0[5:0]
    
    LCD_WriteCmd(ILI9163C_GMCTRN1);     // Negative Gamma correction
    LCD_WriteCmdData(0x00);             // p1   VN0[5:0] 
    LCD_WriteCmdData(0x0E);             // p2   VN1[5:0] 
    LCD_WriteCmdData(0x12);             // p3   VN2[5:0]
    LCD_WriteCmdData(0x10);             // p4   VN4[5:0]
    LCD_WriteCmdData(0x17);             // p5   VN6[5:0]
    LCD_WriteCmdData(0x12);             // p6   VN13[4:0]
    LCD_WriteCmdData(0x26);             // p7   VN20[6:0]
    LCD_WriteCmdData(0x57);             // p8   VN36[3:0]   VN27[3:0]
    LCD_WriteCmdData(0x3B);             // p9   VN43[6:0]
    LCD_WriteCmdData(0x07);             // p10  VN50[4:0]
    LCD_WriteCmdData(0x20);             // p11  VN57[5:0]
    LCD_WriteCmdData(0x2F);             // p12  VN59[5:0]
    LCD_WriteCmdData(0x38);             // p13  VN61[5:0]
    LCD_WriteCmdData(0x3D);             // p14  VN62[5:0]       
    LCD_WriteCmdData(0x3f);             // p15  VN63[5:0]
    
    LCD_WriteCmd(ILI9163C_DISPON);      // Display On
    LCD_WriteCmd(ILI9163C_RAMWR);       // Memory Write  
    
    //LCD_BACKLIGHT_LAT = 1;
    
    //lcdDeselect();
}



void LCD_WriteData(uint8_t dataHighByte, uint8_t dataLowByte)
{
    /*TFT_DC_LAT   = 1;               // DC = 1 = data
    
    DATABUS_LATD = dataHighByte;
    TFT_WR_LAT   = 0;
    TFT_WR_LAT   = 1;
    
    DATABUS_LATD = dataLowByte;
    TFT_WR_LAT   = 0;
    TFT_WR_LAT   = 1;*/
    
    LCD_WriteCmdData(dataHighByte);
    LCD_WriteCmdData(dataLowByte);
}

void LCD_WriteData16bits(uint16_t data)
{
    uint8_t highByte, lowByte;
    highByte = (uint8_t)(data>>8);
    lowByte  = (uint8_t)data;
    LCD_WriteData(highByte, lowByte);
}

void LCD_SetPosition(uint8_t x0, uint8_t x1, uint16_t y0, uint16_t y1)
{
    LCD_WriteCmd(ILI9163C_CASET);       // column address set
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(x0);               // start x
    LCD_WriteCmdData(0x00);
    LCD_WriteCmdData(x1);               // end x
    
    LCD_WriteCmd(ILI9163C_PASET);       // row address set
    LCD_WriteCmdData(y0 >> 8);          // start y
    LCD_WriteCmdData(y0);
    LCD_WriteCmdData(y1 >> 8);          // end y
    LCD_WriteCmdData(y1);
    
    LCD_WriteCmd(ILI9163C_RAMWR);       // write to ram
}

void LCD_ClearScreen(uint16_t bColor)
{
    uint16_t column, row;
    LCD_SetPosition(ORGIN, MAX_WIDTH, ORGIN, MAX_HEIGHT);
    for(row = 0; row < DISPLAY_HEIGHT; row++)
    {
        for(column = 0; column < DISPLAY_WIDTH; column++)
        {
            LCD_WriteData16bits(bColor);
        }
    }
}

void LCD_InvertDisplay(bool invert)
{
    LCD_WriteCmd(invert ? ILI9163C_INVON : ILI9163C_INVOFF);
}

// required control bits for rotating the display
#define MADCTL_MY       0x80
#define MADCTL_MX       0x40
#define MADCTL_MV       0x20
#define MADCTL_ML       0x10
#define MADCTL_RGB      0x00
#define MADCTL_BGR      0x08
#define MADCTL_MH       0x04

// don't know if I should provide a rotate function because x and y would need
// to be maintained as the display is rotate
void LCD_SetRotation(uint8_t rotate)
{
    LCD_WriteCmd(ILI9163C_MADCTL);
    rotate = rotate % 4;        // 0 - 3 only
    switch(rotate)
    {
    case 0:
        break;
    case 1:
        break;
    case 3:
        break;
    default:                    // no change
        break;
    }
    
}

// this is just for diagnostics - used for POST
void LCD_RGBGrayTest(void)
{
    uint16_t  A, B, C;
    uint16_t  i, j, k, DH;
    
    LCD_SetPosition(ORGIN, MAX_WIDTH, ORGIN, MAX_HEIGHT);   //160x128
    
    for(k=0;k<40;k++)
    {   
        A=0;
    	B=0;
    	C=0;
        for(i=0;i<32;i++)
	{    
            for(j=0;j<4;j++)
            {
     		DH=(A<<11)+(B<<5)+C;
     		LCD_WriteData16bits(DH);
            }
            A=A+1;
            B=B+2;
            C=C+1;
  	}
    }

    for(k=0;k<40;k++)
    {   
    	A=0;
    	B=0;
    	C=0;
        for(i=0;i<32;i++)
	{    
            for(j=0;j<4;j++)
            {
     		DH=(A<<11)+B+C;
     		LCD_WriteData16bits(DH);
            }
            A=A+1;
        }
    }

    for(k=0;k<40;k++)
    {   
    	A=0;
    	B=0;
    	C=0;
	for(i=0;i<32;i++)
	{    
            for(j=0;j<4;j++)
            {
     		DH=A+(B<<5)+C;
     		LCD_WriteData16bits(DH);
            }
            B=B+2;
        }
    }

    for(k=0;k<40;k++)
    {   
        A=0;
        B=0;
        C=0;
	for(i=0;i<32;i++)
	{    
            for(j=0;j<4;j++)
            {
     		DH=A+B+C;
     		LCD_WriteData16bits(DH);
            }
            C=C+1;
  	}
    }
}