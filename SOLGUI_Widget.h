#ifndef SOLGUI_WIDGET_H


//##################################��mode�궨�塿########################################

//------------��SPIN�ؼ���
#define INTEGRAL	0x00	//������		
#define DECIMAL		0x01	//С���� 	

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
void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page);						//ҳ����ת�ؼ�
void SOLGUI_Widget_Spin(u8 USN,u8 type,const u8 *name,double max,double min,void* value);	//������ť�ؼ�
//---------------������ʽ�ؼ���
void SOLGUI_Widget_Bar(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value,u8 mode);		//��



#endif
