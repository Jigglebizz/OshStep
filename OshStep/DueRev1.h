/*
 * DueRev1.h
 *
 * Created: 2/27/2015 8:28:41 PM
 *  Author: hawthm
 */ 


#ifndef DUEREV1_H_
#define DUEREV1_H_

#include <stdint.h>

enum Port { A, B, C, D };
enum Mode { INPUT, OUTPUT, PERIPHERAL_A, PERIPHERAL_B};

#define HIGH    1
#define LOW     0
#define ON      1
#define OFF     0

// Interrupt structures
#define __ISR_ENABLED_A 0x08
#define __ISR_ENABLED_B 0x04
#define __ISR_ENABLED_C 0x02
#define __ISR_ENABLED_D 0x01

typedef void(*__Isr)(Port, int);         // Declare format for ISR
typedef __Isr __IsrBank[32];    // Declare format for ISR Bank

extern uint8_t __isr_enabled_mask; // XXXXABCD

extern volatile __IsrBank __isr_a;
extern volatile __IsrBank __isr_b;
extern volatile __IsrBank __isr_c;
extern volatile __IsrBank __isr_d;

// Functions
void setupTimer0(long , void(*)(void));
void pinSetMode(Port, int, Mode);
void pinEnablePullup(Port, int);
void pinDisablePullup(Port, int);
void pinSetOutput(Port, int, int);
int  pinGetOutputStatus(Port, int);
int  pinReadInput(Port, int);
void attachInterrupt(Port, int, void(*)(Port, int));
void pioIsr(Port);

#endif /* DUEREV1_H_ */