/*
 * DriverInterface.h
 *
 * Created: 2/15/2015 3:34:53 PM
 *  Author: hawthm
 */ 


#ifndef DRIVER_H_
#define DRIVER_H_

class Driver {
  public:
    virtual int   open(void*)       = 0;
    virtual int   close()           = 0;
    virtual int   write(void*)      = 0;
    virtual void* read()            = 0;
    virtual void* ioctl(int, void*) = 0;
};



#endif /* DRIVER_H_ */