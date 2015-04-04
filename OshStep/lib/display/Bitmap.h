/*
 * Bitmap.h
 *
 * Created: 4/2/2015 9:37:57 PM
 *  Author: hawthm
 */ 


#ifndef BITMAP_H_
#define BITMAP_H_

#include <stdint.h>
#include "../driver/parameter/SSD1305Params.h"

class Bitmap {
  friend class Display;
  private:
    uint8_t x, y;                   // Position onscreen
    uint8_t r_x, r_y, r_w, r_h;     // Viewing rectangle of bitmap          
    const unsigned char* bitmap;    // Reference to bitmap

    void draw(SSD1305Params&);
    void init(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, const unsigned char*);
  public:
    int width, height;  // Full w and h of bitmap

    Bitmap(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, const unsigned char*);
    Bitmap(uint8_t, uint8_t, uint8_t, uint8_t, const unsigned char*);
    Bitmap(uint8_t, uint8_t, const unsigned char*);
    Bitmap(const unsigned char*);

    // Functions for placement on screen
    void moveTo(uint8_t, uint8_t);
    void moveRelative(uint8_t, uint8_t);
    uint8_t getX();
    uint8_t getY();

    // Functions for view rectangle
    void setRectangle(uint8_t, uint8_t, uint8_t, uint8_t);
    uint8_t getRectX();
    uint8_t getRectY();
    uint8_t getRectW();
    uint8_t getRectH();
};

#endif /* BITMAP_H_ */