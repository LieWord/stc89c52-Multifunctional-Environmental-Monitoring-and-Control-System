#include <REGX52.H>
#include <LCD1602.h>
#include <Delay.h>
#include <Key.h>
#include <AT2402.h>
#include <XPT2046.h>
#include <Timer0.h>
#include <Timer1.h>
#include <Timer2.h>
#include <Buzzer.h>
#include <Temp_Warn.h>
#include <MOTOR_Monitor.h>
#include <Menu.h>
#include <Lux_Get.h>



sbit ENA = P1^6;  
sbit IN1 = P1^4;  
sbit IN2 = P1^5;

sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DIN=P3^4;
sbit XPT2046_DOUT=P3^7;

const char* g_Messages[] = {
    "Warning Tem Set ",
    "Warning Lux Set ",
    "Motor_Speed Set ",   
	"Auto Motor Mode ",
	"                ",
};  

const unsigned int g_MessageCount=sizeof(g_Messages)/sizeof(g_Messages[0]);
  
char  Compare=3;
unsigned char Key_Num;
unsigned char Lux;
unsigned char ADValue;
unsigned char auto_mode=0;
unsigned char Menu_Syb=2;
unsigned char Open_Motor=0;

extern float NowTem;
extern unsigned char Warning_TNum;
extern unsigned int Warning_LHNum;
extern unsigned int Warning_LLNum;
extern unsigned char Buzzer_Flag;
extern unsigned char Motor_Flag;
extern unsigned char Motor_Start;



void main()
{		
	LCD_Init();	
	Show_Menu_Start_Init();        //功能初始化开始
	Delay(3000);
	MOTOR_Monitor_Init();
 	Timer1_Init();
	//Timer2_Init();	
	
	DS18B20_ConvertT();
	Delay(1000);	
	Temp_Set(27);
	Motor_Start=0;	              //初始状态电机禁用

	Show_Menu_End_Init();          //功能初始化完成
	while(1)
	{	
		Temp_Monitor();            //温度检测
		Key_Num=Key();             //键码获取

		Motor_Flag=Buzzer_Flag;
		MOTOR_Monitor();           //电机控制
		Lux=Lux_Get();		
	
		if(Key_Num==4)
		{
			if(Menu_Syb==1)
			{
				LCD_ShowString(1,1,"                ");	
				LCD_ShowString(2,1,"                ");	
				LCD_ShowString(1,1,g_Messages[0]);
				LCD_ShowString(2,1,g_Messages[1]);
				Show_Menu_Function();      //功能展示
				Menu_Syb=2;
			}		
			if(Menu_Syb==2)
			{
				LCD_ShowString(1,1,"                ");	
				LCD_ShowString(2,1,"                ");	
				LCD_ShowString(1,1,"Now Temp:");
				LCD_ShowString(2,1,"Now Lux :");
				LCD_ShowNum(1,11,NowTem,3);
				LCD_ShowNum(2,11,Lux,3);
				Menu_Syb=1;
			}
		}
		//Key_Num=Key(); 	
		LCD_ShowString(1,1,"Now Temp:");
		LCD_ShowString(2,1,"Now Lux :");
		LCD_ShowNum(1,11,NowTem,3);
		LCD_ShowNum(2,11,Lux,3);
		Menu_Syb=1;
		/*if(Key_Num==3)
		{
			Open_Motor=~Open_Motor;
		}*/
		//Key_Num=Key(); 	
	}	
}



void Timer1_Routine() interrupt 3
{		
	
	static unsigned int T1Count,T2Count,T3Count;
	TL1 = 0x18;		
	TH1 = 0xFC;		
	T1Count++;
	T2Count++;
	if(T2Count>20)                                        //定时器扫描键码
	{
		Key_Loop();
		T2Count=0;
	}
	if(T1Count>=1000 && Buzzer_Flag==1 && Motor_Start==0 && Open_Motor==0)//蜂鸣器满足条件后开始报警
	{
		T1Count=0;
		Buzzer_tms(50);
	}	
	T3Count++;
	if(T3Count>20)                                        //产生PWM波

	{
		static unsigned char Counter;
		Counter++;
		Counter%=10;
		if(Counter<Compare  &&	Motor_Flag==1 && Motor_Start==1)
			{
				ENA=1;
			}
		else if (Counter<Compare && Open_Motor)
		{
				ENA=1;
		}
		else
			{
				ENA=0;
			}		
		T3Count=0;
	}
	if(Key_Num==3)
	{
		Open_Motor=~Open_Motor;
	}	
}

/*
void Timer2_Routine() interrupt 5
{
	TL2=0xA4;		
	TH2=0xFF;
	
}

*/