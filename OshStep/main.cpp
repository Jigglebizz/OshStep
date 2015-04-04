/*
 * main.cpp
 *
 * Created: 2/15/2015 3:01:16 PM
 *  Author: hawthm
 */ 

#include "system.h"
#include "sam.h"

#include <stdlib.h>

#include "lib/driver/ShiftRegisters.h"
#include "lib/driver/SSD1305.h"
#include "lib/driver/parameter/SSD1305Params.h"
#include "lib/Reporting.h"
#include "lib/driver/Encoders.h"
#include "lib/Display.h"
#include "lib/display/Bitmap.h"
#include "assets/images.h"

/**
 * \brief Application entry point.
 *
 * \return Unused (ANSI-C compatibility).
 */
int main(void)
{
    /* Initialize the SAM system */
    SystemInit();

    Reporting::Instance().reportCode(d, LIGHTS, 0xDEADBEEF);

    //SSD1305Params ssdp = SSD1305Params();
    //Reporting::Instance().reportCode(d, LIGHTS, (uint32_t)ssdp.buffer);
    //ssdp.clear(PIXEL_OFF);

    //Reporting::Instance().reportCode(d, LIGHTS, (uint32_t)&ssdp->buffer);
    //Reporting::Instance().reportCode(d, LIGHTS, 0x00080008);
    //SSD1305::Instance().open((void*)&ssdp);
    //Reporting::Instance().reportCode(d, LIGHTS, 0xFFFF0000);
    //SSD1305::Instance().write((void*)&ssdp);

    Display disp = Display();
    Bitmap b = Bitmap(edit_note);
    disp.drawBitmap(b);
    //disp.drawText(0, 0, LARGE_FONT, "123456789!");
    disp.paint();

    Reporting::Instance().reportCode(d, DISPLAY, 0xAAAA5555);
    


    while (1) 
    {
        //REG_PIOD_SODR |= pin_11_mask;
        //int x;
        //for (int i = 0; i < 5000; i++) {
        //    x+=i;
       // }

        //REG_PIOD_CODR |= pin_11_mask;

        //for (int i = 0; i < 5000; i++) {
        //    x+=i;
        //}
    }
}
