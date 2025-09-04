#include <REGX52.H>

sbit I2C_SCL = P2^1;
sbit I2C_SDA = P2^0;


//����I2C��ʼ�ź�
void I2C_Start()
{
	I2C_SDA=1;
	I2C_SCL=1;
	I2C_SDA=0;
	I2C_SCL=0;
}

//����I2Cֹͣ�ź�
void I2C_Stop()
{
	I2C_SDA=0;
	I2C_SCL=1;
	I2C_SDA=1;
}
/*
//I2C����һ���ֽ�,����ֵΪ0���ͳɹ�
bit I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>i);//�����λ����
		I2C_SCL=1;
		I2C_SCL=0;
	}
	I2C_SDA=1;
	I2C_SCL=1;
	i=I2C_SDA;
	I2C_SCL=0;
	
	return i;
}
//I2C����һ���ֽڣ���ack=0Ϊ����Ӧ��
unsigned char I2C_ReceiveByte(bit ack)
{
	unsigned char i;
	unsigned char Byte=0x00;
	I2C_SDA=1;
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA)Byte|=(0x80>i);
		I2C_SCL=0;	
	}
	I2C_SDA=ack;
	I2C_SCL=1;
	I2C_SCL=0;
	return Byte;
}
*/
void I2C_SendByte(unsigned char Byte)
{
	unsigned char i;
	for(i=0;i<8;i++)
	{
		I2C_SDA=Byte&(0x80>>i);
		I2C_SCL=1;
		I2C_SCL=0;
	}
}

unsigned char I2C_ReceiveByte(void)
{
	unsigned char i,Byte=0x00;
	I2C_SDA=1;
	for(i=0;i<8;i++)
	{
		I2C_SCL=1;
		if(I2C_SDA){Byte|=(0x80>>i);}
		I2C_SCL=0;
	}
	return Byte;
}

void I2C_SendAck(unsigned char AckBit)
{
	I2C_SDA=AckBit;
	I2C_SCL=1;
	I2C_SCL=0;
}

unsigned char I2C_ReceiveAck(void)
{
	unsigned char AckBit;
	I2C_SDA=1;
	I2C_SCL=1;
	AckBit=I2C_SDA;
	I2C_SCL=0;
	return AckBit;
}
