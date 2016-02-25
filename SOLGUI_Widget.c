#include"SOLGUI_Include.h"
#include<string.h>
#include<stdarg.h> 						//֧�ֱ䳤����

#if MENU_FRAME_EN==1
//##############################���������塿##############################
//-----------�����ƫ�Ƽ�������
/*ѡ��������������
   >option0
	option1
	option2
	...
*/
u8 cursor_rel_offset=0;	//�������ӿڵ�ƫ��
u8 viewport_offset=0;	//�ӿڵ�ƫ��
//-----------�����λ�ü��㡿
u8 row_start=0;			//ѡ����ʼ�У�����˶��Ͻ磩
u8 viewport_width=0;	//�ӿڿ��
u32 y_t=0,y_b=0;		//�߽���������
//-----------��ѡ��ʹ�ܱ�
u8 option_enable_list[OPTIONS_MAX];		//ѡ��ʹ�ܱ�,�˴����ԸĽ�

//-----------��GotoPage�ؼ���
extern MENU_PAGE *current_page;	//��ǰҳ��
//-----------��״̬�Ĵ�����
/*	
	SOLGUI_CSR[0]��	SPINռ��1������0
	SOLGUI_CSR[1]��	EDITռ��1������0��Ҫռ��ȫ����
	SOLGUI_CSR[2]�� EDIT���뷨����1���ر�0
*/
u8 SOLGUI_CSR=0;		//����ģʽ���ƼĴ���

//-----------��EDIT��
const u8 SOL_ASCII_IME_lowerchar[]	="abcdefghijklmnopqrstuvwxyz";
const u8 SOL_ASCII_IME_upperchar[]	="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const u8 SOL_ASCII_IME_Number[]		="0123456789+-*/=%()[]{}<>&|~^";
const u8 SOL_ASCII_IME_symbol[]		=" .,:;_?!@#$'\"\\";
const u8 SOL_ASCII_IME_CRLchar[]	={0x00,0x0a,0x0d};	//�������ַ�

IME_CLUSTER IME_CLUSTER_LC={0,"LOWER",26,SOL_ASCII_IME_lowerchar};		//��д�ַ���
IME_CLUSTER IME_CLUSTER_UC={0,"UPPER",26,SOL_ASCII_IME_upperchar};		//Сд�ַ���
IME_CLUSTER IME_CLUSTER_NU={0,"NUMBER",28,SOL_ASCII_IME_Number};		//�����ַ���
IME_CLUSTER IME_CLUSTER_SY={0,"SYMBOL",14,SOL_ASCII_IME_symbol};		//�����ַ���
IME_CLUSTER IME_CLUSTER_CR={0,"CTRL",3,SOL_ASCII_IME_CRLchar};			//�����ַ���

EDIT_IME SOL_ASCII_IME_REG={		//����ascii���뷨
	0,								//�ַ�����ǰָ�򴢴�
	SOL_ASCII_IME_SIZE,				//�ַ�����С
   {&IME_CLUSTER_LC,
	&IME_CLUSTER_UC,
	&IME_CLUSTER_NU,
	&IME_CLUSTER_SY,
	&IME_CLUSTER_CR}
};



//################################���ڲ����ú�����##############################

boolean _OptionsDisplay_Judge(u8 USN)
{
	if((USN-viewport_offset)>=0&&(USN-viewport_offset)<=viewport_width&&(!bit_istrue(SOLGUI_CSR,bit(1))))	
		return(True);	//��ʾѡ��	
	else return(False);	 //����ʾѡ��	
}

u32 _OptionsDisplay_coorY(u8 USN)
{
	return((row_start-USN+viewport_offset)*8);
}

void _String_LenCtrlCpy(u16 dest_size,u8 *dest,u8 *sour)
{
	if(strlen((const char *)sour)>dest_size) strncpy((char *)dest,(char *)sour,dest_size);	//���������Ƶĸ��� 
	else strcpy((char *)dest,(char *)sour);	//���¸���buf
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



//################################����꡿##############################
//ѡ��ʽ�ؼ������й����ܲ���
void SOLGUI_Cursor(u8 rowBorder_Top,u8 rowBorder_Bottom,u8 option_num)		//��꣨�ϱ߽��У��±߽��У�ѡ�������	
{
	u8 i=0;
	u8 temp=0;
	u8 cur_key=0;
	u8 cursor_row=0;
	u8 cursor_abs_offset=0;	//���ľ���ƫ��

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
	s_h=(double)(y_t-y_b+8)/(double)option_num;									//����߶�
	s_y=y_t+7-s_h*(cursor_abs_offset+1);										//����λ��
	GUI_GBasic_Rectangle(SCREEN_X_WIDTH-4,s_y,SCREEN_X_WIDTH-1,s_y+s_h,FILL);	//����
	GUI_GBasic_Rectangle(SCREEN_X_WIDTH-4,y_b,SCREEN_X_WIDTH-1,y_t+7,ACTUAL);	//�߿�
//--------���޸�ѡ��ʹ�ܱ�			
	for(i=0;i<=option_num;i++){
		option_enable_list[i]=(cursor_abs_offset==i)?1:0;	//��дѡ��ʹ�ܱ��ھ���ƫ��λ����Ϊ1������λ��Ϊ0��
	}
}

//##############################��ѡ��ʽ�ؼ���##############################

void SOLGUI_Widget_GotoPage(u8 USN,MENU_PAGE *page)		//ҳ����ת�ؼ�
{
	u32 y_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
//--------���������ˡ�
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
//--------��������ʾ�С�
	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
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
		SOLGUI_printf(6,y_disp,F6X8,"%s",page->pageTitle);		//��һ��ҳ�����
		SOLGUI_printf(SCREEN_X_WIDTH-13,y_disp,F6X8,"%c",ICON_WIDGET_GOTOPAGE);	//ͼ��
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",ICON_OK);	//����ָʾ�����ݼ�ֵ������������д��
	}
}

void SOLGUI_Widget_Spin(u8 USN,const u8 *name,u8 type,double max,double min,void* value)		//������ť�ؼ�
{
	double swap;	
	u32 y_disp=0;	//��ѡ��Ӧ����ʾ����λ��
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
	switch(type)
	{
		case DECIMAL: v_f=(double *)value; break; //С��
		case INTEGRAL:;			   //����
		default:v_l=(s32 *)value;  //����Ĭ����������������չ��
	}
//--------��������ʾ�С�
	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{
//--------����ֵ������
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){					//OK��			
				SOLGUI_CSR^=bit(0);						//CSR[0]��ת����1��ʾSPINռ��									
			}
			if(bit_istrue(SOLGUI_CSR,bit(0)))			//�������SPINռ����
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
					if(type==DECIMAL) { if(spin_pos>SPIN_DIGIT_MIN) spin_pos--; }	 //С��
					else { if(spin_pos>0) spin_pos--; }		//����Ĭ����������������չ��
				}
			}				
		}
//--------��ѡ�������&��ֵ���ơ�
		SOLGUI_printf(6,y_disp,F6X8,"%s",name);		//������
		if(type==DECIMAL) SOLGUI_printf(68,y_disp,F6X8,"%f",*v_f);	//��ֵ		
		else SOLGUI_printf(68,y_disp,F6X8,"%d",*v_l);	//��ֵ						
//--------����ť���ơ�
		if(bit_istrue(SOLGUI_CSR,bit(0))&&(option_enable_list[USN]==1)) 
		SOLGUI_printf(0,y_disp,~F6X8,"%c%f%c",ICON_LEFT,dat_step,ICON_RIGHT);	   	//�����������ģʽ�У���ʾ��ť��ֵ
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",ICON_OK);			//����ָʾ�����ݼ�ֵ������������д��
	}	
}

void SOLGUI_Widget_Text(u8 USN,const u8 *text)						//�ı�
{
	u32 y_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 t[SCREEN_X_PAGE-2];		//�ַ�����
//--------���������ˡ�
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
	_String_LenCtrlCpy(SCREEN_X_PAGE-2,t,(u8 *)text);
//--------��������ʾ�С�
	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
//--------��ѡ����ơ�
		SOLGUI_printf(6,y_disp,F6X8,"%s",t);		//�ı���ʾ
	}
}

void SOLGUI_Widget_Button(u8 USN,const u8 *name,void (*func)(void))				//����
{
	u32 y_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
	u8 run_f=0;		//���мǺ�
//--------���������ˡ�
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
//--------��������ʾ�С�
	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{
//--------����ֵ������
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){					//OK��			
				run_f=1;								
			}					
		}
//--------��ѡ����ơ�
		SOLGUI_printf(6,y_disp,F6X8,"%s",name);					//ѡ����
		SOLGUI_printf(68,y_disp,F6X8,"->");						//ͼ��
//--------������ǣ��������		
		if(run_f==1) 											//����OK��������ǣ������
		{
			run_f=0;											//ֻ����һ��
			func();	
		}
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",0x84);			//����ָʾ�����ݼ�ֵ������������д��
	}
}

void SOLGUI_Widget_Switch(u8 USN,const u8 *name,u32 *mem_value,u8 L_shift)		//�������أ�mem_value��һ���ⲿ����ķ���ʧ�Դ洢��������
{
	u32 y_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
	u32 temp=bit(L_shift);
//--------���������ˡ�
	if((L_shift<1)||(L_shift>32)) L_shift=1;	//С��1�����32������Ϊ1
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
//--------��������ʾ�С�
	if(True==_OptionsDisplay_Judge(USN))
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{
//--------����ֵ������
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){					//OK��			
				(*mem_value)^=temp;			//��Ҫ�ⲿ����ʧ�Դ���ռ�����������־λ������ĳλȡ��									
			}					
		}
//--------��ѡ����ơ�
		SOLGUI_printf(6,y_disp,F6X8,"%s",name);						//ѡ����
//--------��ͼ����ơ�
		if(bit_istrue((*mem_value),temp)) SOLGUI_printf(68,y_disp,F6X8,"[ON ]");				//"��"����	
		else SOLGUI_printf(68,y_disp,F6X8,"[OFF]");												//"��"����
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",0x84);			//����ָʾ�����ݼ�ֵ������������д��
	}	
}


void SOLGUI_Widget_Edit(u8 USN,const u8 *name,u16 char_num,u8 *buf)			//�ı��༭��
{	
	u32 y_disp=0;	//��ѡ��Ӧ����ʾ����λ��
	u8 cur_key=0;	//��ֵ
	u16 i=0,j=0,buf_i=0;
	u8 edit_thumbnail_buf[EDIT_THUMBNAIL_SIZE];	//��������
	static u8 edit_buf[EDIT_BUF_SIZE];			//�༭������buf	
	static u16 edit_cursor_row=0;				//�༭�������ַ�λ��
	static u16 edit_cursor_col=0;				//�༭��������ַ�λ��
	EDIT_IME *SOL_ASCII_IME=&SOL_ASCII_IME_REG;
	u16 edit_buf_size_temp=char_num<EDIT_BUF_SIZE?(char_num+1):EDIT_BUF_SIZE;
//--------���������ˡ�
	if(USN>=OPTIONS_MAX) return;		//USNֻ����ȡ0~OPTIONS_MAX-1
	
//--------��������ʾ�С�
	if((USN-viewport_offset)>=0&&(USN-viewport_offset)<=viewport_width)
	{		
		y_disp=_OptionsDisplay_coorY(USN);
		if(option_enable_list[USN]==1)
		{
//--------����ֵ����������EDITռ�á�
			cur_key=SOLGUI_GetCurrentKey();				//��ȡ��ǰȫ�ּ�ֵ
			if(cur_key==SOLGUI_KEY_OK){					//OK��
//--------�����ָ��(0,0)λ�á�
				if((edit_cursor_row==0)&&(edit_cursor_col==0)) 	 //������ָ�ַ�(0,0)λ
				{
					if(bit_istrue(SOLGUI_CSR,bit(1)))	//����ڱ༭״̬��
					{
						SOLGUI_CSR&=(~bit(1));					//CSR[1]=0����0��ʾEDITռ�ý��
						_String_LenCtrlCpy(char_num,buf,edit_buf);	//���ϸ���buf
					}
					else
					{
						SOLGUI_CSR|=bit(1);					//CSR[1]=1����0��ʾEDITռ��
						memset(edit_buf,0,sizeof(edit_buf));			//edit_buf����
						_String_LenCtrlCpy(edit_buf_size_temp,edit_buf,buf);
					}
				}										
				else
				{
//--------�����ָ�������ַ�λ�ã����¿������뷨��
					SOLGUI_CSR^=bit(2);						//CSR[2]��ת����1��ʾ���뷨ռ��
				}
			}
			if(bit_istrue(SOLGUI_CSR,bit(1)))			//�������EDITռ��״̬��
			{
				buf_i=(SCREEN_X_PAGE-2)*edit_cursor_col+edit_cursor_row;	//�޸�λ�ü���	
//--------����ֵ������EDITռ���µĲ�����
				if(cur_key==SOLGUI_KEY_UP)								//�������&�ַ���
				{
					if(bit_istrue(SOLGUI_CSR,bit(2)) && (SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger
					< SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->size-1))
						SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger++;//���뷨��	
					else if(bit_isfalse(SOLGUI_CSR,bit(2))&&edit_cursor_col>0) 
						edit_cursor_col--;										//�ݹ���
				}
				else if(cur_key==SOLGUI_KEY_DOWN)								//�������&�ַ���
				{
					if(bit_istrue(SOLGUI_CSR,bit(2)) && (SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger>0))
						SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger--;//���뷨��	
					else if(bit_isfalse(SOLGUI_CSR,bit(2))&&edit_cursor_col<(SCREEN_Y_PAGE-4)
					&& ((buf_i+(SCREEN_X_PAGE-2))<edit_buf_size_temp)) 
						edit_cursor_col++;										//�ݹ���
				}
				else if(cur_key==SOLGUI_KEY_LEFT)						//�������&�ַ��������л�
				{
					if(bit_istrue(SOLGUI_CSR,bit(2))&&(SOL_ASCII_IME->finger>0)) SOL_ASCII_IME->finger--;	 //���뷨������
					else if(bit_isfalse(SOLGUI_CSR,bit(2))&&edit_cursor_row>0) edit_cursor_row--;			//�����
				}
				else if(cur_key==SOLGUI_KEY_RIGHT)						//�������&�ַ��������л�
				{
					if(bit_istrue(SOLGUI_CSR,bit(2))&&(SOL_ASCII_IME->finger<SOL_ASCII_IME->size-1)) SOL_ASCII_IME->finger++; //���뷨������	
					else if(bit_isfalse(SOLGUI_CSR,bit(2))&&edit_cursor_row<(SCREEN_X_PAGE-3)&&((buf_i+1)<edit_buf_size_temp)) 
						edit_cursor_row++;//�����
				}
			}				
		}
//--------��ѡ�������&��ֵ���ơ�
		if(bit_istrue(SOLGUI_CSR,bit(1)))
		{
//----����EDITռ���£���ʾ�༭����ȫ��ռ�ã���
//----[���Ʊ༭��]
			SOLGUI_Clean();					//������
			GUI_GBasic_Rectangle(0,0,SCREEN_X_WIDTH-1,SCREEN_Y_WIDTH-1,ACTUAL);		//�߿�
			SOLGUI_GBasic_Line(0,9,SCREEN_X_WIDTH-1,9,ACTUAL);						//�ײ�����
			if(bit_istrue(SOLGUI_CSR,bit(2)))
			{
				edit_buf[buf_i-1]=SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->table[SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger];	//�ַ�����ֵ
				SOLGUI_printf(2,1,F6X8,"%s",SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->name);	   //�ַ�����
				SOLGUI_printf(64,1,F6X8,"[ %c ]",SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->table[SOL_ASCII_IME->cluster[SOL_ASCII_IME->finger]->finger]);
			}
			else SOLGUI_printf(2,1,F6X8,"L:%d C:%d",edit_cursor_col+1,edit_cursor_row+1); //���λ��
//----[������ʾ]
			for(i=0;i<(SCREEN_Y_PAGE-3);i++)
			{
				for(j=0;j<(SCREEN_X_PAGE-2);j++)
				{
					if(i==0&&j==0)
					{
//----[����λ��ʾ(0,0)]
						if((edit_cursor_row==0)&&(edit_cursor_col==0)) 
							SOLGUI_printf(6,48,~F6X8,"%c",ICON_BACK);			//ȷ�ϲ���ָʾ���ַ�����(0,0)����
						else SOLGUI_printf(6,48,F6X8,"%c",ICON_BACK);			
					}
					else
					{
//----[�����ַ���ʾ]
						buf_i=(SCREEN_X_PAGE-2)*i+j-1;			//���ָ�ŵ�λ��
						if(buf_i<edit_buf_size_temp)
						{
							if((edit_cursor_row==j)&&(edit_cursor_col==i))					//���ָ����ַ� 
							{
								if(edit_buf[buf_i]=='\0') SOLGUI_printf(6+j*6,48-i*8,~F6X8,"%c",ICON_OTHER_HIDE);	//'\0'��'...'����ʾ�����ɱ༭����
								else SOLGUI_printf(6+j*6,48-i*8,~F6X8,"%c",edit_buf[buf_i]);			//ѡ�е��ַ�����ʾ
							}
							else 
							{	
								if(edit_buf[buf_i]=='\0') SOLGUI_printf(6+j*6,48-i*8,F6X8,"%c",ICON_OTHER_HIDE);   //'\0'��'...'����ʾ�����ɱ༭����
								else SOLGUI_printf(6+j*6,48-i*8,F6X8,"%c",edit_buf[buf_i]);
							}
						}
						else 
						{
							i=SCREEN_Y_PAGE; j=SCREEN_X_PAGE;	//����ѭ��
						}
					}
				}
			}												
		}
		else
		{
//----������EDITռ���£���ʾѡ�
			SOLGUI_printf(6,y_disp,F6X8,"%s",name);		//������
			_String_LenCtrlCpy(EDIT_THUMBNAIL_SIZE,edit_thumbnail_buf,buf);	//��������Ϣ�����и���
			SOLGUI_printf(68,y_disp,F6X8,"%s",edit_thumbnail_buf);			//����������ʾ
			if(strlen((const char *)buf)>(SCREEN_X_PAGE-14))SOLGUI_printf(SCREEN_X_WIDTH-19,y_disp,F6X8,"%c",ICON_OTHER_HIDE);	//��������ͼ��
			SOLGUI_printf(SCREEN_X_WIDTH-13,y_disp,F6X8,"%c",ICON_WIDGET_EDIT);	//EDITͼ��
		}
//--------��������ʾ���ơ�
		if((viewport_offset+cursor_rel_offset)==USN)
		SOLGUI_printf(SCREEN_X_WIDTH-6,56,F6X8,"%c",ICON_OK);			//����ָʾ�����ݼ�ֵ������������д��
	}	
}

//##############################������ʽ�ؼ���##############################

void SOLGUI_Widget_Bar(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value,u8 mode)		//��
{
	s32 swap=0;
	double f=0;
	u32 d=0;

//--------���������ˡ�
	if(max<min)
	{
		swap=max;
		max=min;
		min=swap;
	}
	value=(value<max)?value:max;
	value=(value>min)?value:min;

//----------������ÿ�񲽳���
	f=(double)(value-min)/(double)(max-min);
//----------������x����������
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
//----------������y����������		
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

void SOLGUI_Widget_Spectrum(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,u16 val_num,s32 value[])
{
	s32 swap=0;
	u16 i=0;
	double delta_x=0,delta_y=0;
	double x_p=0;
	u32 x_last=x0,y_last=y0,y_zero=0;
	s32 val_now=0;

	u32 x_now=0,y_now=0;

//--------���������ˡ�
	if(max<min)
	{
		swap=max;
		max=min;
		min=swap;
	}
//------------����ؼ��㡿
	delta_x=(double)(val_num)/(double)(xsize);		//����
	delta_y=(double)(ysize)/(double)(max-min);		//����һ�������Ƕ���ֵ
//------------�����߻��ơ�
	for(i=0;i<xsize;i++)
	{
		x_p+=delta_x;
		val_now=value[(int)x_p];
		x_now=x0+i;
		if((val_now>=min)&&(val_now<max)) y_now=y0+(u32)((val_now-min)*delta_y);
		else if(val_now<min) y_now=y0;
		else y_now=y0+ysize-1;
		SOLGUI_GBasic_Line(x_last,y_last,x_now,y_now,ACTUAL);
		x_last=x_now;
		y_last=y_now;	
	}
//------------�������ơ�
	GUI_GBasic_Rectangle(x0,y0,x0+xsize-1,y0+ysize-1,ACTUAL);
//------------�������ơ�
	if(min<0)
	{
		y_zero=y0+(u32)((-min)*delta_y);
		SOLGUI_DrawPoint(x0+1,y_zero,1);
	}	
}

void SOLGUI_Widget_Oscillogram(u32 x0,u32 y0,u32 xsize,u32 ysize,s32 max,s32 min,s32 value)
{
//	SOLGUI_Widget_Spectrum(x0,y0,xsize,ysize,max,min,val_num,value[]);
}

void SOLGUI_Widget_Picture(u32 x0,u32 y0,u32 xsize,u32 ysize,const u8 *pic,u8 mode)
{
//------------�������ơ�
	GUI_GBasic_Rectangle(x0,y0,x0+xsize-1,y0+ysize-1,ACTUAL);
//------------��ͼƬ���ơ�
//	SOLGUI_Pictrue(x0,y0,xsize,ysize,pic,mode);
//		
}

#endif





