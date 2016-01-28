#ifndef SOLGUI_CONFIG_H
#define SOLGUI_CONFIG_H

//##############################��Ӳ���������á�##############################
//--------------����Ļ������������
#define SCREEN_X_WIDTH 128
#define SCREEN_Y_WIDTH 64
//--------------����Ļ����ҳ����		
#define SCREEN_X_PAGE SCREEN_X_WIDTH/6		//֧�ֶ��ٸ�Ĭ��6x8�ֿ�
#define SCREEN_Y_PAGE SCREEN_Y_WIDTH/8

//--------------��ѡ�������Ŀ��
#define OPTIONS_MAX	16

//--------------��FIFO��ֵ�����С��
#define FIFOBUF_SIZE		5

//--------------��ϵͳ���صİ�����ֵ��
#define	SOLGUI_KEY_UP		0x50	//�ϼ���ֵ
#define SOLGUI_KEY_DOWN		0x20	//�¼���ֵ
#define	SOLGUI_KEY_LEFT		0x30	//�����ֵ
#define SOLGUI_KEY_RIGHT	0x10	//�Ҽ���ֵ
#define SOLGUI_KEY_OK		0x40 	//OK���̰���ֵ
#define	SOLGUI_KEY_OK_L		0x40	//OK��������ֵ����û�г����������ö̰���ֵ���棬Ӱ�첻�󣩡�PS����ʱ����ʱ��̫�������ö̰����桿
#define	SOLGUI_KEY_BACK		0x60	//���ؼ���ֵ

//--------------��ϵͳͼ�����á�
#define	ICON_CURSOR 		0x86




//##############################�����ܿ��ء�##############################
//--------------���ֿ⿪�ء�
/*----------------Ĭ��ʹ��6x8����----------------*/
#define FONT4X6_EN 		0	 //����ʹ��4x6���壨1���ǣ�0����
#define FONT8X8_EN 		0	 //����ʹ��8x8���壨1���ǣ�0����
#define FONT8X10_EN		0	 //����ʹ��8x10���壨1���ǣ�0����

//--------------��ʹ��SOLGUI�˵����ǰ̨���ء�
#define MENU_FRAME_EN 	1	 //����SOLGUI�˵������Ϊǰ̨��1���ǣ�0���񣩣�ѡ����ֻ��ʹ�õ��м��

//--------------��Widget���ء�

#endif
