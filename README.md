<div id="readme" class="Box-body readme blob js-code-block-container">
  <article class="markdown-body entry-content p-3 p-md-6" itemprop="text"><p><a href="https://www.microchip.com" rel="nofollow"><img src="https://camo.githubusercontent.com/5fb5505f69a28ff407841612dfe2b7004f210594/68747470733a2f2f636c6475702e636f6d2f553071684c7742696a462e706e67" alt="MCHP" data-canonical-src="https://cldup.com/U0qhLwBijF.png" style="max-width:100%;"></a></p>


# Introduction
The PIC16F184xx family has a new Analog to Digital Converter with Computation (ADCC) with a 12-bit resolution. This project shows the reading of a metal detector using the ADCC.

# Description
In this example we will be using the PIC16F18446 Sensor Board. Initially, the board scans the metal detector LC circuit in order to find the peak (resonant) frequency. It then supplies a signal with that frequency using the NCO, and reads the ADCC. If a metal object approaches, it shifts the resonant frequency, and the ADCC value changes. The demo has 2 operating modes. In the first mode, the 12-bit and 10-bit values are plotted in real time.

![Metal Detector](image/display.png)

When entering this mode, the first ADCC reading is used as an offset for the plots. The LCD backlight turns OFF after some time of inactivity, and turns back ON when the user presses a button. In the second mode, the buzzer is beeping at a variable time interval, according to the metal detector reading.

# MCC Settings
Here are the settings used for MSSP, CLC, NCO, FVR, ADCC, CCP, CWG, and TMR. MSSP + CLC are used for the LCD control.

### MSSP Settings
![MSSP Settings](image/MSSP1.png)

### CLC Settings
![CLC1 Settings](image/CLC1.png)

![CLC2 Settings](image/CLC2.png)

### NCO Settings
The NCO is used to oscillate the LC circuit.
![NCO1 Settings](image/NCO1.png)

### FVR Settings
FVR is used as positive reference for the ADCC, to get higher accuracy and gain.
![FVR Settings](image/FVR.png)

### ADCC settings
![ADCC Settings](image/ADCC1.png)
ADRPT register is set to 0x40, to average a burst of 64 samples.
![ADCC Registers](image/ADCC2.png)

### CCP Settings
CCP1 is used for generating the buzzer tone.
![CCP Settings](image/CCP1.png)

### CWG Settings
CWG is used to output the signal from CCP1 in antiphase on 2 pins, so that the buzzer sounds louder.
![CWG Settings](image/CWG1.png)

### TMR Settings
TMR1 is used to clock the CCP1. It sets the pitch of the buzzer tone.  
![TMR Settings](image/TMR1.png)
TMR3 is used to set the beep interval.  
![TMR Settings](image/TMR3.png)
