#include"SOLGUI_Include.h"
#include<string.h>


#if MENU_FRAME_EN==1
//##############################��ȫ�ֱ������塿##############################
MENU_PAGE *current_page;//��ǰҳ��
GUI_FIFO _key_cache;	//��ֵFIFO

extern u8 CSR;		//��ǰ״̬�Ĵ���

//##############################���ڲ�ʹ�á�##############################

void FIFO_Init(void)
{
//------------��FIFO�������㡿
	memset(_key_cache.FIFOBuffer,0,sizeof(_key_cache.FIFOBuffer));
//------------��FIFO��дָ�����㡿
	_key_cache.Read=0;
	_key_cache.Write=0;
}

void FIFO_EnQueue(u8 KeyCode)
{
	_key_cache.FIFOBuffer[_key_cache.Write]=KeyCode;
	if(++_key_cache.Write>=FIFOBUF_SIZE) _key_cache.Write=0;
}

u8 FIFO_DeQueue(void)
{
	u8 ret;
	if(_key_cache.Read==_key_cache.Write) return(FIFO_NONE); 	//FIFO��
	else
	{
		ret=_key_cache.FIFOBuffer[_key_cache.Read];
		if (++_key_cache.Read>=FIFOBUF_SIZE) _key_cache.Read=0;
		return(ret);
	}
} 

void SOLGUI_Menu_Title(MENU_PAGE *page)
{
	u8 left_len=0,title_len=0;

	title_len=6*(strlen((const char*)page->pageTitle)+4);					//����������ؿ�� 
	left_len=(SCREEN_X_WIDTH-title_len)>>1;									//�������ƫ������

//---------�����⡿
	SOLGUI_printf(left_len+2,56,F6X8,"[ %s ]",page->pageTitle);				//page.pageTitle  ҳ��������
	SOLGUI_GBasic_Line(0,57,left_len+2,57,DOTTED);							//��������
	SOLGUI_GBasic_Line(left_len+title_len-2,57,SCREEN_X_WIDTH-1,57,DOTTED);	//��������
//---------������ͼ�꡿
	if(page->parentPage!=PAGE_NULL) SOLGUI_printf(0,56,F6X8,"%c",0x85);	//�и�ҳ�����������ͼ��

}

//##############################��API��##############################
void SOLGUI_Menu_SetHomePage(MENU_PAGE *home_page)	//��ҳ����
{
	current_page=home_page;
	FIFO_Init();
}

void SOLGUI_GetKeyValue(u8 key_value) 				//������������ϵͳ�л�ȡ��ǰ������ֵ����FIFO
{
	FIFO_EnQueue(key_value);
} 

void SOLGUI_Menu_PageStage(void)					//����������SOLGUIǰ̨ҳ���л���
{
	u8 cur_key=0;
//------------------��������ơ�
	SOLGUI_Menu_Title(current_page);
//------------------��ִ��ҳ�溯����
	current_page->pageFunc();						//ִ��ҳ�溯��
	cur_key=FIFO_DeQueue();							//��FIFO��ȡһ����ֵ
	if(cur_key==SOLGUI_KEY_BACK&&CSR==0){			//����Ƿ��з��ؼ�ֵ��CSRΪ�㣨��ռ�ã�
		if(current_page->parentPage!=PAGE_NULL)		//�и�ҳ��ſ�ʹ�÷��ؼ�
		{
			current_page=current_page->parentPage;	//�´�ִ�и�ҳ�溯��
//			cursor_al=0;							//���ָ�������
//			page_al=0;
		}
	}
}










#endif
