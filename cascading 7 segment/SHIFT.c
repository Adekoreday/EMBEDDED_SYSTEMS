
#include "config.h"
#include <stdio.h>
#include <stdlib.h>



#define CLK PORTDbits.RD0
#define DATA PORTDbits.RD1
#define LATCH PORTDbits.RD2


unsigned char const SEGMENT_COMMONC[10] = {0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned char const SEGMENT_COMMONA[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void clock(){
    CLK =1;
    __delay_ms(1);
    CLK = 0;
    __delay_ms(1);
    

}

void Latch(){

    LATCH =1;
    __delay_ms(1);
    LATCH = 0;
    __delay_ms(1);
}

void Serial_write(char value){
    
    char bitsent;   
    for(char i=0;i<8;i++){
    
     bitsent = (value << i) & 0x80 ? 1 : 0;
        
      DATA = bitsent;
     clock();
    }
  //  Latch();
 
}
//for common  anode
char Seven_Segment(char x){
      return SEGMENT_COMMONA[x];
    
}

// the display function for 3 digit seven segment display...........
void display(int number,char displayno){
    char myarray[10];
    char val;
    char i=0;
    char data=0;
    while(number){
        val = number % 10;
        myarray[i]= val;
        ++i;
        number = (number/10);
    }
        for (int j=i;j<displayno;j++){
            myarray[j]=0;
        }
    for (int k=0;k<displayno;k++){
        data = Seven_Segment(myarray[k]);
            Serial_write(data);
    }
    // AFTER WRITING EVERY THING LATCH ONCE
    Latch();

}




void main(void){
    TRISD = 0x00;
    PORTD = 0x00;
    while(1){
        for(int x=0;x<500;x++){
     display(x,4);
    }
    }
}

