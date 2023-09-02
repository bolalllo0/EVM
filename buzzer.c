/*
 * buzzer.c
 *
 * Created: 8/19/2023 5:03:48 PM
 *  Author: Bola George
 */ 

#include "DIO.h"

void Buzzer_init (unsigned char portname,unsigned char pinnumber)
{
	DIO_vSetPinDir(portname,pinnumber,1);
}

void Buzzer_ON(unsigned char portname,unsigned char pinnumber )
{
	DIO_write(portname,pinnumber,1);
}

void Buzzer_OFF(unsigned char portname,unsigned char pinnumber)
{
	DIO_write(portname,pinnumber,0);
}