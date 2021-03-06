/*
 * Reporting.h
 *
 * Created: 3/10/2015 9:21:38 PM
 *  Author: hawthm
 */ 


#ifndef REPORTING_H_
#define REPORTING_H_

#include "driver/ShiftRegisters.h"

#include <stdlib.h>

enum VisualStateMethod { LIGHTS, DISPLAY};
enum Priority { PRIORITY_DEBUG, PRIORITY_PANIC};

class Reporting {
  private:
    Reporting() {};

    ShiftRegistersWriteParams srwp;

    // Make this a singleton
    Reporting(Reporting const&);
    void operator=(Reporting const&);
  public:
    static Reporting &Instance() {
        static Reporting instance;
        return instance;
    };
    void reportCode(Priority, VisualStateMethod, uint32_t);
    void reportText(Priority, const char*);
    void clearReport();
};



#endif /* REPORTING_H_ */