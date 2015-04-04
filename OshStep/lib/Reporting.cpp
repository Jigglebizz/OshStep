/*
 * Reporting.cpp
 *
 * Created: 3/10/2015 9:28:02 PM
 *  Author: hawthm
 */ 

#include "Reporting.h"
#include "driver/ShiftRegisters.h"
#include "Display.h"

#include <stdlib.h>
#include <stdio.h>

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
    else {
        if (p == d)  {
            #ifdef DEBUG
                Display disp = Display();
                char hexString[10];
                sprintf(hexString, "0x%X", (unsigned int)code);
                disp.drawText(0, 0, SMALL_FONT, hexString);
                disp.paint();
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