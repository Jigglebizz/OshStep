/*
 * ShiftRegister.h
 *
 * Created: 2/16/2015 1:16:45 PM
 *  Author: hawthm
 */ 

#ifndef SHIFTREGISTERS_H_
#define SHIFTREGISTERS_H_

#include "Driver.h"
#include "../../system.h"
#include <stdint.h>

typedef struct ShiftRegistersWriteParams {
    uint32_t stepLights;
    uint16_t functionLights;
} ShiftRegistersWriteParams;

class ShiftRegisters : Driver {
  private:
    // Declare our ports and pins
    static const Port seqSdPort    =  C;
    static const int  seqSdPin     = 23;
    static const Port seqClkPort   =  C;
    static const int  seqClkPin    = 24;
    static const Port seqOePort    =  C;
    static const int  seqOePin     = 25;

    static const Port funcSdPort   =  C;
    static const int  funcSdPin    = 29;
    static const Port funcClkPort  =  C;
    static const int  funcClkPin   = 21;
    static const Port funcOePort   =  C;
    static const int  funcOePin    = 22;

    // Make this a singleton
    ShiftRegisters() {};
    ShiftRegisters(ShiftRegisters const&);
    void operator=(ShiftRegisters const&);
  public:
    static ShiftRegisters& Instance()
    {
        static ShiftRegisters instance;
        return instance;
    };
    int   open(void*);
    int   close();
    int   write(void*);
    void* read();
    void* ioctl(int, void*);
};


#endif /* SHIFTREGISTER_H_ */