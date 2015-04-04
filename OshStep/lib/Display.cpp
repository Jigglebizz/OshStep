/*
 * Display.cpp
 *
 * Created: 4/1/2015 6:56:27 PM
 *  Author: hawthm
 */ 

#include "Display.h"
#include "driver/SSD1305.h"
#include "../assets/images.h"

Display::Display() {
    ssdp = SSD1305Params();
    ssdp.clear(PIXEL_OFF);
    SSD1305::Instance().open(NULL);
}

Display::~Display() {
    delete &ssdp;
}

void Display::drawBitmap( Bitmap &bmp) {
    bmp.draw(ssdp);
}

void Display::drawText( uint8_t x, uint8_t y, Font f, const char* str) {
    int glyph_w, glyph_h;
    const unsigned char* bitmap_raw;
    
    if (f == LARGE_FONT) {
        bitmap_raw = font_large;
        glyph_w = 8;
        glyph_h = 32;
    } else {    // default is SMALL_FONT
        bitmap_raw = font_small;
        glyph_w = 7;
        glyph_h = 7;
    }

    Bitmap bmp(bitmap_raw);

    int glyph_map_w = (bmp.width / glyph_w) * glyph_w;
    
    for (int i = 0; str[i] != 0; i++) {
        int glyphPos;
        if (str[i] == 32)                       glyphPos = 0;           // Space
        else if (str[i] == 45)                  glyphPos = 1;           // -
        else if (str[i] >= 48 && str[i] <= 57)  glyphPos = str[i] - 46; // 0-9
        else if (str[i] == 63)                  glyphPos = 12;          // ?
        else if (str[i] == 46)                  glyphPos = 13;          // .
        else if (str[i] >= 65 && str[i] <= 90)  glyphPos = str[i] - 51; // A-Z
        else if (str[i] >= 97 && str[i] <= 122) glyphPos = str[i] - 83; // a-z
        else                                    glyphPos = 12;          // ?
        
        bmp.setRectangle(   (glyphPos * glyph_w) % glyph_map_w, 
                            (((glyphPos * glyph_w) / glyph_map_w) * glyph_h), 
                             glyph_w, glyph_h);
        bmp.moveTo(x, y);
        bmp.draw(ssdp);
        x += glyph_w;
    }
}

void Display::paint() {
    SSD1305::Instance().write(&ssdp);
}