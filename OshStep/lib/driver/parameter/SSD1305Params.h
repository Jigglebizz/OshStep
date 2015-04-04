/*
 * SSD1305WriteParams.h
 *
 * Created: 3/6/2015 11:15:32 AM
 *  Author: hawthm
 */ 


#ifndef SSD1305PARAMS_H_
#define SSD1305PARAMS_H_

#include "../SSD1305.h"

#include <stdint.h>

#define PIXEL_ON  1
#define PIXEL_OFF 0



class SSD1305Params {
    friend class SSD1305;
  private:
    static const int junk_buffer        = 532;  // buffers beyond display
    static const int blank              = 4;    // Offscreen buffers
    static const int pix_in_page        = 8;    // Pixels in a buffer page
    static const int total_buffers      = 1056;
    static const int visible_buffers    = 512;  // Visible buffers
                                                // (width * height) / pix_in_page   
  public:
    static const int width              = 128;
    static const int height             = 32;

    uint8_t buffer[visible_buffers];

    SSD1305Params();
    ~SSD1305Params();

    void setPixel(int, int, int);
    void clear(int);
};


#endif /* SSD1305WRITEPARAMS_H_ */