#include"SOLGUI_Include.h"

#if MENU_FRAME_EN==1
//##############################���������塿##############################
//-----------��״̬�Ĵ�����
u8 SOLGUI_CSR=0;		//����ģʽ���ƼĴ�����1������ģʽ�У�0���У�
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

	u32 y_t=0,y_b=0;
	double s_h=0;			//����ĸ߶�
	u32 s_y=0;				//�����λ��
//--------���������ˡ�
	if(rowBorder_Top<rowBorder_Bottom)		//Ĭ���ϱ߽�����±߽磬���򽻻�
	{
		temp=rowBorder_Top;
		rowBorder_Top=rowBorder_Bottom;
		rowBorder_Bottom=temp;
	}
	if(option_num>OPTIONS_MAX) option_num=OPTIONS_MAX;		//���������Ϊ���
//--------����ز������㡿
	row_start=rowBorder_Top;	//����ѡ����ʼ��
	viewport_width=rowBorder_Top-rowBorder_Bottom; //�ӿ���������
	if(option_num<=viewport_width) viewport_width=option_num-1;		//ѡ����С���ӿڿ�ȴ���
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
	cursor_abs_offset=viewport_offset+cursor_rel_offset;	//���㵱ǰ���ľ���ƫ��
//--------����Ļ���ơ�
	y_t=rowBorder_Top*8;									//��y����
	y_b=rowBorder_Bottom*8;									//��y����
//---����꡿
	cursor_row=y_t-cursor_rel_offset*8;	 		//���������ӿڵ�ƫ�ƻ������������
	SOLGUI_printf(0,cursor_row,F6X8,"%c",ICON_CURSOR);		//������
//---�����±��ߡ�
	if(rowBorder_Top!=6) SOLGUI_GBasic_Line(0,y_t+8,SCREEN_X_WIDTH-1,y_t+8,DOTTED);		//�ϱ���
	if(rowBorder_Top!=0) SOLGUI_GBasic_Line(0,y_b-1,SCREEN_X_WIDTH-1,y_b-1,DOTTED);		//�±���
//---����������

	s_h=(double)(y_t-y_b+8)/(double)option_num;									//����߶�???????????????????????
	s_y=y_t+7-s_h*(cursor_abs_offset+1);							//����λ��???????????????????????
	GUI_GBasic_Rectangle(SCREEN_X_WIDTH-4,s_y,SCREEN_X_WIDTH-1,s_y+s_h,FILL);	//����???????????????????????

	GUI_GBasic_Rectangle(SCREEN_X_WIDTH-4,y_b,SCREEN_X_WIDTH-1,y_t+7,ACTUAL);	//�߿�

//--------���޸�ѡ��ʹ�ܱ�			
	for(i=0;i<=option_num;i++){
		option_enable_list[i]=(cursor_abs_offset==i)?1:0;	//��дѡ��ʹ�ܱ��ھ���ƫ��λ����Ϊ1������λ��Ϊ0��
	}
}

//##############################��ѡ��ʽ�ؼ���##############################

void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page)		//ҳ����ת�ؼ�
{
	u8 row_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
//--------���������ˡ�
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
//--------��������ʾ�С�
	if((USN-viewport_offset)>=0&&(USN-viewport_offset)<=viewport_width)
	{		
		row_disp=row_start-USN+viewport_offset;
		if(option_enable_list[USN]==1)
		{
//--------����ֵ������
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){					//OK��			
				current_page=page;						//��ת
				cursor_rel_offset=0;					//��չ��ƫ�Ƽ�����
				viewport_offset=0;											
			}					
		}
//--------��ѡ����ơ�
		SOLGUI_printf(6,row_disp*8,F6X8,"%s",page->pageTitle);		//��һ��ҳ�����
		SOLGUI_printf(SCREEN_X_WIDTH-13,row_disp*8,F6X8,"%c",0x8f);	//ͼ��
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",0x84);			//����ָʾ�����ݼ�ֵ������������д��
	}
}



double _Pow_10(s8 n) 	//pow=10^n
{
	s16 i=0;
	s8 m=(n>=0)?n:-n;
	double p=1;

	for(i=0;i<m;i++)
	{
		if(n>=0) p*=10;
		else p*=0.1;
	}
	return(p);
}

void SOLGUI_Widget_Spin(u8 USN,u8 type,const u8 *name,double max,double min,void* value)		//������ť�ؼ�
{
	double swap;	
	u8 row_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
	static s8 spin_pos=0;	//��ťλ��
	double dat_step=0;
	s32 *v_l;
	double *v_f;
//--------���������ˡ�
	if(max<min)
	{
		swap=max;
		max=min;
		min=swap;
	}
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
//--------������׼����
	if(type==INTEGRAL) v_l=(s32 *)value;	//����	
	else if(type==DECIMAL) v_f=(double *)value;	 //С��
	else v_l=(s32 *)value;		//����Ĭ����������������չ��
//--------��������ʾ�С�
	if((USN-viewport_offset)>=0&&(USN-viewport_offset)<=viewport_width)
	{		
		row_disp=row_start-USN+viewport_offset;
		if(option_enable_list[USN]==1)
		{
//--------����ֵ������
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){					//OK��			
				SOLGUI_CSR++;							//CSR��ת
				if(SOLGUI_CSR>1) SOLGUI_CSR=0;													
			}
			if(SOLGUI_CSR==1)							//�����������ģʽ��
			{
				dat_step=_Pow_10(spin_pos);				//������ڲ���ֵ

				if(cur_key==SOLGUI_KEY_UP)														//��ֵ�Ӳ���
				{
					if(type==DECIMAL) { if(((*v_f)+dat_step)<=max) (*v_f)+=dat_step; }			//С��	
					else { if(((*v_l)+(s32)dat_step)<=(s32)max) (*v_l)+=(s32)dat_step; }	 	//����		
				}
				else if(cur_key==SOLGUI_KEY_DOWN)												//��ֵ������
				{
					if(type==DECIMAL) { if(((*v_f)-dat_step)>=min) (*v_f)-=dat_step; }			//С��	
					else { if(((*v_l)-(s32)dat_step)>=(s32)min) (*v_l)-=(s32)dat_step; }	 	//����
				}
				else if(cur_key==SOLGUI_KEY_LEFT)												//�󲽽�
				{
					if(spin_pos<SPIN_DIGIT_MAX-1) spin_pos++;						
				}
				else if(cur_key==SOLGUI_KEY_RIGHT)												//�Ҳ���
				{
					if(type==INTEGRAL) { if(spin_pos>0) spin_pos--; }	//����	
					else if(type==DECIMAL) { if(spin_pos>SPIN_DIGIT_MIN) spin_pos--; }	 //С��
					else { if(spin_pos>0) spin_pos--; }		//����Ĭ����������������չ��
				}
			}				
		}
//--------��ѡ�������&��ֵ���ơ�
		SOLGUI_printf(6,row_disp*8,F6X8,"%s",name);		//������
		if(type==DECIMAL) SOLGUI_printf(68,row_disp*8,F6X8,"=%f",*v_f);	//��ֵ		
		else SOLGUI_printf(68,row_disp*8,F6X8,"=%d",*v_l);	//��ֵ						
//--------����ť���ơ�
		if((SOLGUI_CSR==1)&&(option_enable_list[USN]==1)) 
		SOLGUI_printf(0,row_disp*8,0,"%c%f%c",0x82,dat_step,0x83);	   	//�����������ģʽ�У���ʾ��ť��ֵ
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
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
	}	
}

#endif





