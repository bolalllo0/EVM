/*
 * LCD.c
 *
 * Created: 8/18/2023 6:35:40 PM
 *  Author: Bola George
 */ 


#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>

void LCD_init(void)
{
	_delay_ms(200);
	#if defined eight_bits_mode
	DIO_vSetPinDir(DATA_PORT,0,1);
	DIO_vSetPinDir(DATA_PORT,1,1);
	DIO_vSetPinDir(DATA_PORT,2,1);
	DIO_vSetPinDir(DATA_PORT,3,1);
	DIO_vSetPinDir(DATA_PORT,4,1);
	DIO_vSetPinDir(DATA_PORT,5,1);
	DIO_vSetPinDir(DATA_PORT,6,1);
	DIO_vSetPinDir(DATA_PORT,7,1);
	DIO_vSetPinDir(CONTROL_PORT,EN,1);
	DIO_vSetPinDir(CONTROL_PORT,RW,1);
	DIO_vSetPinDir(CONTROL_PORT,RS,1);
	DIO_write(CONTROL_PORT,RW,0);
	LCD_send_cmd(EIGHT_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTERY_MODE);
	_delay_ms(1);
	
	#elif defined four_bits_mode
	DIO_vSetPinDir(DATA_PORT,4,1);
	DIO_vSetPinDir(DATA_PORT,5,1);
	DIO_vSetPinDir(DATA_PORT,6,1);
	DIO_vSetPinDir(DATA_PORT,7,1);
	DIO_vSetPinDir(CONTROL_PORT,EN,1);
	DIO_vSetPinDir(CONTROL_PORT,RW,1);
	DIO_vSetPinDir(CONTROL_PORT,RS,1);
	DIO_write(CONTROL_PORT,RW,0);
	LCD_send_cmd(RETURN_HOME);
	_delay_ms(10);
	LCD_send_cmd(FOUR_BITS);
	_delay_ms(1);
	LCD_send_cmd(CURSOR_ON_DISPLAY_ON);
	_delay_ms(1);
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
	LCD_send_cmd(ENTERY_MODE);
	_delay_ms(1);
	#endif
}

static void enable(void)
{
	DIO_write(CONTROL_PORT,EN,1);
	_delay_ms(2);
	DIO_write(CONTROL_PORT,EN,0);
	_delay_ms(2);
}

void LCD_send_cmd(unsigned char cmd)
{
	#if defined eight_bits_mode
	DIO_write_Port(DATA_PORT,cmd);
	DIO_write(CONTROL_PORT,RS,0);
	enable();
	
	#elif defined four_bits_mode
	DIO_write_high_nibble(DATA_PORT,(cmd>>4));
	DIO_write(CONTROL_PORT,RS,0);
	enable();
	DIO_write_high_nibble(DATA_PORT,cmd);
	DIO_write(CONTROL_PORT,RS,0);
	enable();
	#endif
	_delay_ms(1);
	
}

void LCD_send_char (unsigned char data)
{
	#if defined eight_bits_mode
	DIO_write_Port(DATA_PORT,data);
	DIO_write(CONTROL_PORT,RS,1);
	enable();
	
	#elif defined four_bits_mode
	DIO_write_high_nibble(DATA_PORT,data>>4);
	DIO_write(CONTROL_PORT,RS,1);
	enable();
	DIO_write_high_nibble(DATA_PORT,data);
	DIO_write(CONTROL_PORT,RS,1);
	enable();
	#endif
	_delay_ms(1);
}

void LCD_send_string (unsigned char * data)
{
	while((*data)!='\0')
	{
		LCD_send_char(*data);
		data++;
	}
}

void LCD_clear_screen(void)
{
	LCD_send_cmd(CLR_SCREEN);
	_delay_ms(10);
}

void LCD_move_cursor(unsigned char row,unsigned char col)
{
	char data;
	if((row>2)||(row<1)||(col>16)||(col<1))
	{
		data = 0X80;
	}
	else if(row == 1)
	{
		data = 0X80+(col-1);
	}
	else if(row==2)
	{
		data = 0XC0+(col-1); 
	}
	LCD_send_cmd(data);
	_delay_ms(1);
}
