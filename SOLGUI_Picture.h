#ifndef SOLGUI_PICTURE_H
#define SOLGUI_PICTURE_H

//##########################��mode������############################

#define	NORMAL	0x01	//������ʾ
#define	REVERSE	0x00	//������ʾ

//##########################��API��############################
void SOLGUI_Pictrue(u32 x,u32 y,const u8 *pic,u32 x_len,u32 y_len,u8 mode);		//��ɫͼƬ��ʾ��mode��0���ף�1������
//Ӧ����Ϊ1ά���飬ȡģ��ʽ����ʽ������ˮƽ���ֽڴ�ֱ�������ң����ϵ���ɨ��


#endif

