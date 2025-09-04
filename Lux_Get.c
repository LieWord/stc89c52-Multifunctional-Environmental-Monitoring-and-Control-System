#include <REGX52.H>
#include <XPT2046.h>
#include <LCD1602.h>
#include <Delay.h>


extern unsigned char ADValue;


unsigned char Lux_Get()
{
	    unsigned char ADV;
		//LCD_ShowString(1,1,"ADJ  NTC  RG");
		//ADValue=XPT2406_ReadAD(XPT2046_XP_8);
		//LCD_ShowNum(2,1,ADValue,3);
		//Delay(5);
		//ADValue=XPT2406_ReadAD(XPT2046_YP_8);
		//LCD_ShowNum(2,6,ADValue,3);		
		//Delay(5);
		ADV=XPT2406_ReadAD(XPT2046_VBAT_8);
		//LCD_ShowNum(2,11,ADValue,3);
		Delay(5);
		return ADV;
}