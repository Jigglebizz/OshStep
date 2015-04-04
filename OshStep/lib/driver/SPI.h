/*
 * SPI.h
 *
 * Created: 3/1/2015 9:18:45 PM
 *  Author: hawthm
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "Driver.h"
#include "../../system.h"
#include "../Reporting.h"

#include <stdint.h>

#define SPI_LAST     0
#define SPI_CONTINUE 1

#define SPI_BLOCK_UNTIL_TRANSFERRED 0

typedef struct SPIParams {
    Port csPort;
    int  csPin;
} SPIParams;

typedef struct SPIWriteParams {
    uint16_t data;
    int      mode;
} SPIWriteParams;

class SPI : Driver {
  private:
    static const Port misoPort      =  A;
    static const int  misoPin       = 25;
    static const Port mosiPort      =  A;
    static const int  mosiPin       = 26;
    static const Port clkPort       =  A;
    static const int  clkPin        = 27;

    Port csPort;
    int  csPin;
    int  csOpen;

    SPI() {
        csOpen = 0;
    }

    // Make it a singleton
    SPI(SPI const&);
    void operator=(SPI const&);
  public:
    static SPI& Instance() {
        static SPI instance;
        return instance;
    };
    int     open(void*);
    int     close();
    int     write(void*);
    void*   read();
    void*   ioctl(int, void*);
};



#endif /* SPI_H_ */