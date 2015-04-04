/*
 * SSD1305.h
 *
 * Created: 3/1/2015 9:10:47 PM
 *  Author: hawthm
 */ 


#ifndef SSD1305_H_
#define SSD1305_H_

#include "Driver.h"
#include "parameter/SSD1305Params.h"

#include "../../system.h"
#include "SPI.h"

#include <stdint.h>

#define SSD1305_ORIENTATION

class SSD1305 : Driver {
    //friend class SSD1305WriteParams;
  private:
    // Ports and pins
    static const Port csPort    =  C;
    static const int  csPin     = 26;
    static const Port resPort   =  B;
    static const int  resPin    = 25;
    static const Port dcPort    =  C;
    static const int  dcPin     = 28;

    SSD1305() {};
    SSD1305(SSD1305 const&);
    void operator=(SSD1305 const&);
  public:
    static SSD1305& Instance() {
        static SSD1305 instance;
        return instance;
    };
    int     open(void*);
    int     close();
    int     write(void*);
    void*   read();
    void*   ioctl(int, void*);
};



#endif /* SSD1305_H_ */