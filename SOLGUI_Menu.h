#ifndef SOLGUI_MENU_H
#define SOLGUI_MENU_H

//###########################�����޸Ĳ�����##############################
#define MAX_MENU_OPTION 17 		//��ҳ���˵�ѡ����(����СһЩ���Լ����ڴ�ʹ����)
//-------��ֵ����
#define	MENU_KEY_UP		0x50	//�ϼ���ֵ
#define MENU_KEY_DOWN	0x20	//�¼���ֵ
#define	MENU_KEY_LEFT	0x30	//�����ֵ
#define MENU_KEY_RIGHT	0x10	//�Ҽ���ֵ
#define	MENU_KEY_OK		0x40 	//OK���̰���ֵ
#define	MENU_KEY_OK_L	0x40	//OK��������ֵ����û�г����������ö̰���ֵ���棬Ӱ�첻�󣩡�PS����ʱ����ʱ��̫�������ö̰����桿
#define	MENU_KEY_BACK	0x60	//���ؼ���ֵ

//############################���ڲ����塿##############################
#define NULL 		0				//��
#define FUNC_NULL 	0				//������
#define LIST_NULL	{0}				//ָ���б��

#define MENU_KIND	0x01  			//�˵�ҳ����
#define	FUNC_KIND	0x10			//����ҳ����


typedef struct __MENU_ITEM{									//�˵�/��������
	unsigned char pageKind;									//ҳ�����ͣ�MENU_KIND�˵��ͣ�֦����FUNC_KIND�����ͣ�Ҷ��)
//--------���˵�������ԡ�
	unsigned char *menuTitle;								//�ò�˵��ı���
	unsigned char page;										//��ʼҳ		�����ھ�������0��
	unsigned char page_cursor;								//��ʼҳ�ڹ��	�����ھ�������0��
	unsigned char optionCnt;								//�ò�˵��к��е�ѡ����Ŀ��
	struct __MENU_ITEM *ChildrenMenus[MAX_MENU_OPTION];		//�ò�˵��к��е��Ӳ˵�ָ������
	struct __MENU_ITEM *ParentMenus;						//�ò�˵��еĸ��˵�ָ��
//--------������������ԡ�
	void (*HookFunc)();										//�ù���ҳ��ִ�к���
}MENU_ITEM;

//##############################��API��##############################
//--------���˵����桿
void SOLGUI_Menu_Init(MENU_ITEM *Root_Menu);				//�˵������ʼ����������˵�ָ�룩
void SOLGUI_Menu_GetKeyValue(unsigned char key_value);		//ȡ����������ļ�ֵ�������ֵ��
void SOLGUI_Menu_Main(void);								//�˵����棨Ҫ���ú���ȡ�ü�ֵ������������Ҫѭ�����á�

//--------������ҳʹ�á�
void SOLGUI_Menu_Title(void);										//��ʾ��ҳ���⣨��ѡ��
unsigned char SOLGUI_Menu_GetKeyInline(void);						//��������ȡ�ü�ֵ

//--------������ҳʹ�á�
void SOLGUI_Menu_Cursor_Alone(unsigned char top_col,unsigned char bot_col,unsigned char option_cnt); 			//����ҳ��꼰ѡ��ѡͨ��������ѡ����ʾ�Ͻ磬�½磬ѡ������
void SOLGUI_Menu_Set_Int(unsigned char handle,unsigned char *value_name,int *value,int value_max,int value_min);//���������������������������10���ַ�
void SOLGUI_Menu_Set_Double(unsigned char handle,unsigned char *value_name,double *value,int value_max,int value_min);  //����С���������������������10���ַ���3λС��
void SOLGUI_Menu_Trig_Func(unsigned char handle,unsigned char *func_name,void (*func)(void));					//����ҳ�еĵ��δ�������,����������10���ַ�

/*---------------------------------------------------------------------------------------------------------------------------------
��SOLGUI_MENU_2.0 SOL�˵�����v2.0ʹ��˵����

��Ҫ���ļ���
	pixelC_SOLGUI_General.h
	pixelC_SOLGUI_General.c	//�����ַ�����������ʾ����ѡ��
	pixelC_SOLGUI_MENU.h
	pixelC_SOLGUI_MENU.c	//�˵����桾���ġ�


��1��ԭ������˫�������״̬��
����.c�ļ���Ϊ״̬�����ü�ֵ���뺯�������ֵ���ı�״̬�����������Ƿ������ṹ����ִ�й���ҳ��ĺ���ʱ���˵���
��ռ��ϵͳʱ�伫�١�

��2���ṹ����Ϊ����ҳ�棬MENU_KIND�˵��ͺ�FUNC_KIND�����͡��ɲ˵��������빦��ҳ������ҳִ�к���������ʱ�䰴
�·��ؼ��������˻��ϼ��˵��С����������νṹ���˵�ҳ����֦���ɣ�����ҳ����Ҷ

��3����ֲ���裺
1.�������޸ļ�ֵ�����ⲿ����μ�ֵʱ�ᴥ���Ĳ�����

2.����ҳ�棺��Ҫ�õ���ҳ���������������ע�⣬���Ƕ��壡������ֹ�ڶ���ҳ��ʱ�õ�����֮�����ҳ��������Ĵ���
�磺
	MENU_ITEM root,temp_1,temp_2,������; 	//��������

3.����ҳ�棺

ʹ��MENU_ITEM���Ͷ���ҳ�棬����Ա���ã�
	unsigned char pageKind;									//ҳ�����ͣ�MENU_KIND�˵��ͣ�FUNC_KIND������)
	unsigned char *menuTitle;								//�ò˵��ı���
	unsigned char page;										//ҳ��				
	unsigned char page_cursor;								//ҳ�ڹ��λ��
	unsigned char optionCnt;								//�ò˵��е�ѡ����Ŀ
	struct __MENU_ITEM *ChildrenMenus[MAX_MENU_OPTION];		//�ò˵��е��Ӳ˵�ҳ/����ҳָ������
	struct __MENU_ITEM *ParentMenus;						//�ò˵��еĸ��˵�ָ��
	void (*HookFunc)();										//��Ϊ����ҳʱ��ִ�к���

�������������ҳ��Ķ���ģ�壺��ֱ�Ӹ����޸ļ��ɣ���
//----------------------------------//�˵�ҳģ��
MENU_ITEM temp={					
	MENU_KIND,						//MENU_KIND�˵���
	"title",						//����
	0,								//��0
	0,								//��0
	2,								//ѡ����Ŀ
	{&temp_func,&temp_menu},		//ѡ��ҳ�����ָ���б������ǹ���ҳ�����ǲ˵�ҳ��ע���&ȡ��ַ��
	&root,							//�ϼ�ҳ�����ָ�루�����ؼ�����Իص������ҳ�棩
	FUNC_NULL 						//FUNC_NULLû��ִ�к��� 
};

//----------------------------------//����ҳģ��

void function(void)				 	//����ҳִ�к���������Ϊ�޲����޷���ֵ�ĺ������ͣ�
{
	...
}

MENU_ITEM temp={					
	FUNC_KIND,						//FUNC_KIND������
	"title",						//����
	0,								//��0
	0,								//��0
	0,								//��0
	LIST_NULL,						//��LIST_NULL
	&root,					    	//�ϼ�ҳ�����ָ�루�����ؼ�����Իص������ҳ�棩
	function 						//�ù���ҳ��ִ�к�����
};



4.ʹ�ò˵�����
�õ�����������
void SOLGUI_Menu_Init(MENU_ITEM *Root_Menu);				//��ʼ���˵����棬Ҫ�����ҳ�棨���к���ʾ�ĵ�һ��ҳ�棩ָ��
void SOLGUI_Menu_GetKeyValue(unsigned char key_value);		//��ȡ��ֵ����˵����棨����Ӱ���ɨ�躯���еõ��ļ�ֵ������������Ҫѭ�����á�				
void SOLGUI_Menu_Main(void);								//�˵��������塾��������Ҫѭ�����á�

�������ʹ�������ģ�壺
//----------------------------------//����ʹ��ģ��
void main()
{
	...
	SOLGUI_Menu_Init(&root);				//��ʼ���˵����棬Ҫ�����ҳ��ָ��
	...
	while(1)
	{
		...
		key_value=Key_Scan();				//����ɨ�躯�������ؼ�ֵ��Key_Scan()��Ҫ�Լ�����
		SOLGUI_Menu_GetKeyValue(key_value);	//��ֵ����˵�����
		SOLGUI_Menu_Main();					//�˵���������
		...
	}
}

��PS��pixelC_SOLGUI_MENU.c�ļ�����@��ʶ��ע����ʹ����pixelC_SOLGUI_General.h�еĺ���ʵ�ֵģ��������б�д�滻��

��4������ҳ��
�˵��������жϵ�ǰҳ��Ϊ������ҳ�󣬻�ִ�й���ҳ��ִ�к���������ÿ��ѭ������ѯ�Ƿ��з��ؼ����£�����У��򷵻��ϼ��˵���
��ˣ���ֻҪ�ڹ���ҳִ�к����в�����:���޸�ҳ������(��ɲ˵���)����ʹ�÷��ؼ��������ֱ�ӽ��˵����浱������ҳִ�к���!��
����
	 function(void)<----->SOLGUI_Menu_Main(void); 		//���ߵȼ�
	
��ʱ���ڹ���ҳִ�к����п��Ե����������������ȡ��ֵ�����ؼ����⣩����Ļ��ͼ��GPIO�����ڵȣ���
��ʱ��ִ�к�����д�����ȼ��ڣ�
					while(1)
					{
						...
						function();
						...
					}


������ҳ�л�ȡ��ֵ�����Ҫ�ڹ���ҳ�л�ȡ����ֵ������ʹ��
						SOLGUI_Menu_GetKeyInline();
������ȡ���룬��������˵������еļ�ֵ���ⷽ����ļ����ʱʹ�á�

������ҳ����ʾ��ҳ���⡿���Ҫ�ڹ���ҳ������ʾ���⣬����ʹ��
						SOLGUI_Menu_Title(void); 
������˵�ҳ����һ�µı���


��5����������ҳ��
�ر�ģ��˵������ṩһ�����ڲ������õĹ���ҳ����Ϊ��������ҳ��ÿ��ҳ����԰������MAX_MENU_OPTION(Ĭ��16)����
���������ã�֧�ֹ���������

���Ƕ���Ļ���н������¶���:

					+-----------------------+
					|________[ ���� ]_______|	-----��7��
					| 	����1		| ֵ	|	-----��6��
					|	����2		| ֵ	|	-----��5��
					|	����3		| ֵ	|	-----��4��
					|	����4		| ֵ	|	-----��3��
					|	����5		| ֵ	|	-----��2��
					|	����������	-> 		|	-----��1��
					|	����������	-> 		|	-----��0��
					+-----------------------+

������ڲ�������ҳ�����ò�������
��1�����¼��ƶ���꣬ѡ��Ҫ�޸ĵĲ�����
��2������ȷ�ϼ����������������Ҽ����ò���ֵ�����¼��Բ������мӼ���
��3���ٴγ���ȷ�ϼ������������������������˳���ʧЧ�����ظ���1�����߰��˳����˳���������ҳ��


2. ��������ҳ��д��
��1������:
����Ϊ����ҳ����ο�������ҳģ�塿��ֻ���ڹ���ҳִ�к����У�ʹ��ģ�弴�ɣ�

��2��ִ�к�����
������ҳ��غ�����
void SOLGUI_Menu_Cursor_Alone(unsigned char top_col,unsigned char bot_col,unsigned char option_cnt); 			
	//������꼰ѡ��ѡͨ����ѡ�����Ͻ磬ѡ�����½磬ѡ���������������ƣ����½�ɵߵ���
	
void SOLGUI_Menu_Set_Int(unsigned char handle,unsigned char *value_name,int *value,int value_max,int value_min);
	//������������ѡ�������ʾ��ţ�������ʾ��������ֵָ�룬���ޣ����ޣ�
	��PS������������10���ַ������ھ��ȣ�1�����������ƣ������޿ɵߵ���

void SOLGUI_Menu_Set_Double(unsigned char handle,unsigned char *value_name,double *value,int value_max,int value_min);  
	//����С������ѡ�������ʾ��ţ�������ʾ��������ֵָ�룬���ޣ����ޣ�
	��PS������������10���ַ������ھ��ȣ�0.001�����������ƣ������޿ɵߵ���
	
void SOLGUI_Menu_Trig_Func(unsigned char handle,unsigned char *func_name,void (*func)(void));					
	//����ҳ�еĵ��δ�����������ʾ��ţ�������ʾ��������ָ�룩
	��PS������������10���ַ�������ȷ�ϼ����ִ��func()�еĴ��룩

��ÿ��������ѡ������븳��һ��Ψһ����ʾ��ţ���ʾʱ�ᰴ��ʾ���˳����ʾ����Χ��0~ѡ����-1��

//----------------------------------//��������ҳģ��

void function(void)		 						//SOLGUI_Menu_Trig_Func()ʹ�õĵ��δ�������
{
//	...(���Ե���ȫ����Դ��������ѭ��)
}

void set(void)			
{
	SOLGUI_Menu_Cursor_Alone(6,3,8); 			//�ӵ�6�е���3����ʾѡ�����8����������������ʾ���Ϊ0~7����
//--------����Ϊ�����������
	SOLGUI_Menu_Set_Int(0,"Enable_PID?",&PID_en,1,0);
	SOLGUI_Menu_Set_Int(1,"PIDobj_addr",&addr,255,0);
	SOLGUI_Menu_Set_Int(2,"PIDobj_opt",&opt,5,0);
	SOLGUI_Menu_Set_Int(3,"PID_balance",&bal,100,-100);
	SOLGUI_Menu_Set_Double(4,"PIDobj_Kp",&Kp,10000,-10000);
	SOLGUI_Menu_Set_Double(5,"PIDobj_Ki",&Ki,10000,-10000);
	SOLGUI_Menu_Set_Double(6,"PIDobj_Kd",&Kd,10000,-10000);
	SOLGUI_Menu_Trig_Func(7,"SetToPID",function);
	
	... 	

}

---------------------------------------------------------------------------------------------------------------------------------*/

#endif
