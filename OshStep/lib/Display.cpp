/*
 * Display.cpp
 *
 * Created: 4/1/2015 6:56:27 PM
 *  Author: hawthm
 */ 

#include "Display.h"
#include "driver/SSD1305.h"
#include "../assets/images.h"

#include <math.h>

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
    uint8_t x_origin = x;
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
        
        // If this is a newline
        if (str[i] == 10) { 
            x = x_origin;
            y += glyph_h + 1;
        } else {
            bmp.setRectangle(   (glyphPos * glyph_w) % glyph_map_w,
            (((glyphPos * glyph_w) / glyph_map_w) * glyph_h),
            glyph_w, glyph_h);
            bmp.moveTo(x, y);
            bmp.draw(ssdp);
            x += glyph_w;
        }
    }
}

/*
 *  Draws line using Bresenham's line drawing algorithm.
 */
void Display::drawLine(int x1, int y1, int x2, int y2) {
    int dy = y2 - y1;
    int dx  = x2 - x1;
    
    if (dx == 0) {
        if (y2 < y1) {
            int tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for (int y  = y1; y < y2 + 1; y++) {
            ssdp.setPixel(x1, y, 1);
        }
    } else {
        float m = (float)dy / dx;
        float adjust = (m >= 0) ? 1 : -1;
        float offset = 0;
        float threshold = 0.5;
        
        if (m <= 1 and m >= -1) {
            float delta = fabs(m);
            int y = y1;
            if (x2 < x1) {
                int tmp = x1;
                x1 = x2;
                x2 = tmp;
                y = y2;
            }
            for (int x = x1; x < x2 + 1; x++) {
                ssdp.setPixel(x, y, 1);
                offset += delta;
                if (offset >= threshold) {
                    y += adjust;
                    threshold += 1;
                }
            }
        }
        else {
            float delta = fabs(m);
            int x = x1;
            if (y2 < y1) {
                int tmp = y1;
                y1 = y2;
                y2 = tmp;
                x = x2;
            }
            for (int y = y1; y < y2 + 1; y++) {
                ssdp.setPixel(x, y, 1);
                offset += delta;
                if (offset >= threshold) {
                    x += adjust;
                    threshold += 1;
                }
            }
        }
    }
}

void Display::drawRectangle(int x0, int y0, int x1, int y1) {
    this->drawLine(x0, y0, x0, y1);
    this->drawLine(x0, y1, x1, y1);
    this->drawLine(x1, y1, x1, y0);
    this->drawLine(x1, y0, x0, y0);
}

void Display::drawFilledRectangle(int x0, int y0, int x1, int y1) {
    for (int y = y0; y < y1; y++) {
        for (int x = x0; x < x1; x++) {
            ssdp.setPixel(x, y, PIXEL_ON);
        }
    }
}

void Display::drawPixel(int x, int y) {
    ssdp.setPixel(x, y, PIXEL_ON);
}

void Display::clear() {
    ssdp.clear(PIXEL_OFF);
}

void Display::paint() {
    SSD1305::Instance().write(&ssdp);
}