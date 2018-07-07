#include"Mid_oled.h"

uchar Mid_oled_Display_Control(uchar ControlData)
{	
	switch(ControlData)
	{
		case DisOff:
		{
			OLED_Display_Off();
		}break;
		case DisOn:
		{
			OLED_Display_On();
		}break;
		case DisClear:
		{
			OLED_Clear();
		}break;
		case DisInit:
		{
			OLED_Init();
			OLED_Display_On();
			OLED_Size(12);
		}break;
		case Char_Size_12:
		{
			OLED_Size(12);
		}break;
		case Char_Size_16:
		{
			OLED_Size(16);
		}break;
		default:return ERROR;break;
	}

	return OK;
}




uchar Mid_oled_Display_Show(uchar Xpos,uchar Ypos,uchar Fun,uchar *Data,uchar *Size)   //ÁÐÐÐ
{
	switch(Fun)
	{
		case ShowChar:
		{
			OLED_ShowChar(Xpos,Ypos,*Data);
		}break;
		case ShowString:
		{
			OLED_ShowString(Xpos,Ypos,Data);	
		}break;
		case ShowCHinese:
		{
			OLED_ShowCHinese(Xpos,Ypos,Data);	
		}break;
		case ShowBmp:
		{
			OLED_DrawBMP(Xpos, Ypos,Xpos+Size[1], Ypos+Size[0],Data);
		}break;
		default:return ERROR;break;
	}
	return OK;
}


void ShowData(uchar Ypos,uchar Xpos,unsigned int dat)
{
	unsigned char s[32];
	sprintf(s,"%d",dat);
 	Mid_oled_Display_Show(Xpos,Ypos,ShowString,s,NULL);
}

