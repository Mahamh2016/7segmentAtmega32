#include<avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>


int main(void){
    unsigned char arr[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
    unsigned char btnCount=0;
    DDRC=0xff;//output
    DDRD=0xfe;//used for input counting
    PORTD=0x01;//pulling up


  while(1){
    //if btn pressed
    if(PIND & (1<<0)){
      btnCount+=1;//increment counter
      _delay_ms(500);

      if(btnCount>9){
        btnCount=0;
      }

      PORTC=arr[btnCount];
    }
  }
}