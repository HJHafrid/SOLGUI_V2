#include"SOLGUI_Include.h"

#if MENU_FRAME_EN==1
//##############################���������塿##############################
//-----------��״̬�Ĵ�����
u8 SOLGUI_CSR=0;		//���ƼĴ���
//-----------�����ƫ�Ƽ�������
/*ѡ������������*/
u8 cursor_rel_offset=0;	//�������ӿڵ�ƫ��
u8 viewport_offset=0;	//�ӿڵ�ƫ��
//-----------�����λ�ü��㡿
u8 row_start=0;			//ѡ����ʼ�У�����˶��Ͻ磩
u8 viewport_width=0;	//�ӿڿ��

//-----------��ѡ��ʹ�ܱ�
u8 option_enable_list[OPTIONS_MAX];		//ѡ��ʹ�ܱ�,�˴����ԸĽ�


//-----------��GotoPage�ؼ���
extern MENU_PAGE *current_page;//��ǰҳ��

//################################����꡿##############################
//ѡ��ʽ�ؼ������й����ܲ���
void SOLGUI_Cursor(u8 rowBorder_Top,u8 rowBorder_Bottom,u8 option_num)		//��꣨�ϱ߽��У��±߽��У�ѡ�������	
{
	u8 i=0;
	u8 temp=0;
	u8 cur_key=0;
	u8 cursor_row=0;
	u8 cursor_abs_offset=0;	//���ľ���ƫ��
//--------���������ˡ�
	if(rowBorder_Top<rowBorder_Bottom)		//Ĭ���ϱ߽�����±߽磬���򽻻�
	{
		temp=rowBorder_Top;
		rowBorder_Top=rowBorder_Bottom;
		rowBorder_Bottom=temp;
	}
	row_start=rowBorder_Top;	//����ѡ����ʼ��
	viewport_width=rowBorder_Top-rowBorder_Bottom; //�ӿ���������
	if(option_num<viewport_width) viewport_width=option_num-1;		//ѡ����С���ӿڿ�ȴ���
//--------����ֵ������
	cur_key=SOLGUI_GetCurrentKey();										//��ȡ��ǰȫ�ּ�ֵ
	if(cur_key==SOLGUI_KEY_UP){											//��ǰȫ��Ϊ�ϼ�
		if(cursor_rel_offset>0&&SOLGUI_CSR==0)cursor_rel_offset--;		//������ӿ�������	   	
		else if(viewport_offset>0&&SOLGUI_CSR==0)viewport_offset--;	 	//�ӿ�����	
	}
	else if(cur_key==SOLGUI_KEY_DOWN){								    //��ǰȫ��Ϊ�¼�
		if((cursor_rel_offset<viewport_width)&&SOLGUI_CSR==0)cursor_rel_offset++; //������ӿ�������
		else if((viewport_offset<option_num-viewport_width-1)&&SOLGUI_CSR==0)viewport_offset++;	 //�ӿ�����
	}
//--------����Ļ���ơ�
//---����꡿
	cursor_row=(rowBorder_Top-cursor_rel_offset)*8;	 		//���������ӿڵ�ƫ�ƻ������������
	SOLGUI_printf(0,cursor_row,F6X8,"%c",ICON_CURSOR);		//������
//---����������



//--------���޸�ѡ��ʹ�ܱ�			
	cursor_abs_offset=viewport_offset+cursor_rel_offset;	//���㵱ǰ���ľ���ƫ��
	for(i=0;i<=option_num;i++){
		option_enable_list[i]=(cursor_abs_offset==i)?1:0;	//��дѡ��ʹ�ܱ��ھ���ƫ��λ����Ϊ1������λ��Ϊ0��
	}
}

//##############################��ѡ��ʽ�ؼ���##############################

void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page)		//ҳ����ת�ؼ�
{
	u8 row_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
//--------��������ʾ�С�
	if((USN-viewport_offset)>=0&&(USN-viewport_offset)<=viewport_width)
	{		
		row_disp=row_start-USN+viewport_offset;
		if(option_enable_list[USN]==1)
		{
//--------����ֵ������
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){								
				current_page=page;						//�̰�OK����ת
				cursor_rel_offset=0;					//��չ��ƫ�Ƽ�����
				viewport_offset=0;											
			}					
		}
//--------��ѡ����ơ�
		SOLGUI_printf(6,row_disp*8,F6X8,"%s",page->pageTitle);		//��һ��ҳ�����

//--------��������ʾ���ơ�
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",0x84);			//����ָʾ�����ݼ�ֵ������������д��
	}
}







//##############################������ʽ�ؼ���##############################

void SOLGUI_Widget_Bar(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value,u8 mode)		//��
{
	double f=0;
	u32 d=0;

	value=(value<max)?value:max;
	value=(value>min)?value:min;

	f=(double)(value-min)/(double)(max-min);

	if((mode&0x01)==DIREC_X)				//x����
	{
		d=f*xsize;
		if((mode&0x06)==PROGBAR) 			//������
		{
			GUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,ACTUAL);
			GUI_GBasic_Rectangle(x0,y0,x0+d,y0+ysize,FILL);		
		}
		else if((mode&0x06)==SCALEBAR)		//�̶�
		{
			GUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,ACTUAL);
			GUI_GBasic_Rectangle(x0,y0,x0+d,y0+ysize,ACTUAL);
			SOLGUI_GBasic_Line(x0,y0+ysize,x0+xsize,y0+ysize,DELETE);
		}
		else if((mode&0x06)==SCROLL)		//������
		{
			
		}
	}
	else									//y����
	{		
		d=f*ysize;
		if((mode&0x06)==PROGBAR) 			//������
		{
			GUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,ACTUAL);
			GUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+d,FILL);
		}
		else if((mode&0x06)==SCALEBAR)		//�̶�
		{
			GUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+ysize,ACTUAL);
			GUI_GBasic_Rectangle(x0,y0,x0+xsize,y0+d,ACTUAL);
			SOLGUI_GBasic_Line(x0,y0,x0,y0+ysize,DELETE);
		}
		else if((mode&0x06)==SCROLL)		//������
		{
			
		}		
	}	
}

#endif





