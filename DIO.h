/*
 * DIO.h
 *
 * Created: 7/19/2023 6:52:10 PM
 *  Author: Bola George
 */ 


#ifndef DIO_H_
#define DIO_H_

//=====================================================================================================================================|

/*  Function Name         :DIO_vSetPinDir
    Function Return       :void
	Function Argument     :unsigned char portname, unsigned char pinnumber , unsigned char direction
	Function Description  :set the direction of the given pin in the given port (diection = 0 =input or direction = 1 = output
*/  
void DIO_vSetPinDir(unsigned char portname, unsigned char pinnumber , unsigned char direction);

//======================================================================================================================================|

/*
     Function Name         :DIO_WRITE
     Function Return       :void
     Function Argument     :unsigned char portname , unsigned char pinnumber , unsigned char outputvalue
     Function Description  :set the value of the given bit in the given port (High = 1,low = 0)
*/
void DIO_write (unsigned char portname , unsigned char pinnumber , unsigned char outputvalue);

//======================================================================================================================================|

/*
     Function Name         :DIO_toogle
     Function Return       :void
     Function Argument     :unsigned char portname , unsigned char pinnumber
     Function Description  :reverse the value of the given bin in the given port
*/
void DIO_toogle (unsigned char portname , unsigned char pinnumber);

//======================================================================================================================================|

/*
     Function Name         :DIO_read
     Function Return       :char
     Function Argument     :unsigned char portname , unsigned char pinnumber
     Function Description  :Returns 1 if the value of the given pin is high and zero if the value is low
*/
char DIO_read (unsigned char portname , unsigned char pinnumber);

//======================================================================================================================================|

/*
     Function Name         :DIO_SetPortDir
     Function Return       :void
     Function Argument     :char portname , char direction
     Function Description  :set the direction of whole port
*/
void DIO_Set_Port_Direction(char portname , char direction);

//======================================================================================================================================|

/*
     Function Name         :DIO_write_Port
     Function Return       :void
     Function Argument     :unsigned char portname , unsigned char portvalue
     Function Description  :writhe the value to all port pins
*/
void DIO_write_Port (unsigned char portname , unsigned char portvalue);

//======================================================================================================================================|

/*
     Function Name         :DIO_read_port
     Function Return       :char
     Function Argument     :unsigned char portname
     Function Description  :read the value to all port pins
*/
char DIO_read_port (unsigned char portname);

//======================================================================================================================================|

/*
     Function Name         :DIO_toggle_port
     Function Return       :void
     Function Argument     :unsigned char portname
     Function Description  :toggle the bits of the whole port pins
*/
void DIO_toggle_port (unsigned char portname);

//======================================================================================================================================|

/*
     Function Name         :DIO_connect_pull_up
     Function Return       :void
     Function Argument     :unsigned char portname,unsigned char pinnumber ,unsigned char connect
     Function Description  :connect and disconnect the pull up resistor to given pin at the given port
*/
void DIO_connect_pull_up(unsigned char portname,unsigned char pinnumber ,unsigned char connect);

//======================================================================================================================================|

/*
     Function Name         :DIO_connect_pull_up
     Function Return       :void
     Function Argument     :unsigned char portname,unsigned char pinnumber ,unsigned char connect
     Function Description  :connect and disconnect the pull up resistor to given pin at the given port
*/
void DIO_write_low_nibble(unsigned char portname,unsigned char value);

//======================================================================================================================================|

/*
     Function Name         :DIO_connect_pull_up
     Function Return       :void
     Function Argument     :unsigned char portname,unsigned char pinnumber ,unsigned char connect
     Function Description  :connect and disconnect the pull up resistor to given pin at the given port
*/
void DIO_write_high_nibble(unsigned char portname,unsigned char value);

//======================================================================================================================================|

#endif /* DIO_H_ */