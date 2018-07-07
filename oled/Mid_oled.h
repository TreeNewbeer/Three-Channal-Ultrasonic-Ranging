
#ifndef __MID_OLED_H
#define __MID_OLED_H

#include <STC15F2K60S2.H>
#include <stdio.h>
#include "oled.h"

#ifndef uchar
#define uchar unsigned char
#endif

#ifndef OK
#define OK 1
#endif

#ifndef ERROR
#define ERROR 0
#endif

#ifndef NULL
 #define NULL ((void *) 0)
#endif

//ControlVal
#define DisOff 0
#define DisOn 1
#define DisClear 2
#define DisInit 3
#define Char_Size_12 4
#define Char_Size_16 5
uchar Mid_oled_Display_Control(uchar ControlData);

//FunVal
#define ShowChar 0
#define ShowString 1
#define ShowCHinese 2
#define ShowBmp 3

uchar Mid_oled_Display_Show(uchar Ypos,uchar Xpos,uchar Fun,uchar *Data,uchar *Size);		//Size[0] ImgYSize,Size[1] ImgXsize
void ShowData(uchar Ypos,uchar Xpos,unsigned int dat);

#endif
