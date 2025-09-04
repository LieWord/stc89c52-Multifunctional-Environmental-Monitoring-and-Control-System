#include <REGX52.H>
#include <LCD1602.h>

sbit ENA = P1^6;  
sbit IN1 = P1^4;  
sbit IN2 = P1^5;

extern unsigned char Key_Num;
extern char Compare;

void MOTOR_Monitor_Init()
{
	IN2=1;  
	IN2=0;  
	IN1=1;
	//IN1=0;
	ENA=1;
	ENA=0;
}

void MOTOR_Monitor()
{
		/*if(Key_Num)
	{
		if(Key_Num==1)
		{
			Compare++;
			if(Compare>8)Compare=8;
		}			
		if(Key_Num==2)
		{
			Compare--;
			if(Compare<0)Compare=0;
		}			
	}*/
}