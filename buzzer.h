/*
 * buzzer.h
 *
 * Created: 8/19/2023 5:03:58 PM
 *  Author: Bola George
 */ 


#ifndef BUZZER_H_
#define BUZZER_H_

void Buzzer_init (unsigned char portname,unsigned char pinnumber);
void Buzzer_ON(unsigned char portname,unsigned char pinnumber );
void Buzzer_OFF(unsigned char portname,unsigned char pinnumber);



#endif /* BUZZER_H_ */