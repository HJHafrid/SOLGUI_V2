#ifndef SOLGUI_WIDGET_H


//##################################��mode�궨�塿########################################

//------------��SPIN�ؼ���
#define INTEGRAL	0x00	//������		
#define DECIMAL		0x01	//С����

//------------��SWITCH�ؼ���
#define ONxOFF1	  	0x00	//����ʽ
#define ONxOFF2 	0x01	//����ʽ
#define ONxOFF3		0x02	//����ʽ


//------------��BAR�ؼ���
/*---------------------
	mode[0]		��������
	mode[2:1]	�������
---------------------*/
//mode[0]
#define DIREC_X		0x00	//x��������
#define DIREC_Y		0x01	//y��������
//mode[2:1]			 
#define PROGBAR 	0x00	//������
#define SCALEBAR 	0x02	//�̶�





//####################################��API��##########################################
void SOLGUI_Cursor(u8 rowBorder_Top,u8 rowBorder_Bottom,u8 option_num);		//��꣨�ϱ߽��У��±߽��У�ѡ�������
//---------------��ѡ��ʽ�ؼ���
void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page);						//ҳ����ת
void SOLGUI_Widget_Spin(u8 USN,const u8 *name,u8 type,double max,double min,void* value);	//������ť
void SOLGUI_Widget_Text(u8 USN,const u8 *text);								//�ı�
void SOLGUI_Widget_Button(u8 USN,const u8 *name,void (*func)(void));		//����
void SOLGUI_Widget_Switch(u8 USN,const u8 *name,u32 *mem_value,u8 L_shift,u8 mode);	//�������أ�mem_value��һ���ⲿ����ķ���ʧ�Դ洢��������

//---------------������ʽ�ؼ���
void SOLGUI_Widget_Bar(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value,u8 mode);		//��



#endif
