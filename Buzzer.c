#include <REGX52.H>
#include <INTRINS.H>
#include "Delay.h"
sbit Buzzer=P2^5;


void Buzzer_Delay500us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	i = 227;
	while (--i);
}

void Buzzer_tms(unsigned int tms)		//@12.000MHz
{
	unsigned int i;
			for(i=0;i<tms*2;i++){
			Buzzer=!Buzzer;
			Buzzer_Delay500us();
			//Delay(1);
			}
}

