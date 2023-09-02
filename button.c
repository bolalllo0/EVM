/*
 * button.c
 *
 * Created: 7/26/2023 2:05:30 PM
 *  Author: Bola George
 */ 

#include "DIO.h"

void Button_SetPinDir(unsigned char portname, unsigned char pinnumber)
{
	DIO_vSetPinDir(portname,pinnumber,0);
}

 char Button_Read (unsigned char portname ,unsigned char pinnumber)
 {
	 return DIO_read(portname,pinnumber);
 }  