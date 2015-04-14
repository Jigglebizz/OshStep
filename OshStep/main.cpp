/*
 * main.cpp
 *
 * Created: 2/15/2015 3:01:16 PM
 *  Author: hawthm
 */ 

#include "system.h"
#include "sam.h"

#include <stdlib.h>

#include "lib/Reporting.h"
#include "lib/driver/Encoders.h"
#include "lib/Display.h"

/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    //Reporting::Instance().reportCode(PRIORITY_DEBUG, LIGHTS, 0xDEADBEEF);

    Display disp = Display();
    volatile int x = 0;
    Encoders::Instance().open(NULL);
    while (1) 
    {
        EncodersStatus *eStat = (EncodersStatus*)Encoders::Instance().read();
        x += eStat->relative_position[0];

        disp.drawText(x, 0, SMALL_FONT, "hello\nworld!");
        disp.paint();
        disp.clear();
    }
}
