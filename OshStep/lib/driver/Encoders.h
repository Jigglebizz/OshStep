/*
 * Encoders.h
 *
 * Created: 3/1/2015 4:22:12 PM
 *  Author: hawthm
 */ 

#ifndef ENCODERS_H_
#define ENCODERS_H_

#include "Driver.h"
#include "../../system.h"

#include <stdint.h>

typedef struct EncodersStatus {
    int16_t a_relative;
    int16_t b_relative;
    int16_t c_relative;
    int16_t d_relative;
} EncodersStatus;

class Encoders : Driver {
  private:
    // Ports and Pins
    static const Port a1Port =  B;
    static const int  a1Pin  = 26;
    static const Port b1Port =  A;
    static const int  b1Pin  = 14;
    static const Port a2Port =  A;
    static const int  a2Pin  = 15;
    static const Port b2Port =  D;
    static const int  b2Pin  =  0;
    static const Port a3Port =  D;
    static const int  a3Pin  =  1;
    static const Port b3Port =  D;
    static const int  b3Pin  =  2;
    static const Port a4Port =  D;
    static const int  a4Pin  =  3;
    static const Port b4Port =  D;
    static const int  b4Pin  =  6;

    // Define as a singleton
    Encoders() {};
    Encoders(Encoders const&);
    void operator=(Encoders const&);
  public:
    static Encoders& Instance()
    {
        static Encoders instance;
        return instance;
    }
    int     open(void*);
    int     close();
    int     write(void*);
    void*   read();
    void*   ioctl(int, void*);
};


#endif /* ENCODERS_H_ */