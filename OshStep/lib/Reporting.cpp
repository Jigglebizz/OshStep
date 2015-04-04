/*
 * Reporting.cpp
 *
 * Created: 3/10/2015 9:28:02 PM
 *  Author: hawthm
 */ 

#include "Reporting.h"
#include "driver/ShiftRegisters.h"

#include <stdlib.h>

void Reporting::reportCode(Priority p, VisualStateMethod method, uint32_t code) {
    if (method == LIGHTS) {
        if (p == d) {
          #ifdef DEBUG
            srwp->stepLights = code;
            srwp->functionLights = 0xFFFF;
            ShiftRegisters::Instance().open(NULL);
            ShiftRegisters::Instance().write(srwp);
            ShiftRegisters::Instance().close();
          #endif
        }
    }
}

void Reporting::clearReport() {
    srwp->stepLights = 0;
    srwp->functionLights = 0;
    ShiftRegisters::Instance().open(NULL);
    ShiftRegisters::Instance().write(srwp);
    ShiftRegisters::Instance().close();
}