/*
 * SSD1305WriteParams.cpp
 *
 * Created: 3/6/2015 11:15:46 AM
 *  Author: hawthm
 */ 

#include "SSD1305Params.h"

#include "../SSD1305.h"

#include <stdlib.h>

SSD1305Params::SSD1305Params() {
}

SSD1305Params::~SSD1305Params() {

}

void SSD1305Params::setPixel(int x, int y, int val) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        #ifdef SSD1305_ORIENTATION
            int max_x = width - 1;
            int max_y = height - 1;
            if (val == PIXEL_ON)
                buffer[max_x - x + (width * ((max_y - y) / pix_in_page))] |= 
                    0x1 << ((pix_in_page - 1) - ( y % pix_in_page));
            else
                buffer[max_x - x + (width * ((max_y - y) / pix_in_page))] &=
                   ~(0x1 << ((pix_in_page - 1) - (y % pix_in_page))); 
        #else
            if (val == PIXEL_ON)
                buffer[x + (width * (y / pix_in_page))] |=
                    0x1 << (y % pix_in_page);
            else
                buffer[x + (width * (y / pix_in_page))] &=
                    ~(0x1 << (y % pix_in_page));
        #endif
    }
}

void SSD1305Params::clear(int val) {
    for (int i = 0; i < visible_buffers; i++) {
        if (val == PIXEL_ON)
            buffer[i] = 0xFF; // <<<< Problem is here
        else
            buffer[i] = 0x00;
    }
}