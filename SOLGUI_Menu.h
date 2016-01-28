#ifndef SOLGUI_MENU_H
#define SOLGUI_MENU_H

#define PAGE_NULL 		0		//��ҳ��
#define FIFO_NONE		0		//FIFO��

//##############################��ҳ�溯����Ϣ�ṹ�塿##############################
//ÿ��������ҳ�����ҳ�溯����һ����Ϣ�ṹ�壨��������ҳ�������Ϣ��
typedef struct __MENU_PAGE{									//�˵�/��������
	const u8 *pageTitle;									//�ò�˵��ı���
	struct __MENU_PAGE *parentPage;							//�ò�˵��еĸ��˵�ָ��
	void (*pageFunc)();										//ҳ�溯��ָ��
}MENU_PAGE;

//####################################��FIFO��##############################
//ʹ��FIFO��ǿ�������첽����µ��ȶ���
typedef struct __GUI_FIFO{
	u8 FIFOBuffer[FIFOBUF_SIZE];	   						//����FIFO��
	u8 Read;												//��������ָ��				
	u8 Write;												//������дָ��
}GUI_FIFO;													//FIFO��			

//####################################��API��##########################################
void SOLGUI_Menu_SetHomePage(MENU_PAGE *home_page);	//��ҳ����
void SOLGUI_InputKey(u8 key_value); 				//������������ϵͳ�л�ȡ��ǰ������ֵ�������
u8 	 SOLGUI_GetCurrentKey(void); 					//������������ȡGUI��ǰ��ȫ�ּ�ֵ
void SOLGUI_Menu_PageStage(void);					//����������SOLGUIǰ̨ҳ���л���




#endif
