/*
 * LCD.h
 *
 * Created: 8/18/2023 6:35:51 PM
 *  Author: Bola George
 */ 


#ifndef LCD_H_

#define LCD_H_
#include "DIO.h"
#include "LCD_config.h"

#define CLR_SCREEN 0X01
#define CURSOR_ON_DISPLAY_ON 0X0c
#define RETURN_HOME 0X02
#define ENTERY_MODE 0X06
#define DATA_PORT 'A'
#define CONTROL_PORT 'B'

#if defined four_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define FOUR_BITS 0X28

#elif defined eight_bits_mode
#define EN 0
#define RS 1
#define RW 2
#define EIGHT_BITS 0x38
#endif


void LCD_init(void);
static void enable(void);
void LCD_send_cmd(unsigned char cmd);
void LCD_send_char (unsigned char data);
void LCD_send_string (unsigned char * data);
void LCD_clear_screen(void);
void LCD_move_cursor(unsigned char row,unsigned char col);




#endif /* LCD_H_ */