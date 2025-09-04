#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Key.h"

extern const char* g_Messages[];

extern  char Compare;
extern unsigned char Key_Num;
extern unsigned char auto_mode;
extern unsigned char Warning_TNum;
extern  unsigned int Warning_LHNum;
extern  unsigned int Warning_LLNum;
extern unsigned char Motor_Start;

unsigned char cycle=0;

void Show_Menu_Start_Init()
{
	LCD_ShowString(1,1,"   ENV SYSTEM   ");
	LCD_ShowString(2,1,"Function Loading");
}

void Show_Menu_End_Init()
{
	unsigned char i=0;
	LCD_ShowString(2,1,"                ");
	for(i=0;i<8;i++)
	{
		LCD_ShowChar(2,1+i,0x29);
		LCD_ShowChar(2,16-i,0x28);
		Delay(150);
	}

	Delay(200);
	LCD_ShowString(1,1,"                ");
	LCD_ShowString(1,1,"    WELCOME!    ");
	Delay(3000);
	LCD_ShowString(1,1,"                ");
	LCD_ShowString(2,1,"                ");
}


void Show_Menu_Function()
{
	static char i=0;
	Key_Num=Key(); 
	while(Key_Num!=4)
	{
		if(Key_Num)
		{
			if(Key_Num==2)
			{		
				i++;
				if(i>3)i=0;
				
				LCD_ShowString(1,1,g_Messages[i]);
				LCD_ShowString(2,1,g_Messages[i+1]);

			}		
			if(Key_Num==1)
			{			
				i--;
				if(i<0)i=0;
				
				LCD_ShowString(1,1,g_Messages[i]);
				LCD_ShowString(2,1,g_Messages[i+1]);

			}
			if(Key_Num==3)
			{
		
				if(i==0)
				{
					LCD_ShowString(1,1,"                ");
					LCD_ShowString(2,1,"                ");
					LCD_ShowString(1,1,"Now Warning Temp");
					LCD_ShowString(2,1,"-");
					LCD_ShowString(2,16,"+");
					LCD_ShowNum(2,8,Warning_TNum,2);
					cycle=1;
					while(cycle)
					{
						Key_Num=Key();
						if(Key_Num==1)
						{
							Warning_TNum--;
							LCD_ShowNum(2,8,Warning_TNum,2);
							if(Warning_TNum<10)Warning_TNum=10;
						}					
						if(Key_Num==2)
						{
							Warning_TNum++;
							LCD_ShowNum(2,8,Warning_TNum,2);
							if(Warning_TNum>30)Warning_TNum=30;
						}
						if(Key_Num==3)
						{
							cycle=0;
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(2,1,"                 ");
							LCD_ShowString(1,1,"  Set  Success!  ");
							Delay(50);
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(1,1,g_Messages[i]);
							LCD_ShowString(2,1,g_Messages[i+1]);
						}
					}			
				}			
				if(i==1)
				{
					LCD_ShowString(1,1,"                ");
					LCD_ShowString(2,1,"                ");
					LCD_ShowString(1,1,"Now Warning Lux ");
					LCD_ShowString(2,1,"-");
					LCD_ShowString(2,16,"+");
					LCD_ShowNum(2,10,Warning_LHNum,3);
					LCD_ShowNum(2,5,Warning_LLNum,3);
					cycle=1;
					while(cycle)
					{
						Key_Num=Key();
						if(Key_Num==1)
						{
							Warning_LLNum--;
							if(Warning_LLNum<10)Warning_LLNum=100;
							if(Warning_LLNum>Warning_LHNum)Warning_LLNum=Warning_LHNum;
							LCD_ShowNum(2,5,Warning_LLNum,3);
						}					
						if(Key_Num==2)
						{
							Warning_LHNum++;	
							if(Warning_LHNum>300)Warning_LHNum=100;
							if(Warning_LHNum<Warning_LLNum)Warning_LHNum=Warning_LLNum;
							LCD_ShowNum(2,10,Warning_LHNum,3);
						}
						if(Key_Num==3)
						{
							cycle=0;
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(2,1,"                 ");
							LCD_ShowString(1,1,"  Set  Success!  ");
							Delay(50);
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(1,1,g_Messages[i]);
							LCD_ShowString(2,1,g_Messages[i+1]);
						}
					}			
				}	
				if(i==2)
				{
					LCD_ShowString(1,1,"                ");
					LCD_ShowString(2,1,"                ");
					LCD_ShowString(1,1,"Now Motor Speed ");
					LCD_ShowString(2,1,"-");
					LCD_ShowString(2,16,"+");
					LCD_ShowNum(2,8,Compare,2);
					cycle=1;
					while(cycle)
					{
						Key_Num=Key();
						if(Key_Num==1)
						{
							Compare--;
							LCD_ShowNum(2,8,Compare,2);
							if(Compare<0)Compare=0;
						}					
						if(Key_Num==2)
						{
							Compare++;
							LCD_ShowNum(2,8,Compare,2);
							if(Compare>10)Compare=10;
						}
						if(Key_Num==3)
						{
							cycle=0;
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(2,1,"                 ");
							LCD_ShowString(1,1,"  Set  Success!  ");
							Delay(50);
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(1,1,g_Messages[i]);
							LCD_ShowString(2,1,g_Messages[i+1]);
						}
					}			
				}				
				if(i==3)
				{
					LCD_ShowString(1,1,"                ");
					LCD_ShowString(2,1,"                ");
					LCD_ShowString(1,1,"Now  Motor  Mode");
					//LCD_ShowString(2,1,"Y");
					//LCD_ShowString(2,16,"N");
					//LCD_ShowNum(2,8,Warning_LNum,2);
					cycle=1;
					while(cycle)
					{
						Key_Num=Key();
						if(Key_Num==1)
						{
							LCD_ShowString(2,1,"Y");
							Delay(1000);
							LCD_ShowString(2,1," ");							
							Motor_Start=1;
						}					
						if(Key_Num==2)
						{
							LCD_ShowString(2,16,"N");
							Delay(1000);
							LCD_ShowString(2,16," ");	
							Motor_Start=0;
						}
						if(Key_Num==3)
						{
							cycle=0;
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(2,1,"                 ");
							LCD_ShowString(1,1,"  Set  Success!  ");
							Delay(50);
							LCD_ShowString(1,1,"                 ");
							LCD_ShowString(1,1,g_Messages[i]);
							LCD_ShowString(2,1,g_Messages[i+1]);
						}
					}					
				}				
			}
		}
		Key_Num=Key(); 
	}
	LCD_ShowString(1,1,"                ");	
	LCD_ShowString(2,1,"                ");	
}