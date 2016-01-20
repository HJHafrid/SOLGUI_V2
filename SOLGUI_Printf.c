#include"SOLGUI_Include.h"
#include"SOLGUI_Font6x8.h"
#include<stdarg.h> 						//֧�ֱ䳤����



//----------------������Ļ������ַ���
void SOLGUI_Show_Char(u8 x,u8 y,u8 ch,u8 mode)//��ʾ�����ַ���mode��1������ʾ��0������ʾ��
{
	unsigned char temp,t,tl;
	unsigned char y0=y;
	ch=ch-' ';
	for(t=0;t<6;t++)
	{
		 temp=_Font6x8[ch][t];
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

//----------------������Ļ������ַ�����

void SOLGUI_Show_String(u8 x,u8 y,u8 *str,u8 mode)	//��ʾ�ַ�����mode��1������ʾ��0������ʾ��
{
	unsigned char j=0;
	while (str[j]!='\0')
	{		
		SOLGUI_Show_Char(x,y,str[j],mode);
		x+=6;
		j++;
	}
}

//----------------������Ļ�ϸ�ʽ������ַ�����

void SOLGUI_printf(u8 x,u8 y,u8 mode,const u8* str,...)
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

