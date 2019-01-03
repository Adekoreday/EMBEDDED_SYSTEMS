

byte clk;
byte latch;
byte data;
byte a;
byte b;
byte OE;

void p10_init(byte Clk1,byte latch1, byte Data1,byte A1,byte B1,byte Oe1){


clk=Clk1;latch=latch1;data=Data1;a=A1;b = B1; OE=Oe1;
pinMode(clk, OUTPUT);pinMode(latch, OUTPUT);pinMode(data, OUTPUT);pinMode(a, OUTPUT);pinMode(b, OUTPUT);

}
void clock(){
    digitalWrite(clk,HIGH);
    __delay_us(500);
    digitalWrite(clk,LOW);
    __delay_us(500);
}

void Latch(){
     digitalWrite(latch,HIGH);
     __delay_us(500);
       digitalWrite(latch,LOW);
}

void Serial_write(byte value){
    
        byte bitsent;
    for(byte i=0;i<8;i++){
    
        bitsent = (value << i) & 0x80 ? 1 : 0;
        
        digitalWrite(data,bitsent);
        clock();
    }
    Latch();
 
}