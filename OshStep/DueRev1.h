/*
 * DueRev1.h
 *
 * Created: 2/27/2015 8:28:41 PM
 *  Author: hawthm
 */ 


#ifndef DUEREV1_H_
#define DUEREV1_H_

// MIDI Pins...................................................................
#define pinMidiOut(a)       (PIOA->a=PIO_PA9);

// Display Pins................................................................
#define pinDisplayCS(a)     (PIOC->a=PIO_PC29);
#define pinDisplayRes(a)    (PIOB->a=PIO_PB25);
#define pinDisplayDC(a)     (PIOC->a=PIO_PC28);
#define pinDisplaySD(a)     (PIOA->a=PIO_PA26);
#define pinDisplayCLK(a)    (PIOA->a=PIO_PA27);

enum Port { A, B, C, D };
enum Mode { INPUT, OUTPUT, PERIPHERAL_A, PERIPHERAL_B};

#define HIGH    1
#define LOW     0
#define ON      1
#define OFF     0

void setupTimer0(long , void(*)(void));
void pinSetMode(Port, int, Mode);
void pinEnablePullup(Port, int);
void pinDisablePullup(Port, int);
void pinSetOutput(Port, int, int);
int  pinGetOutputStatus(Port, int);

#endif /* DUEREV1_H_ */