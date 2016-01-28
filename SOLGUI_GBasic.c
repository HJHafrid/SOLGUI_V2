#include"SOLGUI_Include.h"



void SOLGUI_GBasic_Line(u32 x0,u32 y0,u32 xEnd,u32 yEnd,u8 mode)		//���ߣ�mode��0�����ߣ�1ʵ�ߣ�2���ߣ�3�̻��ߣ�
{
	s16 dx=xEnd-x0;
	s16 dy=yEnd-y0;
	s16 ux=((dx>0)<<1)-1;//x����������ȡ��-1
	s16 uy=((dy>0)<<1)-1;//y����������ȡ��-1
	s16 x=x0,y=y0,eps;//epsΪ�ۼ����
	u32 cnt=0;
	
	eps=0;
	dx=SOLGUI_Fabs(dx);
	dy=SOLGUI_Fabs(dy); 
	if(dx>dy) 
	{
		for(x=x0;x!=xEnd+ux;x+=ux)
		{
			cnt++;
			switch(mode&0x03)
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
			switch(mode&0x03)
			{
				case 0:SOLGUI_DrawPoint(x,y,0);break;  			//0������
				case 1:
				{
					SOLGUI_DrawPoint(x,y,1);break;	   			//1ʵ��
				}
				case 2:
				{
					if(cnt%2>=1)SOLGUI_DrawPoint(x,y,1); 		//2����	
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

void  GUI_GBasic_Rectangle(u32 x0,u32 y0,u32 x1,u32 y1,u8 mode)		//�����Σ����½ǣ����Ͻǣ�ģʽ��
{
	u32 i=0;
	if(mode&0x04)	//���
	{
		if(x0>x1) {i=x0;x0=x1;x1=i;}	//��x0>x1����x0��x1����
		if(y0>y1) {i=y0;y0=y1;y1=i;}	//��y0>y1����y0��y1����
		if(y0==y1) 
		{  
			SOLGUI_GBasic_Line(x0,y0,x1,y0,ACTUAL);
			return;
		}
		if(x0==x1) 
		{  
			SOLGUI_GBasic_Line(x0,y0,x0,y1,ACTUAL);
			return;
		}						
		while(y0<=y1)						
		{  
			SOLGUI_GBasic_Line(x0,y0,x1,y0,ACTUAL);
			y0++;				
		}
	}
	else			   //�����
	{
		SOLGUI_GBasic_Line(x0,y0,x0,y1,mode);
		SOLGUI_GBasic_Line(x0,y1,x1,y1,mode);
		SOLGUI_GBasic_Line(x1,y0,x1,y1,mode);
		SOLGUI_GBasic_Line(x0,y0,x1,y0,mode);
	}
}

void GUI_GBasic_MultiLine(const u32 *points,u8 num,u8 mode)
{
	u32 x0,y0;
	u32 x1,y1;
	u8 i=0;
	if(num<=0) return;		//û�е�
	if(1==num)						// ����
	{  
		x0=*points++;
		y0=*points;
		SOLGUI_DrawPoint(x0,y0,1);
	}
   
   /* ���������� */
	x0=*points++;					// ȡ����һ������ֵ����Ϊԭ�������ֵ
	y0=*points++;
	for(i=1;i<num;i++)
	{  
		x1=*points++;				// ȡ����һ������ֵ
		y1=*points++;
		SOLGUI_GBasic_Line(x0,y0,x1,y1,mode);
		x0=x1;					// ����ԭ�������
		y0=y1;
	}

}

void SOLGUI_GBasic_Circle(u32 x0,u32 y0,u32 r,u8 mode)			//��Բ��Բ�ģ��뾶��1����0Ϩ��
{
	s32  draw_x0, draw_y0;			// ��ͼ���������
	s32  draw_x1, draw_y1;	
	s32  draw_x2, draw_y2;	
	s32  draw_x3, draw_y3;	
	s32  draw_x4, draw_y4;	
	s32  draw_x5, draw_y5;	
	s32  draw_x6, draw_y6;	
	s32  draw_x7, draw_y7;	
	s32  xx, yy;					// ��Բ���Ʊ���
	s32  di;						// ���߱���
   
   /* �������� */
   if(0==r) return;
   
   /* �����8�������(0��45��90��135��180��225��270��)��������ʾ */
   draw_x0 = draw_x1 = x0;
   draw_y0 = draw_y1 = y0 + r;
   if(draw_y0<SCREEN_Y_WIDTH) SOLGUI_DrawPoint(draw_x0,draw_y0,mode);	// 90��
	
   draw_x2 = draw_x3 = x0;
   draw_y2 = draw_y3 = y0 - r;
   if(draw_y2>=0) SOLGUI_DrawPoint(draw_x2,draw_y2,mode);			// 270��
   
	
   draw_x4 = draw_x6 = x0 + r;
   draw_y4 = draw_y6 = y0;
   if(draw_x4<SCREEN_X_WIDTH) SOLGUI_DrawPoint(draw_x4,draw_y4,mode);	// 0��
   
   draw_x5 = draw_x7 = x0 - r;
   draw_y5 = draw_y7 = y0;
   if(draw_x5>=0) SOLGUI_DrawPoint(draw_x5,draw_y5,mode);			// 180��   
   if(1==r) return;					// ���뾶Ϊ1������Բ����
   
   
   /* ʹ��Bresenham�����л�Բ */
   di = 3 - 2*r;					// ��ʼ�����߱���
   
   xx = 0;
   yy = r;	
   while(xx<yy)
   {  if(di<0)
	  {  di += 4*xx + 6;	      
	  }
	  else
	  {  di += 4*(xx - yy) + 10;
	  
	     yy--;	  
		 draw_y0--;
		 draw_y1--;
		 draw_y2++;
		 draw_y3++;
		 draw_x4--;
		 draw_x5++;
		 draw_x6--;
		 draw_x7++;	 	
	  }
	  
	  xx++;   
	  draw_x0++;
	  draw_x1--;
	  draw_x2++;
	  draw_x3--;
	  draw_y4++;
	  draw_y5++;
	  draw_y6--;
	  draw_y7--;
		
	
	  /* Ҫ�жϵ�ǰ���Ƿ�����Ч��Χ�� */
	  if( (draw_x0<=SCREEN_X_WIDTH)&&(draw_y0>=0) )	
	  {  SOLGUI_DrawPoint(draw_x0, draw_y0,mode);
	  }	    
	  if( (draw_x1>=0)&&(draw_y1>=0) )	
	  {  SOLGUI_DrawPoint(draw_x1, draw_y1,mode);
	  }
	  if( (draw_x2<=SCREEN_X_WIDTH)&&(draw_y2<=SCREEN_Y_WIDTH) )	
	  {  SOLGUI_DrawPoint(draw_x2, draw_y2,mode);   
	  }
	  if( (draw_x3>=0)&&(draw_y3<=SCREEN_Y_WIDTH) )	
	  {  SOLGUI_DrawPoint(draw_x3, draw_y3,mode);
	  }
	  if( (draw_x4<=SCREEN_X_WIDTH)&&(draw_y4>=0) )	
	  {  SOLGUI_DrawPoint(draw_x4, draw_y4,mode);
	  }
	  if( (draw_x5>=0)&&(draw_y5>=0) )	
	  {  SOLGUI_DrawPoint(draw_x5, draw_y5,mode);
	  }
	  if( (draw_x6<=SCREEN_X_WIDTH)&&(draw_y6<=SCREEN_Y_WIDTH) )	
	  {  SOLGUI_DrawPoint(draw_x6, draw_y6,mode);
	  }
	  if( (draw_x7>=0)&&(draw_y7<=SCREEN_Y_WIDTH) )	
	  {  SOLGUI_DrawPoint(draw_x7, draw_y7,mode);
	  }
   }	
}



