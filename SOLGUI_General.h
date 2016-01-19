#ifndef SOLGUI_GENERAL_H
#define SOLGUI_GENERAL_H

//##############################��������##############################
#define X_WIDTH         128		//X���س�
#define Y_WIDTH         64		//Y���س�
#define Y_PAGE			8		//Y����ҳ����

#define SOLGUI_Fabs(num) (num<0)?-num:num						//����������ʾ������ֵ	

//###########################���ڲ���##############################
char SOLGUI_Find_Max(char input[],char num); 					//���������ֵ
char SOLGUI_Find_Min(char input[],char num); 					//���������ֵ
void SOLGUI_Graph_Wave_Init(void);								//����RAM��ʼ��
void SOLGUI_Show_Char(unsigned char x,unsigned char y,unsigned char ch,unsigned char mode);	 
void SOLGUI_Show_String(unsigned char x,unsigned char y,unsigned char *str,unsigned char mode);	

//##############################��API��##############################

/*----------------------------
��Ļ�ϵ�����꣺�����½�Ϊ��㣩
	x��0~127
	y��0~63
----------------------------*/

//----------������������
void SOLGUI_Init(void);	 		//��ʾ��ǿģ���ʼ��
void SOLGUI_Refresh_GRAM(void);	//ˢ��GRAM																	

//----------���ַ���ʾ��
void SOLGUI_printf(unsigned char x,unsigned char y,unsigned char mode,const unsigned char* str,...);//��ʽ���������Ļ��(x,y)��ʾ���꣬mode=1������mode=0���ף�
/*-------------------------------------------------------------------
����ʽ�������
�˴���printf������PC��printf��һ���Ӽ�
��˸�ʽ�÷���PC��prinfһ����

0x01:��ʽ����
	%s,%S:�ַ���
	%c,%C:�����ַ�

	%f,%F:double��������ÿ����ʽ���ַ���ֻ����һ����Ĭ����3λС����

	%b,%B:���Ͷ�����
	%o,%O:���Ͱ˽���
	%d,%D:����ʮ���ƣ�����������
	%u,%U:����ʮ���ƣ�����������
	%x,%X:����ʮ������

0x02:������ֻ�������֣�
	
	%07d�����㣨������С��ʾ����7�񣬲�������0��ǰ�油�룩
	%-7d������루������С��ʾ����7�񣬲������ÿո��ں��油�룩
	%.4f: ����С��λ��������4λС������ౣ��7λ��

-------------------------------------------------------------------*/

//----------��ͼ����ʾ��
void SOLGUI_DrawPoint(unsigned char x,unsigned char y,unsigned char t);	//���㣬t=1������t=0Ϩ��.

void SOLGUI_Graph_line(		unsigned char x0,unsigned char y0,		 //����	��mode��0�����ߣ�1ʵ�ߣ�2���ߣ�3�̻��ߣ�
							unsigned char xEnd,unsigned char yEnd,
							unsigned char mode
							);

void SOLGUI_Graph_Circle(	unsigned char x0,unsigned char y0,		//��Բ��Բ�ģ��뾶��1����0Ϩ��
							unsigned char r,
							unsigned char mode
							);			

void SOLGUI_Graph_pictrue( 	unsigned char x,			//���x����	 		//ͼƬ(ͼ��ľ���������Ͻ�)
							unsigned char y,			//���y����
							unsigned char x_len,		//ͼ�γ�
							unsigned char y_len,		//ͼ�ο�
							unsigned char *pic,			//ͼ(ת��Ϊһά����)
							unsigned char mode 			//��ʾ��ʽ��1������ʾ��0������ʾ
							);
/*---------------------------------------------------------------------------------------------
��ע�⣡����ͼƬӦ����Ϊ1ά���飬ȡģ��ʽ����ʽ������ˮƽ���ֽڴ�ֱ�������ң����ϵ���ɨ�衿
---------------------------------------------------------------------------------------------*/

//----------��ͼ����ʾ��
							
void SOLGUI_Plot_Bar(			unsigned char x,			//���x����	 	//��ֵ��(��ʾ��ֵ��Դ�С)
								unsigned char y,			//���y����
								unsigned char x_len,		//ͼ�γ�
								unsigned char y_len,		//ͼ�ο�
								int graduated_max,			//������ֵ
								int graduated_min,			//�����Сֵ
								int Var_in,					//ֵ����
								unsigned char mode 			//��ʽ��0�������1ƽ����
);

void SOLGUI_Plot_Oscillogram(	unsigned char x,			//���x����	 //����ͼ
								unsigned char y,			//���y����
								unsigned char x_len,		//ͼ�γ�
								unsigned char y_len,		//ͼ�ο�
								int graduated_max,			//�ϱ��
								int graduated_min,			//�±�ߣ�������bug��
								unsigned char dis_num,		//Ҫ��ʾ�����ݸ���
								int wave_in[]				//��������
								);

void SOLGUI_Plot_Waveform(		unsigned char x,			//���x����	 //����ͼ��(��ʾ��ֵʱ�򲨶�)
								unsigned char y,			//���y����
								unsigned char x_len,		//ͼ�γ�
								unsigned char y_len,		//ͼ�ο�
								int graduated_max,			//������ֵ
								int graduated_min,			//�����Сֵ��������bug��
								unsigned char channel,		//ʹ��ͨ��(1,2)
								int Var_in					//����ʾ���εı���
								);
	
	

#endif
