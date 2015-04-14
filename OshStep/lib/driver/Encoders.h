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
    int16_t relative_position[4];
} EncodersStatus;
/*
typedef struct encoderState {
    uint8_t mask;
    struct encoderState *next;
    struct encoderState *prev;
} EncoderState;
*/

class Encoders : Driver {
  private:
    // Ports and Pins
    static const Port aPorts[];
    static const Port bPorts[];
    static const int  aPins[];
    static const int  bPins[];

    // Volatile, because these will change during interrupts
    volatile EncodersStatus status;
    EncodersStatus readStatus;
    volatile uint8_t states[4];
    //volatile EncoderState *states[4];

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
    void    interrupt_callback(Port, int);
};

void __encoders_isr(Port, int);

#endif /* ENCODERS_H_ */