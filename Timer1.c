#include <REGX52.H>


//��ʱ��1��ʼ����1.085ms@11.0532MHz
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
//��ʱ���жϺ���ģ��

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