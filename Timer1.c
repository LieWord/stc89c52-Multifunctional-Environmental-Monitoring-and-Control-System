#include <REGX52.H>


//定时器1初始化，1.085ms@11.0532MHz
void Timer1_Init()
{
	TMOD&=0xF0;
	TMOD|=0x01;
	TL1=0x18;	
	TH1=0xFC;	
	TF1=0;
	TR1=1;
	ET1=1;
	EA=1;
	PT1=1;
}

/*
//定时器中断函数模板

void Timer1_Routine() interrupt 3
{
	static unsigned int T1Count;
	TL1 = 0x18;		
	TH1 = 0xFC;		
	T1Count++;
	if(T1Count>=1000)
	{
		T1Count=0;
		
	}
}
*/