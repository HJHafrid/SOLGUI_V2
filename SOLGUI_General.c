#include"pixelC_Hardware_include.h"

const unsigned char G6x8[][6] ={
0x00, 0x00, 0x00, 0x00, 0x00, 0x00,// sp
0x00, 0x00, 0x00, 0x2f, 0x00, 0x00,// !
0x00, 0x00, 0x07, 0x00, 0x07, 0x00,// "
0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14,// #
0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12,// $
0x00, 0x62, 0x64, 0x08, 0x13, 0x23,// %
0x00, 0x36, 0x49, 0x55, 0x22, 0x50,// &
0x00, 0x00, 0x05, 0x03, 0x00, 0x00,// '
0x00, 0x00, 0x1c, 0x22, 0x41, 0x00,// (
0x00, 0x00, 0x41, 0x22, 0x1c, 0x00,// )
0x00, 0x14, 0x08, 0x3E, 0x08, 0x14,// *
0x00, 0x08, 0x08, 0x3E, 0x08, 0x08,// +
0x00, 0x00, 0x00, 0xA0, 0x60, 0x00,// ,
0x00, 0x08, 0x08, 0x08, 0x08, 0x08,// -
0x00, 0x00, 0x60, 0x60, 0x00, 0x00,// .
0x00, 0x20, 0x10, 0x08, 0x04, 0x02,// /
0x00, 0x3E, 0x51, 0x49, 0x45, 0x3E,// 0
0x00, 0x00, 0x42, 0x7F, 0x40, 0x00,// 1
0x00, 0x42, 0x61, 0x51, 0x49, 0x46,// 2
0x00, 0x21, 0x41, 0x45, 0x4B, 0x31,// 3
0x00, 0x18, 0x14, 0x12, 0x7F, 0x10,// 4
0x00, 0x27, 0x45, 0x45, 0x45, 0x39,// 5
0x00, 0x3C, 0x4A, 0x49, 0x49, 0x30,// 6
0x00, 0x01, 0x71, 0x09, 0x05, 0x03,// 7
0x00, 0x36, 0x49, 0x49, 0x49, 0x36,// 8
0x00, 0x06, 0x49, 0x49, 0x29, 0x1E,// 9
0x00, 0x00, 0x36, 0x36, 0x00, 0x00,// :
0x00, 0x00, 0x56, 0x36, 0x00, 0x00,// ;
0x00, 0x08, 0x14, 0x22, 0x41, 0x00,// <
0x00, 0x14, 0x14, 0x14, 0x14, 0x14,// =
0x00, 0x00, 0x41, 0x22, 0x14, 0x08,// >
0x00, 0x02, 0x01, 0x51, 0x09, 0x06,// ?
0x00, 0x32, 0x49, 0x59, 0x51, 0x3E,// @
0x00, 0x7C, 0x12, 0x11, 0x12, 0x7C,// A
0x00, 0x7F, 0x49, 0x49, 0x49, 0x36,// B
0x00, 0x3E, 0x41, 0x41, 0x41, 0x22,// C
0x00, 0x7F, 0x41, 0x41, 0x22, 0x1C,// D
0x00, 0x7F, 0x49, 0x49, 0x49, 0x41,// E
0x00, 0x7F, 0x09, 0x09, 0x09, 0x01,// F
0x00, 0x3E, 0x41, 0x49, 0x49, 0x7A,// G
0x00, 0x7F, 0x08, 0x08, 0x08, 0x7F,// H
0x00, 0x00, 0x41, 0x7F, 0x41, 0x00,// I
0x00, 0x20, 0x40, 0x41, 0x3F, 0x01,// J
0x00, 0x7F, 0x08, 0x14, 0x22, 0x41,// K
0x00, 0x7F, 0x40, 0x40, 0x40, 0x40,// L
0x00, 0x7F, 0x02, 0x0C, 0x02, 0x7F,// M
0x00, 0x7F, 0x04, 0x08, 0x10, 0x7F,// N
0x00, 0x3E, 0x41, 0x41, 0x41, 0x3E,// O
0x00, 0x7F, 0x09, 0x09, 0x09, 0x06,// P
0x00, 0x3E, 0x41, 0x51, 0x21, 0x5E,// Q
0x00, 0x7F, 0x09, 0x19, 0x29, 0x46,// R
0x00, 0x46, 0x49, 0x49, 0x49, 0x31,// S
0x00, 0x01, 0x01, 0x7F, 0x01, 0x01,// T
0x00, 0x3F, 0x40, 0x40, 0x40, 0x3F,// U
0x00, 0x1F, 0x20, 0x40, 0x20, 0x1F,// V
0x00, 0x3F, 0x40, 0x38, 0x40, 0x3F,// W
0x00, 0x63, 0x14, 0x08, 0x14, 0x63,// X
0x00, 0x07, 0x08, 0x70, 0x08, 0x07,// Y
0x00, 0x61, 0x51, 0x49, 0x45, 0x43,// Z
0x00, 0x00, 0x7F, 0x41, 0x41, 0x00,// [
0x00, 0x55, 0x2A, 0x55, 0x2A, 0x55,// 55
0x00, 0x00, 0x41, 0x41, 0x7F, 0x00,// ]
0x00, 0x04, 0x02, 0x01, 0x02, 0x04,// ^
0x40, 0x40, 0x40, 0x40, 0x40, 0x40,// _
0x00, 0x00, 0x01, 0x02, 0x04, 0x00,// '
0x00, 0x20, 0x54, 0x54, 0x54, 0x78,// a
0x00, 0x7F, 0x48, 0x44, 0x44, 0x38,// b
0x00, 0x38, 0x44, 0x44, 0x44, 0x20,// c
0x00, 0x38, 0x44, 0x44, 0x48, 0x7F,// d
0x00, 0x38, 0x54, 0x54, 0x54, 0x18,// e
0x00, 0x08, 0x7E, 0x09, 0x01, 0x02,// f
0x00, 0x18, 0xA4, 0xA4, 0xA4, 0x7C,// g
0x00, 0x7F, 0x08, 0x04, 0x04, 0x78,// h
0x00, 0x00, 0x44, 0x7D, 0x40, 0x00,// i
0x00, 0x40, 0x80, 0x84, 0x7D, 0x00,// j
0x00, 0x7F, 0x10, 0x28, 0x44, 0x00,// k
0x00, 0x00, 0x41, 0x7F, 0x40, 0x00,// l
0x00, 0x7C, 0x04, 0x18, 0x04, 0x78,// m
0x00, 0x7C, 0x08, 0x04, 0x04, 0x78,// n
0x00, 0x38, 0x44, 0x44, 0x44, 0x38,// o
0x00, 0xFC, 0x24, 0x24, 0x24, 0x18,// p
0x00, 0x18, 0x24, 0x24, 0x18, 0xFC,// q
0x00, 0x7C, 0x08, 0x04, 0x04, 0x08,// r
0x00, 0x48, 0x54, 0x54, 0x54, 0x20,// s
0x00, 0x04, 0x3F, 0x44, 0x40, 0x20,// t
0x00, 0x3C, 0x40, 0x40, 0x20, 0x7C,// u
0x00, 0x1C, 0x20, 0x40, 0x20, 0x1C,// v
0x00, 0x3C, 0x40, 0x30, 0x40, 0x3C,// w
0x00, 0x44, 0x28, 0x10, 0x28, 0x44,// x
0x00, 0x1C, 0xA0, 0xA0, 0xA0, 0x7C,// y
0x00, 0x44, 0x64, 0x54, 0x4C, 0x44,// z
0x00, 0x82, 0x82, 0x6C, 0x10, 0x00,// {
0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,// |
0x00, 0x10, 0x6C, 0x82, 0x82, 0x00,// }
0x10, 0x20, 0x10, 0x08, 0x10, 0x00,//~
0x14, 0x14, 0x14, 0x14, 0x14, 0x14,// hirozy line
};

/************GRAM����************/
unsigned char SOLGUI_GRAM[X_WIDTH][Y_PAGE];
/************����ͼ�������ж���************/
unsigned int SOLGUI_Wave_CH1[X_WIDTH];		//���λ���1
unsigned int SOLGUI_Wave_CH2[X_WIDTH]; 		//���λ���2

//##############################API##############################

void SOLGUI_Init(void)
{
	SOLGUI_Graph_Wave_Init();
}

void SOLGUI_Refresh_GRAM()		//ˢ��GRAM
{
	int i=0,n=0,j=0;
	for(i=0;i<Y_PAGE;i++)
	{
		pixelC_HW_OLED_WrCmd(0xb0+i);
		pixelC_HW_OLED_WrCmd(0x00);
		pixelC_HW_OLED_WrCmd(0x10);
		for(n=0;n<X_WIDTH;n++)
		{
			pixelC_HW_OLED_WrDat(SOLGUI_GRAM[n][i]);
		}
	}	
	for(i=0;i<X_WIDTH;i++)
	{
		for(j=0;j<Y_PAGE;j++)
		{
			 SOLGUI_GRAM[i][j]=0;
		}
	}
}

void SOLGUI_DrawPoint(unsigned char x,unsigned char y,unsigned char t)			//���㣬t=1������t=0Ϩ��.
{
	unsigned char pos,bx,temp=0;
	if(x>=(X_WIDTH)||y>=(Y_WIDTH))	//0~127
	{
		return;//������Χ��.
	}
	pos=7-y/8;
	bx=y%8;
	temp=1<<(7-bx);
	if(t)
	{
		SOLGUI_GRAM[x][pos]|=temp;
	}
	else 
	{
		SOLGUI_GRAM[x][pos]&=~temp;
	}

}

//----------<�ַ���ʾ>

void SOLGUI_Show_Char(unsigned char x,unsigned char y,unsigned char ch,unsigned char mode)//��ʾ�����ַ���mode��1������ʾ��0������ʾ��
{
	unsigned char temp,t,tl;
	unsigned char y0=y;
	ch=ch-' ';
	for(t=0;t<6;t++)
	{
		 temp=G6x8[ch][t];
		 for(tl=0;tl<8;tl++)
		 {
		 	if(temp&0x80)
			{
				SOLGUI_DrawPoint(x,y,mode);
			}
			else
			{
				SOLGUI_DrawPoint(x,y,!mode);
			}
			temp<<=1;
			y++;
			if((y-y0)==8)
			{ 
				y=y0;
				x++;
				break;
			}
		 }
	}
}

void SOLGUI_Show_String(unsigned char x,unsigned char y,unsigned char *str,unsigned char mode)	//��ʾ�ַ�����mode��1������ʾ��0������ʾ��
{
	unsigned char j=0;
	while (str[j]!='\0')
	{		
		SOLGUI_Show_Char(x,y,str[j],mode);
		x+=6;
		j++;
	}
}

/***************************************************************************/

void SOLGUI_printf(
	unsigned char x,
	unsigned char y,
	unsigned char mode,
	const unsigned char* str,
	...					
)
{
	va_list arp;
	unsigned char xpp=x;
	unsigned char f,r,fl=0,l=3,lt;		//Ĭ����3λС��,С������0~7λ
	unsigned char i,j,w,lp;
	unsigned long v;
	char c, d, s[16], *p;
	int res, chc, cc,ll;
	int kh,kl,pow=1;
	double k;

	va_start(arp, str);								//�䳤����ջʼ����str

	for (cc=res=0;cc!=-1;res+=cc) 		   			//������ʽ���ַ����������
	{
		c = *str++;						   			//ÿһ��ȡһ���ַ�
//---------------------------------//��ȡ��'\0',��������
		if (c == 0) break;					
//---------------------------------//��ȡ����'%'����ʱ
		if (c != '%') {						
			//cc = f_putc(c, fil);		   			//��������ַ�
			SOLGUI_Show_Char(xpp,y,c,mode);
			xpp+=6;
			continue;
		}
//---------------------------------//��ȡ��'%'����ʱ
		w=f=0;
		k=0;
		lp=0;
		c=*str++;				   					//Խ��'%'�������ʽ
		if (c == '0') {								//%0��0���
			f = 1; c = *str++;						//f0�����λ��1����ȡ��һ���ַ�
		} 
		else if (c == '-') {							//%-������루�����ո�
				f = 2; c = *str++;					//f�������λ��1����ȡ��һ���ַ�
			}
		else if (c == '.') {						//%.3f��ʾ��3λС��
			fl=1;c=*str++;
		}

		while (((c)>='0')&&((c)<='9')) {			//"%030"����30ת��Ϊ����
			if(fl==1){
				lp=lp*10+c-'0';		
				c=*str++;
			}
			else{
				w=w*10+c-'0';		
				c=*str++;
			}								//�����ֶ���
		}
		if(fl==1) l=(lp>7)? 7:lp;
		if (c == 'l' || c == 'L') {					//%ld�ȳ�����
			f |= 4; c = *str++;		 				//f���α��λ��1������һ���ַ�
		}
		if (!c) break;								//�����ʱ���ַ����������
//---------------------------------//�����ʽ����ʶ����d,s,c,x,o,f��
		d = c;						
		if (((c)>='a')&&((c)<='z')) d -= 0x20;		//�����Сд������ɴ�д����
		switch (d) {								//����%*�����

		case 'S' :					/* String */
			p = va_arg(arp,char*);					//ȡ�ַ�������
			for(j=0;p[j];j++);						//���ȼ���
			ll=j;
			chc = 0;
			if (!(f&2)) {							//��������룬��߾�Ҫ���ո�%06s
				while (j++ < w) 
				{
					SOLGUI_Show_Char(xpp,y,' ',mode);
					chc+=1;
					xpp+=6;
				}
			}
			SOLGUI_Show_String(xpp,y,(unsigned char *)p,mode);
			xpp=xpp+6*ll;
			chc+=ll;
			while (j++ < w) 						//����룬��߾Ͳ��ÿո��ұ���ո�%-06s
			{
				SOLGUI_Show_Char(xpp,y,' ',mode);
				chc+=1;
				xpp+=6;
			}	 
			cc = chc;
			continue;

		case 'C' :
		{					/* Character */
		//	cc = f_putc((TCHAR)va_arg(arp, int), fil); continue;
			SOLGUI_Show_Char(xpp,y,(char)va_arg(arp,int),mode);
			xpp+=6;
			continue;
		}

		case 'F' :											//Ĭ�ϱ���3λС��
		{													/* double(64λ)/float(32λ) */												
			k=va_arg(arp,double);
			if(k<0){
				l|=8;
				k*=-1;										//�����õ�λ1
			}
			kh=(int)k;										//����С������
			lt=l&7;
			while((lt-1)>=0){
				pow*=10;
				lt--;
			}
			kl=(int)(pow*(k-kh));				
			i=0;

			lt=l&7;
			while(lt--){												//����С������
				if(kl){
					d=(char)(kl%10);							//��10����ȡ�࣬��ȡ��λ������Ϊ�ַ�����
					kl/=10;										//�ݽ�								
					s[i++]='0'+d;								//�������s
				}
				else s[i++]='0';
			}

			s[i++]='.';										//����С����
			do{												//������������
				d=(char)(kh%10);								//��10����ȡ�࣬��ȡ��λ������Ϊ�ַ�����
				kh/=10;										//�ݽ�
				s[i++]='0'+d;								//�������s
			}while(kh && i<sizeof s /sizeof s[0]);
			if (l&8)s[i++]='-';								//��ӷ��ţ�ע���λ��ǰ��
			fl=0;	
			goto PRT;
		}
		case 'B' :					/* Binary */
			r = 2; break;
		case 'O' :					/* Octal */
			r = 8; break;
		case 'D' :					/* Signed decimal */
		case 'U' :					/* Unsigned decimal */
			r = 10; break;
		case 'X' :					/* Hexdecimal */
			r = 16; break;
		default:{					/* Unknown type (pass-through) */
				SOLGUI_Show_Char(xpp,y,c,mode);
				xpp+=6;
				cc=1;
				continue;
			}
		}

		/* Get an argument and put it in numeral */
/*ȡ����  ��%ld�ͣ�		����longȡ����			û��l����d��intȡ����						û��lҲû��d���Ȱ�unsigned intȡ������������	*/
		v =(f&4)?(unsigned long)va_arg(arp, long):((d=='D')?(unsigned long)(long)va_arg(arp, int):(unsigned long)va_arg(arp, unsigned int));
		if (d == 'D' && (v & 0x80000000)) {					//��%d���ҷ���λΪ1��������	//ֻ��int��������֮��
			v = 0 - v;										//����Ϊ��������
			f |= 8;											//f���ű��λ��1
		}
		i = 0;
		do {												//���ֽ������ַ�
			d=(char)(v%r);									//������rȡ�࣬��ȡ��λ������Ϊ�ַ�����
			v/=r;											//�ݽ�
			if(d>9)d+=(c=='x')?0x27:0x07;					//�ж�������10���ƶ���16����ʱ��d���ȼ�һ�������ת��'A'(��дX)��'a'(СдX)
			s[i++]=d+'0';									//����Ϊ�ַ�������ע���λ��ǰ��
		} while (v && i<sizeof s /sizeof s[0]);				//��i<sizeof s /sizeof s[0]����ֹ��0����������
		if (f & 8) s[i++] = '-';							//��ӷ��ţ�ע���λ��ǰ��
PRT:		
		j=i;
		d=(f&1)?'0':' ';									//�ж�0��仹�������
		while (!(f&2)&&j++<w)
		{
			//res+=(cc = f_putc(d, fil));	//��������룬��߾�Ҫ��0��ո�
			SOLGUI_Show_Char(xpp,y,d,mode);
			xpp+=6;
		}
		do 
		{
			//res += (cc = f_putc(s[--i], fil)); 
			SOLGUI_Show_Char(xpp,y,s[--i],mode);
			xpp+=6;
		}while(i);

		while (j++ < w) 
		{
			//res += (cc = f_putc(' ', fil));		//�ұ߲��ո�
			SOLGUI_Show_Char(xpp,y,d,mode);
			xpp+=6;
		}
	}
	va_end(arp);
}

/***************************************************************************/

//-------------------------------------------
//----------<ͼ����ʾ>

char SOLGUI_Find_Max(char input[],char num) 				//���������ֵ
{
	int i;
	char max;
	max=input[0];
	for(i=1;i<num;i++)
	{
		if(input[i]>max)
		{
			max=input[i];
		}
	}
	return(max);
}

char SOLGUI_Find_Min(char input[],char num) 				//���������ֵ
{
	int i;
	char min;
	min=input[0];
	for(i=1;i<num;i++)
	{
		if(input[i]<min)
		{
			min=input[i];
		}
	}
	return(min);
}

void SOLGUI_Graph_line(			unsigned char x0,unsigned char y0,		 //����	��mode��0�����ߣ�1ʵ�ߣ�2���ߣ�3�̻��ߣ�
								unsigned char xEnd,unsigned char yEnd,
								unsigned char mode)		
{
	int dx=xEnd-x0;
	int dy=yEnd-y0;
	int ux=((dx>0)<<1)-1;//x����������ȡ��-1
	int uy=((dy>0)<<1)-1;//y����������ȡ��-1
	int x=x0,y=y0,eps;//epsΪ�ۼ����
	unsigned char cnt=0;
	
	eps=0;
	dx=SOLGUI_Fabs(dx);
	dy=SOLGUI_Fabs(dy); 
	if(dx>dy) 
	{
		for(x=x0;x!=xEnd+ux;x+=ux)
		{
			cnt++;
			switch(mode)
			{
				case 0:SOLGUI_DrawPoint(x,y,0);break;  			//0������
				case 1:
				{
					SOLGUI_DrawPoint(x,y,1);break;	   			//1ʵ��
				}
				case 2:
				{
					if(cnt%2>=1)SOLGUI_DrawPoint(x,y,1); 	//2����	
					else	SOLGUI_DrawPoint(x,y,0);break;	
				}
				case 3:
				{
					if(cnt%4>=2)SOLGUI_DrawPoint(x,y,1);  		//3�̻���
					else	SOLGUI_DrawPoint(x,y,0);break;		
				}	
			}
			eps+=dy;
			if((eps<<1)>=dx)
			{
				y+=uy;
				eps-=dx;
			}
		}
	}
	else
	{
		for(y=y0;y!=yEnd+uy;y+=uy)
		{
			cnt++;
			switch(mode)
			{
				case 0:SOLGUI_DrawPoint(x,y,0);break;  			//0������
				case 1:
				{
					SOLGUI_DrawPoint(x,y,1);break;	   			//1ʵ��
				}
				case 2:
				{
					if(cnt%2>=1)SOLGUI_DrawPoint(x,y,1); 	//2����	
					else	SOLGUI_DrawPoint(x,y,0);break;	
				}
				case 3:
				{
					if(cnt%4>=2)SOLGUI_DrawPoint(x,y,1);  		//3�̻���
					else	SOLGUI_DrawPoint(x,y,0);break;		
				}	
			}
			eps+=dx;
			if((eps<<1)>=dy)
			{
				x+=ux; 
				eps-=dy;
			}
		}
	}   


		
     

}

void SOLGUI_Graph_Circle(unsigned char x0,unsigned char y0,unsigned char r,unsigned char mode)			//��Բ��Բ�ģ��뾶��1����0Ϩ��
{
	int x,y,s;
	for(x=x0-r;x<=x0+r;x++){	
		for(y=y0-r;y<=y0+r;y++){	
			s=(x-x0)*(x-x0)+(y-y0)*(y-y0);	
			if(s-r*r<r&&s-r*r>-r)
			SOLGUI_DrawPoint(x,y,mode);
		}	
	}	
}

void SOLGUI_Graph_pictrue(	unsigned char x,			//���x����	 	//ͼ��
							unsigned char y,			//���y����
							unsigned char x_len,		//ͼ�γ�
							unsigned char y_len,		//ͼ�ο�
							unsigned char *pic,			//ͼ
							unsigned char mode 			//��ʾ��ʽ��1������ʾ��0������ʾ
							)
{
	int y_i=0,y_j=0,x_i=0,lie;
	unsigned char temp;

	if(y_len%8!=0)
	{
		lie=y_len/8+1;	
	}
	else
	{
		lie=y_len/8;
	}
	for(y_j=0;y_j<lie;y_j++)
	{
		for(x_i=0;x_i<x_len;x_i++)
		{
			temp=*(pic+y_j*x_len+x_i);
			for(y_i=0;y_i<8;y_i++)
			{
				if(temp&0x80)
				{
					 SOLGUI_DrawPoint(x+x_i,y+y_i-y_j*8-8,mode);
				}
				else
				{
					 SOLGUI_DrawPoint(x+x_i,y+y_i-y_j*8-8,!mode); 
				}
				temp<<=1;
			}
		}
	}
}


//----------<ͼ����ʾ>

void SOLGUI_Plot_Bar(unsigned char x,			//���x����	 	//��ֵ��(��ʾ��ֵ��Դ�С)
					unsigned char y,			//���y����
					unsigned char x_len,		//ͼ�γ�
					unsigned char y_len,		//ͼ�ο�
					int graduated_max,			//������ֵ
					int graduated_min,			//�����Сֵ
					int Var_in,					//ֵ����
					unsigned char mode 			//��ʾ��ʽ��0��������1λ����
)
{
	int i,j;
	double Y_zoom,X_zoom;
	unsigned char temp;	

	if(x_len>=y_len)		//X��������
	{
//---------------<����ϵ��>-------------------
		X_zoom=(double)(x_len)/(double)(graduated_max-graduated_min);		//����һ�������Ƕ���ֵ
		temp=(unsigned char)((Var_in-graduated_min)*X_zoom);								//Ӧ����ʾ�����س���
//---------------<��ͼ>-------------------
		if(mode==0)
		{
			for(i=0;i<x_len;i++)
			{
				SOLGUI_DrawPoint(x+i,y,1);			   //�߿�����
				SOLGUI_DrawPoint(x+i,y+y_len,1);
			}
			for(i=0;i<y_len+1;i++)
			{
				SOLGUI_DrawPoint(x,y+i,1);			   //�߿�����
				SOLGUI_DrawPoint(x+x_len,y+i,1);
			}
			for(i=0;i<temp;i++)
			{
				for(j=0;j<y_len;j++)
				{
					if(temp>x_len)	temp=x_len;
					SOLGUI_DrawPoint(x+i,y+j,1);			//���ɫ�����
				}
			}
		}
		else if(mode==1)
		{
			for(i=0;i<x_len;i++)
			{
				SOLGUI_DrawPoint(x+i,y,1);			   //�߿�����
			}
			for(i=0;i<y_len+1;i++)
			{
				SOLGUI_DrawPoint(x,y+i,1);			   //�߿�����
				SOLGUI_DrawPoint(x+x_len,y+i,1);
			}
			for(j=0;j<y_len;j++)
			{
				if(temp>x_len)	temp=x_len;
				SOLGUI_DrawPoint(x+temp,y+j,1);			//���ɫ�����
			}
		}
			
	}
	else				//Y��������
	{

//---------------<����ϵ��>-------------------
		Y_zoom=(double)(y_len)/(double)(graduated_max-graduated_min);		//����һ�������Ƕ���ֵ
		temp=(unsigned char)((Var_in-graduated_min)*Y_zoom);								//Ӧ����ʾ�����س���
//---------------<��ͼ>-------------------
		if(mode==0)
		{
			for(i=0;i<y_len;i++)
			{
				SOLGUI_DrawPoint(x,y+i,1);
				SOLGUI_DrawPoint(x+x_len,y+i,1);
			}
			for(i=0;i<x_len+1;i++)
			{
				SOLGUI_DrawPoint(x+i,y,1);
				SOLGUI_DrawPoint(x+i,y+y_len,1);
			}
			for(i=0;i<temp;i++)
			{
				for(j=0;j<x_len;j++)
				{
					if(temp>y_len)	temp=y_len;
					SOLGUI_DrawPoint(x+j,y+i,1);
				}
			}
		}
		else if(mode==1)
		{
			for(i=0;i<y_len;i++)
			{
				SOLGUI_DrawPoint(x+x_len,y+i,1);
			}
			for(i=0;i<x_len+1;i++)
			{
				SOLGUI_DrawPoint(x+i,y,1);
				SOLGUI_DrawPoint(x+i,y+y_len,1);
			}
			for(j=0;j<x_len;j++)
			{
				if(temp>y_len)	temp=y_len;	
				SOLGUI_DrawPoint(x+j,y+temp,1);
			}
		}

	}	
}


void OLED_Plot_Oscillogram(	unsigned char x,			//���x����	 	//����ͼ(��ʾ����)
							unsigned char y,			//���y����
							unsigned char x_len,		//ͼ�γ�
							unsigned char y_len,		//ͼ�ο�
							int graduated_max,			//������ֵ
							int graduated_min,			//�����Сֵ
							unsigned char dis_num,		//Ҫ��ʾ�����ݸ�����wave_in[0]~wave_in[dis_num]��
							int wave_in[]				//��������
							)
{
	int i;
	double Y_zoom,X_zoom,x_count=0;
	char temp;
	int last_x=x,last_y=y;

	x_len-=1;
	y_len-=1;
	if((x+x_len)>X_WIDTH)	x_len=X_WIDTH-x-1; //��λ
	if((y+y_len)>Y_WIDTH)	y_len=Y_WIDTH-y-1;
//------------<��������ʾ>-------------------
	SOLGUI_DrawPoint(x,y,1);					//��ʼ��ͼ��
	for(i=1;i<x_len;i++)
	{
		SOLGUI_DrawPoint(x+i,y,1);			//x��
	}
	SOLGUI_DrawPoint(x+x_len-1,y+1,1);
	for(i=1;i<y_len;i++)
	{
		SOLGUI_DrawPoint(x,y+i,1);			//y��
	}
	SOLGUI_DrawPoint(x+1,y+y_len-1,1);
//---------------<����ϵ��>-------------------
	X_zoom=(double)(dis_num)/(double)(x_len);							//����
	Y_zoom=(double)(y_len)/(double)(graduated_max-graduated_min);		//����һ�������Ƕ���ֵ
//---------------<������ʾ����>---------------
	for(i=0;i<x_len;i++)
	{
		x_count+=X_zoom;
		if((wave_in[(int)x_count]>=graduated_min)&&(wave_in[(int)x_count]<graduated_max))
		{
			temp=(unsigned char)((wave_in[(int)x_count]-graduated_min)*Y_zoom);
			SOLGUI_Graph_line(last_x,last_y,x+i,(y+temp),1);
			last_x=x+i;
			last_y=(y+temp);
		}
	}
}

void SOLGUI_Graph_Wave_Init()								//����RAM��ʼ��
{
	int i;
	for(i=0;i<X_WIDTH;i++)
	{
		SOLGUI_Wave_CH1[i]=0;
		SOLGUI_Wave_CH2[i]=0;
	}
}

void SOLGUI_Plot_Waveform(	unsigned char x,			//���x����	 	//����ͼ��(��ʾ��ֵʱ�򲨶�)
							unsigned char y,			//���y����
							unsigned char x_len,		//ͼ�γ�
							unsigned char y_len,		//ͼ�ο�
							int graduated_max,			//������ֵ
							int graduated_min,			//�����Сֵ
							unsigned char channel,		//ʹ��ͨ��
							int Var_in					//����ʾ���εı���
							)
{
	int i,fwd,bck;
	double Y_zoom,X_zoom,x_count=0;
	char temp;
	int last_x=x,last_y=y;

	x_len-=1;
	y_len-=1;
	if((x+x_len)>X_WIDTH)	x_len=X_WIDTH-x-1; //��λ
	if((y+y_len)>Y_WIDTH)	y_len=Y_WIDTH-y-1;
//------------<��������ʾ>-------------------
	SOLGUI_DrawPoint(x,y,1);					//��ʼ��ͼ��
	for(i=1;i<x_len;i++)
	{
		SOLGUI_DrawPoint(x+i,y,1);			//x��
	}
	SOLGUI_DrawPoint(x+x_len-1,y+1,1);
	for(i=1;i<y_len;i++)
	{
		SOLGUI_DrawPoint(x,y+i,1);			//y��
	}
	SOLGUI_DrawPoint(x+1,y+y_len-1,1);
//---------------<����ϵ��>-------------------
	X_zoom=(double)(X_WIDTH)/(double)(x_len);							//����
	Y_zoom=(double)(y_len)/(double)(graduated_max-graduated_min);		//����һ�������Ƕ���ֵ

	if(channel==2)							//ͨ��ѡ��Ĭ��1ͨ����
	{
//---------------<���ɱ�������>---------------
		for(fwd=0,bck=1;bck<X_WIDTH;fwd++,bck++)
		{
			SOLGUI_Wave_CH2[fwd]=SOLGUI_Wave_CH2[bck];
		}
		SOLGUI_Wave_CH2[X_WIDTH-1]=Var_in;
//---------------<������ʾ����>---------------
		for(i=0;i<x_len;i++)
		{
			x_count+=X_zoom;
			if((SOLGUI_Wave_CH2[(int)x_count]>=graduated_min)&&(SOLGUI_Wave_CH2[(int)x_count]<graduated_max))
			{
				temp=(unsigned char)((SOLGUI_Wave_CH2[(int)x_count]-graduated_min)*Y_zoom);
				SOLGUI_Graph_line(last_x,last_y,x+i,(y+temp),1);
				last_x=x+i;
				last_y=(y+temp);
			}
		}
	}
	else
	{
//---------------<���ɱ�������>---------------
		for(fwd=0,bck=1;bck<X_WIDTH;fwd++,bck++)
		{
			SOLGUI_Wave_CH1[fwd]=SOLGUI_Wave_CH1[bck];
		}
		SOLGUI_Wave_CH1[X_WIDTH-1]=Var_in;
//---------------<������ʾ����>---------------
		for(i=0;i<x_len;i++)
		{
			x_count+=X_zoom;
			if((SOLGUI_Wave_CH1[(int)x_count]>=graduated_min)&&(SOLGUI_Wave_CH1[(int)x_count]<graduated_max))
			{
				temp=(unsigned char)((SOLGUI_Wave_CH1[(int)x_count]-graduated_min)*Y_zoom);
				SOLGUI_Graph_line(last_x,last_y,x+i,(y+temp),1);
				last_x=x+i;
				last_y=(y+temp);
			}
		}
	}
}

