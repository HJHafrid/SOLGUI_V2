#ifndef SOLGUI_COMMON_H
#define SOLGUI_COMMON_H


//########################���꺯����############################
#define SOLGUI_Fabs(num) (num<0)?-num:num						//����������ʾ������ֵ

//##########################��API��############################
void SOLGUI_Init(void);		//SOLGUI��ʼ��
void SOLGUI_Refresh(void);		//ˢ����Ļ
void SOLGUI_DrawPoint(u32 x,u32 y,u8 t);			//���㣬t=1������t=0Ϩ��.

#endif

