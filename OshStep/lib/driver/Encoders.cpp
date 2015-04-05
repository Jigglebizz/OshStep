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
    }

    /* Construct the state wheel */
    EncoderState *a = (EncoderState*)malloc(sizeof(EncoderState));
    EncoderState *b = (EncoderState*)malloc(sizeof(EncoderState));
    EncoderState *c = (EncoderState*)malloc(sizeof(EncoderState));
    EncoderState *d = (EncoderState*)malloc(sizeof(EncoderState));

    a->mask = 0x0;
    b->mask = 0x1;
    c->mask = 0x3;
    d->mask = 0x2;

    a->next = b;
    a->prev = d;
    b->next = c;
    b->prev = a;
    c->next = d;
    c->prev = b;
    d->next = a;
    d->prev = c;

    /* Read values, assign states */
    for (int i = 0; i < 4; i++) {
        // States are in the form of 0b000000ab
        uint8_t state = (pinReadInput(aPorts[i], aPins[i]) << 1) | pinReadInput(bPorts[i], bPins[i]);
        
        // Cycle through the state wheel
        EncoderState *e = a;
        states[i] = NULL;
        do {
            if (state == e->mask) {
                states[i] = e;
                break;
            }
            e = e->next;
        } while (e != a);

        // Error checking
        if (states[i] == NULL) {
            char panic_text[25];
            sprintf(panic_text, "Invalid state encoder %d", i);
            Reporting::Instance().reportText(PRIORITY_PANIC, panic_text);
        }

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
    return (void*)0;
}

 void *Encoders::ioctl(int ioctl_t, void *params) {
    return (void*)0;
 }