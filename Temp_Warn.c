#include <REGX52.H>
#include <LCD1602.h>
#include <DS18B20.h>
#include <Delay.h>
#include <LCD1602.h>
#include <Key.h>

float NowTem;
unsigned char Buzzer_Flag;
unsigned char Motor_Flag;
unsigned char Motor_Start;
unsigned char Warning_TNum;
unsigned int Warning_LHNum=250;
unsigned int Warning_LLNum=50;

extern unsigned char Lux;
extern unsigned char auto_mode;
extern unsigned char Key_Num;

void Temp_Monitor()
{
		DS18B20_ConvertT();
		NowTem=DS18B20_ReadT();
		//LCD_ShowNum(1,1,NowTem,3);
		//Ð¡ÊýÏÔÊ¾
		//LCD_ShowChar(2,5,'.');		
		//LCD_ShowNum(2,6,(unsigned long)(NowTem*10000)%10000,4);		
		if(NowTem>=Warning_TNum)
		{
			Buzzer_Flag=1;
			Motor_Flag=1;
			LCD_ShowString(1,15,"OT");
			Key_Num=Key();
		}
		else
		{
			Buzzer_Flag=0;
			Motor_Flag=0;
			Motor_Start=0;
			LCD_ShowString(1,15,"  ");
		}
		
		if(Lux>Warning_LHNum)
		{
			LCD_ShowString(2,15,"HL");
		}
					
		else if(Lux<Warning_LLNum)
		{
			LCD_ShowString(2,15,"LL");

		}
		else
		{
			LCD_ShowString(2,15,"  ");
		}
}

void Temp_Set(unsigned char Warning)
{
	Warning_TNum=Warning;
}