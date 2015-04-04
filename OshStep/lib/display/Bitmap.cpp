/*
 * Bitmap.cpp
 *
 * Created: 4/3/2015 5:53:30 PM
 *  Author: hawthm
 */ 

#include "Bitmap.h"
#include "../driver/parameter/SSD1305Params.h"

Bitmap::Bitmap(uint8_t r_x, uint8_t r_y, uint8_t r_w, uint8_t r_h, 
               uint8_t x,   uint8_t y, const unsigned char* bmp) {
    init(r_x, r_y, r_w, r_h, x, y, bmp);    
}

Bitmap::Bitmap(uint8_t r_x, uint8_t r_y, uint8_t r_w, uint8_t r_h, const unsigned char* bmp) {
    init(r_x, r_y, r_w, r_h, 0, 0, bmp);
}

Bitmap::Bitmap(uint8_t x, uint8_t y, const unsigned char* bmp) {
    init(0, 0, (uint8_t)bmp[0], (uint8_t)bmp[1], x, y, bmp);
}

Bitmap::Bitmap(const unsigned char* bmp) {
    init(0, 0, (uint8_t)bmp[0], (uint8_t)bmp[1], 0, 0, bmp);
}

void Bitmap::init(uint8_t r_x, uint8_t r_y, uint8_t r_w, uint8_t r_h, 
                  uint8_t x, uint8_t y, const unsigned char* bmp) {
    this->r_x = r_x;
    this->r_y = r_y;
    this->r_w = r_w;
    this->r_h = r_h;

    this->x = x;
    this->y = y;

    width = bmp[0];
    height = bmp[1];

    bitmap = &bmp[2];
}

void Bitmap::moveTo(uint8_t x, uint8_t y) {
    this->x = x;
    this->y = y;
}

void Bitmap::moveRelative(uint8_t x, uint8_t y) {
    this->x += x;
    this->y += y;
}

uint8_t Bitmap::getX() {
    return x;
}

uint8_t Bitmap::getY() {
    return y;
}

void Bitmap::setRectangle(uint8_t r_x, uint8_t r_y, uint8_t r_w, uint8_t r_h) {
    this->r_x = r_x;
    this->r_y = r_y;
    this->r_w = r_w;
    this->r_h = r_h;
}

uint8_t Bitmap::getRectX() {
    return r_x;
}

uint8_t Bitmap::getRectY() {
    return r_y;
}

uint8_t Bitmap::getRectW() {
    return r_w;
}

uint8_t Bitmap::getRectH() {
    return r_h;
}

void Bitmap::draw(SSD1305Params &ssdp) {
    for (uint8_t d_y = 0; d_y < r_h; d_y++) {
        for (uint8_t d_x = 0; d_x < r_w; d_x++) {
            uint8_t disp_x = x + d_x;
            uint8_t disp_y = y + d_y;

            int bmp_addr = ((r_x + d_x) + ((r_y + d_y) * width)) / 8;

            int pix_status =
                (bitmap[bmp_addr] & (0x1 << ((r_x + d_x) % 8))) ?
                PIXEL_ON : PIXEL_OFF;

            ssdp.setPixel(disp_x, disp_y, pix_status);
        }
    }
}