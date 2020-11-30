#include<avr/io.h>
#include<util/delay.h>
//#include<avr/interrupt.h>
#include "lcd.h"

int i;
//volatile unsigned char j;

void main()
{
	DDRD&=~(1<<2);
	PORTD|=(1<<2);
	DDRD&=~(1<<3);
	PORTD|=(1<<3);
	//init_interrupt();
	InitLCD(0);
	LCDClear();
	LCDWriteString("Intruupt process");
	_delay_ms(500);
	LCDClear();
	//sei();
	while(1)
    {
	//int i=0;
	if((!(PIND&4))&&(PIND&8))
    {
	i=i+1;
	LCDWriteIntXY(0,1,i,3);
	_delay_ms(200);
    }
	else if((PIND&4)&&(!(PIND&8)))
    {
	i=i-1;
	LCDWriteIntXY(0,1,i,3);
	_delay_ms(200);
	}
 	else if(i<0)
	{
	i=0;
	LCDWriteIntXY(0,1,i,3);
	_delay_ms(200);
	}
   
	
}
}
