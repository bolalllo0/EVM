/*
 * EVM.c
 *
 * Created: 8/19/2023 4:09:21 PM
 *  Author: Bola George
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 8000000UL
#include "LCD.h"
#include "button.h"
#include "buzzer.h"

unsigned short counter1=0;
unsigned short counter2=0;
unsigned short counter3=0;
unsigned short counter4=0;

int main(void)
{
	LCD_init();
	Button_SetPinDir('D',3);
	Button_SetPinDir('D',4);
	Button_SetPinDir('D',5);
	Button_SetPinDir('D',6);
	Button_SetPinDir('D',7);
	Buzzer_init('D',0);
	
	LCD_send_string("A=0");
	LCD_move_cursor(1,10);
	LCD_send_string("B=0");
	LCD_move_cursor(2,1);
	LCD_send_string("C=0");
	LCD_move_cursor(2,10);
	LCD_send_string("D=0");
    while(1)
    {
        if(Button_Read('D',3)==1)
		{
			counter1++;
			LCD_move_cursor(1,3);
			Buzzer_ON('D',0);
			if(counter1<10)
			{
				LCD_send_char(counter1+48);
			}
			else if(counter1<100)
			{
				LCD_send_char((counter1/10)+48);
				LCD_send_char((counter1%10)+48);
			}
			else if(counter1<1000)
			{
				LCD_send_char((counter1/100)+48);
				LCD_send_char(((counter1/10)%10)+48);
				LCD_send_char(((counter1%100)%10)+48);
			}
			else if(counter1<10000)
			{
				LCD_send_char((counter1/1000)+48);
				LCD_send_char(((counter1/100)%10)+48);
				LCD_send_char((((counter1%1000)/10)%10)+48);
				LCD_send_char((((counter1%1000)%100)%10)+48);
			}
		}			
			if(Button_Read('D',4)==1)
			{
				counter2++;
				LCD_move_cursor(1,12);
				Buzzer_ON('D',0);
				if(counter2<10)
				{
					LCD_send_char(counter2+48);
				}
				else if(counter2<100)
				{
					LCD_send_char((counter2/10)+48);
					LCD_send_char((counter2%10)+48);
				}
				else if(counter2<1000)
				{
					LCD_send_char((counter2/100)+48);
					LCD_send_char(((counter2/10)%10)+48);
					LCD_send_char(((counter2%100)%10)+48);
				}
				else if(counter2<10000)
				{
					LCD_send_char((counter2/1000)+48);
					LCD_send_char(((counter2/100)%10)+48);
					LCD_send_char((((counter2%1000)/10)%10)+48);
					LCD_send_char((((counter2%1000)%100)%10)+48);
				}
			}
			if(Button_Read('D',5)==1)
			{
				counter3++;
				LCD_move_cursor(2,3);
				Buzzer_ON('D',0);
				if(counter3<10)
				{
					LCD_send_char(counter3+48);
				}
				else if(counter3<100)
				{
					LCD_send_char((counter3/10)+48);
					LCD_send_char((counter3%10)+48);
				}
				else if(counter3<1000)
				{
					LCD_send_char((counter3/100)+48);
					LCD_send_char(((counter3/10)%10)+48);
					LCD_send_char(((counter3%100)%10)+48);
				}
				else if(counter3<10000)
				{
					LCD_send_char((counter3/1000)+48);
					LCD_send_char(((counter3/100)%10)+48);
					LCD_send_char((((counter3%1000)/10)%10)+48);
					LCD_send_char((((counter3%1000)%100)%10)+48);
				}
			}				
			if(Button_Read('D',6)==1)
			{
				counter4++;
				LCD_move_cursor(2,12);
				Buzzer_ON('D',0);
				if(counter4<10)
				{
					LCD_send_char(counter4+48);
				}
				else if(counter4<100)
				{
					LCD_send_char((counter4/10)+48);
					LCD_send_char((counter4%10)+48);
				}
				else if(counter4<1000)
				{
					LCD_send_char((counter4/100)+48);
					LCD_send_char(((counter4/10)%10)+48);
					LCD_send_char(((counter4%100)%10)+48);
				}
				else if(counter4<10000)
				{
					LCD_send_char((counter4/1000)+48);
					LCD_send_char(((counter4/100)%10)+48);
					LCD_send_char((((counter4%1000)/10)%10)+48);
					LCD_send_char((((counter4%1000)%100)%10)+48);
				}
			}
			if (Button_Read('D',7)==1)
			{
				counter1=counter2=counter3=counter4=0;
				Buzzer_ON('D',0);
				LCD_move_cursor(1,3);
				LCD_send_char(0x30);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_move_cursor(1,12);
				LCD_send_char(0x30);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_move_cursor(2,3);
				LCD_send_char(0x30);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_move_cursor(2,12);
				LCD_send_char(0x30);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
				LCD_send_char(0x80);
			}
		
		_delay_ms(1000);
		Buzzer_OFF('D',0);							
    }
}