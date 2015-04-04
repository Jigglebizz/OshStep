/*
 * Display.h
 *
 * Created: 4/1/2015 6:56:05 PM
 *  Author: hawthm
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "display/Bitmap.h"
#include "driver/parameter/SSD1305Params.h"

enum TextAlignment {LEFT, CENTER, RIGHT};
enum Font {SMALL_FONT, LARGE_FONT};

class Display {
  private:
    SSD1305Params ssdp;
  public:
    Display();
    ~Display();
    void drawBitmap(Bitmap&);
    void drawText(uint8_t, uint8_t, Font, const char*);
    void drawLine(int, int, int, int);
    void drawRectangle(int, int, int, int);
    void drawFilledRectangle(int, int, int, int);
    void drawCircle(int, int, int);
    void drawFilledCircle(int, int, int);
    void drawPixel(int, int);
    void paint();
};

#endif /* DISPLAY_H_ */