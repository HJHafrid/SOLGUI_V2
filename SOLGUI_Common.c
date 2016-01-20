#include"SOLGUI_Include.h"
#include"SOLGUI_Hardware.h"
#include<string.h>

//##########################���������塿############################
/************GRAM����************/
unsigned char SOLGUI_GRAM[SCREEN_X_WIDTH][SCREEN_Y_PAGE];

//##########################��SOLGUI���ú�����############################

void SOLGUI_Init(void) 		//SOLGUI��ʼ��
{
	SOLGUI_Hardware_Init();
	memset(SOLGUI_GRAM,0,sizeof(SOLGUI_GRAM));			//��ʼ����GRAM���㣬��ֹ����
}

void SOLGUI_Refresh(void)		//ˢ����Ļ
{
	SOLGUI_Hardware_FillScreen(SOLGUI_GRAM);
	memset(SOLGUI_GRAM,0,sizeof(SOLGUI_GRAM));			//GRAM����
}

void SOLGUI_DrawPoint(u8 x,u8 y,u8 t)			//���㣬t=1������t=0Ϩ��.
{
	unsigned char pos,bx,temp=0;
	if(x>=(SCREEN_X_WIDTH)||y>=(SCREEN_Y_WIDTH))	//0~127
	{
		return;//������Χ��.
	}
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)
	{
		SOLGUI_GRAM[x][pos]|=temp;
	}
	else 
	{
		SOLGUI_GRAM[x][pos]&=~temp;
	}

}



