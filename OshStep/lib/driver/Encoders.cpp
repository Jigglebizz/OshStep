/*
 * Encoders.cpp
 *
 * Created: 3/13/2015 4:31:06 PM
 *  Author: hawthm
 */ 

#include "Encoders.h"
#include "../Reporting.h"

#include <stdlib.h>
#include <stdio.h>

Port const Encoders::aPorts[] = {B,  A,  D, D};
int  const Encoders::aPins[]  = {26, 15, 1, 3};
Port const Encoders::bPorts[] = {A,  D,  D, D};
int  const Encoders::bPins[]  = {14, 0,  2, 6};

int Encoders::open(void* p) {
    /* Set up our IO */
    for (int i = 0; i < 4; i++) {
        // Enable, set to input
        pinSetMode(aPorts[i], aPins[i], INPUT);
        pinSetMode(bPorts[i], bPins[i], INPUT);

        // Enable pull-ups
        pinEnablePullup(aPorts[i], aPins[i]);
        pinEnablePullup(bPorts[i], bPins[i]);

        attachInterrupt(aPorts[i], aPins[i], &__encoders_isr);
    }

    /* Read values, assign states */
    for (int i = 0; i < 4; i++) {
        // States are in the form of 0b000000ab
        states[i] = (pinReadInput(aPorts[i], aPins[i]) << 1) | pinReadInput(bPorts[i], bPins[i]);

        // And set encoder status
        status.relative_position[i] = 0;
    }

    return 0;
}

int Encoders::close() {
    return 0;
}

int Encoders::write(void* p) {
    return 0;
}

void *Encoders::read() {
    for (int i = 0; i < 4; i++) {
        readStatus.relative_position[i] = status.relative_position[i];
        status.relative_position[i] = 0;
    }
    
    return (void*)&readStatus;
}

 void *Encoders::ioctl(int ioctl_t, void *params) {
    return (void*)0;
 }

 void Encoders::interrupt_callback(Port p, int pin) {
    for (int i = 0; i < 4; i++) {
        if (p == aPorts[i] && pin == aPins[i]) {
            if (pinReadInput(p, pin) == pinReadInput(bPorts[i], bPins[i])) {
                status.relative_position[i] ++;
            } else {
                status.relative_position[i] --;
            }
            break;
        }
    }
 }

 void __encoders_isr(Port p, int pin) {
    Encoders::Instance().interrupt_callback(p, pin);
 }