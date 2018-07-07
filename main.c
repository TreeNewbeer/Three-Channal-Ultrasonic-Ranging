

#include <STC15F2K60S2.H>
#include "Mid_oled.h"
#include <stdio.h>
#include "delay.h"

//#include "bmp.h"

sbit Tx  = P3^2;     //产生脉冲引脚，延时 20us
sbit Rx  = P3^3;    //回波引脚，进入外部中断 1。这些引脚可随意改变。

sbit Tx1 = P1^3;
sbit Rx1 = P1^2;

sbit Tx2 = P1^5;
sbit Rx2 = P1^4;

sbit LED = P5^5;
bit TimeUp = 0;   //定时器溢出标志位
long xdata Th0,Tl0,Th1,Tl1,Th2,Tl2;
unsigned long time0 = 0;
unsigned int Measureresult = 0;


void GPIO_Init(void)
{
	P1M0 = 0;  P1M1 = 0;
	P2M0 = 0;  P2M1 = 0;
	P3M0 = 0;  P3M1 = 0;
	P5M0 = 0;  P5M1 = 0;
}


unsigned int Measure(void)
{
	char Del20us = 0;                 //延时变量，在超声波脉冲引脚中产生 20us 的方波
	char RxBack = 1;                 //超声波返回标志位
	TMOD = 0x01;                    //定时器工作方式 1：16 位，初值不能重装
	Tx = 0;                        //将超声波脉冲引脚电位拉低
	Th0 = 0;                      //初始化变量值
	Tl0 = 0;                     //初始化变量值
	TimeUp = 0;                 //初始化
	EA = 1;
	ET0 = 1;                  //开定时器 0 中断TR0=0;//关定时器 0
	TH0 = 0;                 //赋定时器初始值高 8 位为 0
	TL0 = 0;                //赋定时器初始值低 8 位为 0
	Tx = 1;                //拉高超声波脉冲引脚电位
	for(Del20us = 20;Del20us > 0;Del20us--);//延时 20us
	Tx = 0;              //拉低超声波脉冲引脚电位，使之产生 20us 的方波信号，使超声波模块开始工作。
	while(Rx == 0);     //等待回波引脚变 1；
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;          //开定时器 0
	               //使用软件查询的方式，检测超声波回波引脚，判断是否有声波返回，避免使用外部中断的
	              //形式，便于扩展多个超声波模块。
	while(RxBack)
	{
		if(Rx == 0 || TimeUp == 1)
			{
				TR0 = 0;
				Th0 = TH0;
				Tl0 = TL0;
				TR0 = 1;
				RxBack = 0;
			}
	}
	while(!TimeUp);                                         //等待定时器溢出
	time0 = (Th0 * 256 + Tl0);                             //取出定时器的值
	Measureresult = ((unsigned long)(344) * time0) / 2000;//测量的结果单位为 mm
	if(Measureresult < 30 || Measureresult > 900)
		{
			Measureresult = 0;
		}	                        //过滤掉一些异常的数据，当测量出的距离不在 30－900mm 时返回值为 0
	return Measureresult;
}


unsigned int Measure_Sec(void)
{
	char Del20us = 0;                 //延时变量，在超声波脉冲引脚中产生 20us 的方波
	char RxBack = 1;                 //超声波返回标志位
	TMOD = 0x01;                    //定时器工作方式 1：16 位，初值不能重装
	Tx1 = 0;                        //将超声波脉冲引脚电位拉低
	Th1 = 0;                      //初始化变量值
	Tl1 = 0;                     //初始化变量值
	TimeUp = 0;                 //初始化
	EA = 1;
	ET0 = 1;                  //开定时器 0 中断TR0=0;//关定时器 0
	TH0 = 0;                 //赋定时器初始值高 8 位为 0
	TL0 = 0;                //赋定时器初始值低 8 位为 0
	Tx1 = 1;                //拉高超声波脉冲引脚电位
	for(Del20us=20;Del20us>0;Del20us--);//延时 20us
	Tx1 = 0;              //拉低超声波脉冲引脚电位，使之产生 20us 的方波信号，使超声波模块开始工作。
	while(Rx1 == 0);     //等待回波引脚变 1；
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;          //开定时器 0
	                 //使用软件查询的方式，检测超声波回波引脚，判断是否有声波返回，避免使用外部中断的
	                //形式，便于扩展多个超声波模块。
	while(RxBack)
	{
		if(Rx1 == 0 || TimeUp == 1)
			{
				TR0 = 0;
				Th1 = TH0;
				Tl1 = TL0;
				TR0 = 1;
				RxBack = 0;
			}
	}
	while(!TimeUp);                                   //等待定时器溢出
	time0 = (Th1*256 + Tl1);                             //取出定时器的值
	Measureresult = ((unsigned long)(344) * time0) / 2000;//测量的结果单位为 mm
	if(Measureresult < 30 || Measureresult > 900)
		{
			Measureresult = 0;
		}	                        //过滤掉一些异常的数据，当测量出的距离不在 30－900mm 时返回值为 0
	return Measureresult;
}



unsigned int Measure_Thr(void)
{
	char Del20us = 0;                 //延时变量，在超声波脉冲引脚中产生 20us 的方波
	char RxBack = 1;                 //超声波返回标志位
	TMOD = 0x01;                    //定时器工作方式 1：16 位，初值不能重装
	Tx2 = 0;                        //将超声波脉冲引脚电位拉低
	Th2 = 0;                      //初始化变量值
	Tl2 = 0;                     //初始化变量值
	TimeUp = 0;                 //初始化
	EA = 1;
	ET0 = 1;                  //开定时器 0 中断TR0=0;//关定时器 0
	TH0 = 0;                 //赋定时器初始值高 8 位为 0
	TL0 = 0;                //赋定时器初始值低 8 位为 0
	Tx2 = 1;                //拉高超声波脉冲引脚电位
	for(Del20us=20;Del20us>0;Del20us--);//延时 20us
	Tx2 = 0;              //拉低超声波脉冲引脚电位，使之产生 20us 的方波信号，使超声波模块开始工作。
	while(Rx2 == 0);     //等待回波引脚变 1；
	TH0 = 0;
	TL0 = 0;
	TR0 = 1;          //开定时器 0
	               //使用软件查询的方式，检测超声波回波引脚，判断是否有声波返回，避免使用外部中断的
	              //形式，便于扩展多个超声波模块。
	while(RxBack)
	{
		if(Rx2 == 0 || TimeUp == 1)
			{
				TR0 = 0;
				Th2 = TH0;
				Tl2 = TL0;
				TR0 = 1;
				RxBack = 0;
			}
	}
	while(!TimeUp);                                   //等待定时器溢出
	time0 = (Th2 * 256 + Tl2);                             //取出定时器的值
	Measureresult = ((unsigned long)(344) * time0) / 2000;//测量的结果单位为 mm
	if(Measureresult < 30 || Measureresult > 900)
		{
			Measureresult = 0;
		}	                        //过滤掉一些异常的数据，当测量出的距离不在 30－900mm 时返回值为 0
	return Measureresult;
}



void T0_time() interrupt 1
{
	TimeUp = 1;
}

void main(void)
{
	unsigned int ge,shi,bai;
	unsigned char flag;
	unsigned int j = 0;
	GPIO_Init();
	Mid_oled_Display_Control(DisInit);
	Mid_oled_Display_Control(Char_Size_16);
	LED = 1;
	while(1)
	{
		ge   = Measure()%100%10;
		shi  = Measure()%100/10;
		bai  = Measure()/100;
		ShowData(2,0,bai);
		ShowData(2,10,shi);
		ShowData(2,20,ge);
		ge  = Measure_Sec()%100%10;
		shi = Measure_Sec()%100/10;
		bai = Measure_Sec()/100;
		ShowData(4,0,bai);
		ShowData(4,10,shi);
		ShowData(4,20,ge);
		ge  = Measure_Thr()%100%10;
		shi = Measure_Thr()%100/10;
		bai = Measure_Thr()/100;
		ShowData(6,0,bai);
		ShowData(6,10,shi);
		ShowData(6,20,ge);
		flag = 0;	
		Mid_oled_Display_Show(30,2,ShowString,"mm",NULL);		
		Mid_oled_Display_Show(30,4,ShowString,"mm",NULL);	
		Mid_oled_Display_Show(30,6,ShowString,"mm",NULL);
		LED = 0;
		delayms(50);
		LED = 1;
		delayms(50);
	}
}
