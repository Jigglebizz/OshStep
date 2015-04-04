/*
 * ShiftRegister.cpp
 *
 * Created: 2/16/2015 1:23:22 PM
 *  Author: hawthm
 */

#include "ShiftRegisters.h"

#include "../../system.h"

#include <unistd.h>
#include <stdlib.h>

int ShiftRegisters::open( void* params) {

    // Open our shift register driver
    // Enable IO, set to output
    pinSetMode(seqSdPort,   seqSdPin,   OUTPUT);
    pinSetMode(seqClkPort,  seqClkPin,  OUTPUT);
    pinSetMode(seqOePort,   seqOePin,   OUTPUT);
    pinSetMode(funcSdPort,  funcSdPin,  OUTPUT);
    pinSetMode(funcClkPort, funcClkPin, OUTPUT);
    pinSetMode(funcOePort,  funcOePin,  OUTPUT);

    // Disable pull-ups
    pinDisablePullup(seqSdPort,   seqSdPin);
    pinDisablePullup(seqClkPort,  seqClkPin);
    pinDisablePullup(seqOePort,   seqOePort);
    pinDisablePullup(funcSdPort,  funcSdPin);
    pinDisablePullup(funcClkPort, funcClkPin);
    pinDisablePullup(funcOePort,  funcOePin);

    // Set data and clock low, latch high
    pinSetOutput(seqSdPort,   seqSdPin,   LOW);
    pinSetOutput(seqClkPort,  seqClkPin,  LOW);
    pinSetOutput(seqOePort,   seqOePin,   HIGH);
    pinSetOutput(funcSdPort,  funcSdPin,  LOW);
    pinSetOutput(funcClkPort, funcClkPin, LOW);
    pinSetOutput(funcOePort,  funcOePin,  HIGH);

    return 0;
}

int ShiftRegisters::close() {
    return 0;
}

int ShiftRegisters::write( void* data) {
    ShiftRegistersWriteParams *params = (ShiftRegistersWriteParams *)data;
    
    // Sequencer lights
    // Set latch low
    pinSetOutput(seqOePort, seqOePin, LOW);
    // Bang em out
    pinSetOutput(seqClkPort, seqClkPin, HIGH);
    for (int i = 0; i < 32 ; i++) {
        pinSetOutput(seqClkPort, seqClkPin, LOW);
        int level = (~(params->stepLights >> i) & 1);
        pinSetOutput(seqSdPort, seqSdPin, level);
        pinSetOutput(seqClkPort, seqClkPin, HIGH);
    }
    pinSetOutput(seqClkPort, seqClkPin, LOW);
    // Latch high
    pinSetOutput(seqOePort, seqOePin, HIGH);

    // Function lights
    // Set latch low
    pinSetOutput(funcOePort, funcOePin, LOW);
    // Bang em out
    pinSetOutput(funcClkPort, funcClkPin, HIGH);
    for (int i = 0; i < 16; i++) {
        pinSetOutput(funcClkPort, funcClkPin, LOW);
        int level = ~(params->functionLights >> i) & 1;
        pinSetOutput(funcSdPort, funcSdPin, level);
        pinSetOutput(funcClkPort, funcClkPin, HIGH);
    }
    pinSetOutput(funcClkPort, funcClkPin, LOW);
    // Latch high
    pinSetOutput(funcOePort, funcOePin, HIGH);

    return 0;
}

void* ShiftRegisters::read() {
    return (void*)0;
}

void* ShiftRegisters::ioctl(int ioctl_t, void* data) {
    return (void*)0;
}