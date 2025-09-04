#include <REGX52.H>

unsigned char Key_Temp;
	
unsigned char Key()
{
	unsigned char temp=0;
	temp=Key_Temp;
	Key_Temp=0;
	return temp;
}

unsigned char Key_GetState()
{
	unsigned char KeyNumber=0;
	
	if(P3_1==0)KeyNumber=1;
	if(P3_0==0)KeyNumber=2;
	if(P3_2==0)KeyNumber=3;
	if(P3_3==0)KeyNumber=4;
	
	return KeyNumber;
}

void Key_Loop()
{
	static unsigned char NowState,LastState;
	LastState=NowState;
	NowState=Key_GetState();
	
	if(NowState==1 && LastState==0)
	{
		Key_Temp=1;
	}	
	if(NowState==2 && LastState==0)
	{
		Key_Temp=2;
	}	
	if(NowState==3 && LastState==0)
	{
		Key_Temp=3;
	}	
	if(NowState==4 && LastState==0)
	{
		Key_Temp=4;
	}
}