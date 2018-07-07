//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//
//  �� �� ��   : main.c
//  �� �� ��   : v2.0
//  ��    ��   : 
//  ��������   : 2014-0101
//  ����޸�   : 
//  ��������   : OLED 4�ӿ���ʾ����(51ϵ��)
//              ˵��: 
//              ----------------------------------------------------------------
//              GND    ��Դ��
//              VCC  ��5V��3.3v��Դ
//              SCL   P1^0
//              SDA   P1^1
//              RES  ��P12
//              DC   ��P13
//              CS   ��P14  -----��ģ��Ƭѡ���Ѿ����û��ӵأ������ٽ�                
//              ----------------------------------------------------------------
//******************************************************************************/
#include <STC15F2K60S2.H>
#ifndef __OLED_H
#define __OLED_H			  	 
//#include "sys.h"
//#include "stdlib.h"	  
#define  u8 unsigned char 
#define  u32 unsigned int 
#define OLED_CMD  0	//д����
#define OLED_DATA 1	//д����
#define OLED_MODE 1                       //1��IIC  0��SPI

#ifndef OK
#define OK 1
#endif

#ifndef ERROR
#define ERROR 0
#endif

#if OLED_MODE==0
sbit OLED_CS=P1^4; //Ƭѡ
sbit OLED_RST =P1^2;//��λ
sbit OLED_DC =P1^3;//����/�������
sbit OLED_SCL=P1^0;//ʱ�� D0��SCLK?
sbit OLED_SDIN=P1^1;//D1��MOSI�� ����


#define OLED_CS_Clr()  OLED_CS=0
#define OLED_CS_Set()  OLED_CS=1

#define OLED_RST_Clr() OLED_RST=0
#define OLED_RST_Set() OLED_RST=1

#define OLED_DC_Clr() OLED_DC=0
#define OLED_DC_Set() OLED_DC=1


#define OLED_SCLK_Clr() OLED_SCL=0
#define OLED_SCLK_Set() OLED_SCL=1

#define OLED_SDIN_Clr() OLED_SDIN=0
#define OLED_SDIN_Set() OLED_SDIN=1
#else
#include "i2c_master.h"
#include "intrins.h"
#define OLED_RST_Clr() _nop_()
#define OLED_RST_Set() _nop_()
#endif




//OLEDģʽ����
//0:4�ߴ���ģʽ
//1:����8080ģʽ

//#define SIZE 16
#define XLevelL		0x02
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF 
#define X_WIDTH 	128
#define Y_WIDTH 	64	    						  
//-----------------OLED�˿ڶ���----------------  					   

void delay_ms(unsigned int ms);


 		     

//OLED�����ú���
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);	   							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr);
//void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size2);
void OLED_ShowString(u8 x,u8 y, u8 *p);	 
void OLED_Set_Pos(unsigned char x, unsigned char y);
unsigned char OLED_ShowCHinese(u8 x,u8 y,u8 *Data);
void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[]);
unsigned char OLED_Size(unsigned char SizeData);


#endif  
	 


