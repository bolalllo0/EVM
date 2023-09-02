/*
 * DIO.c
 *
 * Created: 7/19/2023 6:51:57 PM
 *  Author: Bola George
 */ 

#include <avr/io.h>
#include "std_macros.h"


void DIO_vSetPinDir(unsigned char portname, unsigned char pinnumber , unsigned char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if (direction==1)
		{
			SET_BIT(DDRA,pinnumber);
		}
		else
		{
			CLR_BIT(DDRA,pinnumber);
		}
		break;
		
		case 'B':
		case 'b':
		if (direction==1)
		{
			SET_BIT(DDRB,pinnumber);
		}
		else
		{
			CLR_BIT(DDRB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if (direction==1)
		{
			SET_BIT(DDRC,pinnumber);
		}
		else
		{
			CLR_BIT(DDRC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(direction==1)
		{
			SET_BIT(DDRD,pinnumber);
		}
		else
		{
			CLR_BIT(DDRD,pinnumber);
		}
		break;
		default:
		break;
	}
}

void DIO_write (unsigned char portname , unsigned char pinnumber , unsigned char outputvalue)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		if (outputvalue==1)
		{
			SET_BIT(PORTA,pinnumber);
		}
		else
		{
			CLR_BIT(PORTA,pinnumber);
		}
		break;
		case 'B':
		case 'b':
		if (outputvalue==1)
		{
			SET_BIT(PORTB,pinnumber);
		}
		else
		{
			CLR_BIT(PORTB,pinnumber);
		}
		break;
		case 'C':
		case 'c':
		if (outputvalue==1)
		{
			SET_BIT(PORTC,pinnumber);
		}
		else
		{
			CLR_BIT(PORTC,pinnumber);
		}
		break;
		case 'D':
		case 'd':
		if(outputvalue==1)
		{
			SET_BIT(PORTD,pinnumber);
		}
		else
		{
			CLR_BIT(PORTD,pinnumber);
		}
		break;
		default:
		break;
	}
}


void DIO_toogle (unsigned char portname , unsigned char pinnumber)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		TOG_BIT(PORTA,pinnumber);
		break;
		case 'B':
		case 'b':
		TOG_BIT(PORTB,pinnumber);
		break;
		case 'C':
		case 'c':
		TOG_BIT(PORTC,pinnumber);
		break;
		case 'D':
		case 'd':
		TOG_BIT(PORTD,pinnumber);
		break;
		default:
		break;
	}
}

char DIO_read (unsigned char portname , unsigned char pinnumber)
{
	char ret_val;
	switch(portname)
	{
		case 'A':
		case 'a':
		ret_val = READ_BIT(PINA,pinnumber);
		break;
		case 'B':
		case 'b':
		ret_val = READ_BIT(PINB,pinnumber);
		break;
		case 'C':
		case 'c':
		ret_val = READ_BIT(PINC,pinnumber);
		break;
		case 'D':
		case 'd':
		ret_val = READ_BIT(PIND,pinnumber);
		break;
		default:
		break;
	}
	return ret_val;
}


void DIO_Set_Port_Direction(char portname , char direction)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		DDRA = direction;
		break;
		case 'B':
		case 'b':
		DDRB = direction;
		break;
		case 'C':
		case 'c':
		DDRC = direction;
		break;
		case 'D':
		case 'd':
		DDRD = direction;
		break;
		default:
		break;
	}
}

void DIO_write_Port (unsigned char portname , unsigned char portvalue)
{
	switch(portname)
	{
		case 'A':
		case 'a':
		PORTA = portvalue;
		break;
		case 'B':
		case 'b':
		PORTB = portvalue;
		break;
		case 'C':
		case 'c':
		PORTC = portvalue;
		break;
		case 'D':
		case 'd':
		PORTD = portvalue;
		break;
		default:
		break;
	}
}


char DIO_read_port (unsigned char portname)
{
	unsigned char return_val;
	switch(portname)
	{
		case 'A':
		case 'a':
		return_val = PINA;
		break;
		case 'B':
		case 'b':
		return_val = PINB;
		break;
		case 'C':
		case 'c':
		return_val = PINC;
		break;
		case 'D':
		case 'd':
		return_val = PIND;
		break;
		default:
		break;
	}
	return return_val;
}

void DIO_toggle_port (unsigned char portname)
{
	switch (portname)
	{
		case 'A':
		case 'a':
		PORTA = ~PORTA;
		break;
		case 'B':
		case 'b':
		PORTB = ~PORTB;
		break;
		case 'C':
		case 'c':
		PORTC = ~PORTC;
		break;
		case 'D':
		case 'd':
		PORTD = ~PORTD;
		break;
		default:
		break;
	}
}

void DIO_connect_pull_up(unsigned char portname,unsigned char pinnumber ,unsigned char connect)
{
	DIO_vSetPinDir(portname,pinnumber,0);
	DIO_write(portname,pinnumber,connect);
	
}

void DIO_write_low_nibble(unsigned char portname,unsigned char value)
{
	value&=0x0f;
	switch(portname)
	{
		case 'A':
		PORTA&=0xf0;
		PORTA|=value;
		break;
		case 'B':
		PORTB&=0xf0;
		PORTB|=value;
		break;
		case 'C':
		PORTC&=0xf0;
		PORTC|=value;
		break;
		case 'D':
		PORTD&=0xf0;
		PORTD|=value;
		break;
	}
}

void DIO_write_high_nibble(unsigned char portname,unsigned char value)
{
	value<<=4;
	switch(portname)
	{
		case 'A':
		PORTA&=0x0f;
		PORTA|=value;
		case 'B':
		PORTB&=0x0f;
		PORTB|=value;
		case 'C':
		PORTC&=0x0f;
		PORTC|=value;
		case 'D':
		PORTD&=0x0f;
		PORTD|=value;
	}
}