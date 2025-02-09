/*
 * File:   main.c
 * Author: SulaimanNiazi
 *
 * Created on February 6, 2025, 6:26 PM
 */

//Defining ports and pins

#define LCDdataPort     PORTB
#define LCDdataPortDIR  TRISB
#define Epin            PORTDbits.RD0
#define EpinDIR         TRISDbits.TRISD0
#define RSpin           PORTDbits.RD1
#define RSpinDIR        TRISDbits.TRISD1
#define RWpin           PORTDbits.RD2
#define RWpinDIR        TRISDbits.TRISD2
#define indicatorLEDDIR TRISCbits.TRISC0
#define indicatorLED    PORTCbits.RC0
#define itemSensorDIR   TRISCbits.TRISC2
#define itemSensor      PORTCbits.RC2
#define clearCounterDIR TRISCbits.TRISC1
#define clearCounter    PORTCbits.RC1

//Header files

#define _XTAL_FREQ 20000000
#include<xc.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

//declaring global variables

unsigned int count = 0;

//functions

void toggleEnable(){
    Epin = 1;
    __delay_us(10);
    Epin = 0;
    __delay_ms(10);
}
void sendCommand(uint8_t command){
    RSpin = 0;
    RWpin = 0;
    LCDdataPort = command;
    toggleEnable();
}
void LCDdisplay(uint8_t line[]){
    RSpin = 1;
    RWpin = 0;
    unsigned int lineLength = strlen((char*)line) + 1;
    for(unsigned int ind = 0; ind < lineLength; ind++){
        LCDdataPort = line[ind];
        toggleEnable();
    }
}
void selectRow(int row){
    switch(row){
        case 1: sendCommand(0x80); break;
        case 2: sendCommand(0xc0); break;
    }
}
void main(){
//Initialization
    
    indicatorLEDDIR = 0;
    indicatorLED = 0;
    clearCounterDIR = 1;
    T1CON = 0x01;           //timer 1 turned on
    
//CCP initialization
    
    CCP1CON = 0x05;         //capture mode every rising edge
    PIE1bits.CCP1IE = 1;
    PIR1bits.CCP1IF = 0;
    INTCONbits.PEIE = 1;    //enable all peripheral interrupts
    INTCONbits.GIE = 1;     //enable the main interrupt
    
    itemSensorDIR = 1;
    
//LCD initialization
    
    LCDdataPortDIR = 0x00;
    EpinDIR = 0;
    RSpinDIR = 0;
    RWpinDIR = 0;
    for(int x = 0; x < 3; x++){
        __delay_ms(100);
        sendCommand(0x30);
    }
    __delay_ms(100);
    sendCommand(0x38);
    sendCommand(0x08);
    sendCommand(0x01);
    sendCommand(0x06);
    sendCommand(0x0F);
    
//Declaring local variables
    
    uint8_t line[16];

    while(1){
        indicatorLED = itemSensor;
        if(clearCounter){
            count = 0;
        }
        selectRow(1);
        line[0]='\0';
        sprintf((char*)line,"Count: %d",count);
        LCDdisplay(line);
    }
}

void __interrupt()isr(){
    if(PIR1bits.CCP1IF){
        count++;
        PIR1bits.CCP1IF = 0;
    }
    return;
}
