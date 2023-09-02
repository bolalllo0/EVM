/*
 * button.h
 *
 * Created: 7/26/2023 2:05:45 PM
 *  Author: Bola George
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

//=====================================================================================================================================|
/*
Function Name        : button_vInit
Function Returns     : void
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : define the given pin in the given port as input pin
*/
void Button_SetPinDir(unsigned char portname, unsigned char pinnumber);

//=====================================================================================================================================|

/*
Function Name        : Button_Read
Function Returns     : char
Function Arguments   : unsigned char portname,unsigned char pinnumber
Function Description : Return 0 or 1 depend on the status of the button (pressed or not) and the type of connection (pull up or pull down)
*/
char Button_Read(unsigned char portname ,unsigned char pinnumber);

//=====================================================================================================================================|
#endif /* BUTTON_H_ */