#include <REGX52.H>


//��ʱ��1��ʼ����1.085ms@11.0532MHz
void Timer2_Init()
{
	T2CON = 0x00;
	TL2=0xA4;	
	TH2=0xFF;
    RCAP2L = 0xA4; 
    RCAP2H = 0xFF; 
	TF2=0;
	TR2=1;
	ET2=1;
	EA=1;
	PT2=0;
}

/*
//��ʱ���жϺ���ģ��

void Timer2_Routine() interrupt 5
{
	TL2=0xA4;		
	TH2=0xFF;	
	Counter++;
	Counter%=100;
	if(Counter<Compare)
	{
		MOTOR=1;
	}
	else
	{
		MOTOR=0;
	}
}
*/