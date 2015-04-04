/*
 * TouchSensors.h
 *
 * Created: 3/1/2015 5:47:58 PM
 *  Author: hawthm
 */ 


#ifndef TOUCHSENSORS_H_
#define TOUCHSENSORS_H_

typedef struct TouchSensorsStatus {
    uint16_t sequencer;
    uint8_t  function;
} TouchSensorsStatus; 

class TouchSensors : Driver {
  private:
    // Ports and pins
    // Send
    static const Port sendPort      =  D;
    static const int  sendPin       =  7;
    // Receive
    static const Port t1Port        =  D;
    static const int  t1Pin         =  9;
    static const Port t2Port        =  A;
    static const int  t2Pin         =  7;
    static const Port t3Port        =  D;
    static const int  t3Pin         = 10;
    static const Port t4Port        =  C;
    static const int  t4Pin         =  1;
    static const Port t5Port        =  C;
    static const int  t5Pin         =  2;
    static const Port t6Port        =  C;
    static const int  t6Pin         =  3;
    static const Port t7Port        =  C;
    static const int  t7Pin         =  4;
    static const Port t8Port        =  C;
    static const int  t8Pin         =  5;
    static const Port t9Port        =  C;
    static const int  t9Pin         =  6;
    static const Port t10Port       =  C;
    static const int  t10Pin        =  7;
    static const Port t11Port       =  C;
    static const int  t11Pin        =  8;
    static const Port t12Port       =  C;
    static const int  t12Pin        =  9;
    static const Port t13Port       =  A;
    static const int  t13Pin        = 19;
    static const Port t14Port       =  A;
    static const int  t14Pin        = 20;
    static const Port t15Port       =  C;
    static const int  t15Pin        = 19;
    static const Port t16Port       =  C;
    static const int  t16Pin        = 18;
    // Function
    static const Port playPort      =  C;
    static const int  playPin       = 17;
    static const Port recordPort    =  C;
    static const int  recordPin     = 16;
    static const Port shiftPort     =  C;
    static const int  shiftPin      = 15;
    static const Port yesPort       =  C;
    static const int  yesPin        = 14;
    static const Port upPort        =  C;
    static const int  upPin         = 13;
    static const Port downPort      =  C;
    static const int  downPin       = 12;
    static const Port rightPort     =  B;
    static const int  rightPin      = 21;
    static const Port leftPort      =  B;
    static const int  leftPin       = 14;

    // Singleton instance
    static TouchSensors *instance;
  protected:
    TouchSensors();
  public
    static TouchSensors* Instance();
    int     open(void*);
    int     close();
    int     write(void*);
    void*   read();
    void*   ioctl(int, void*);
};




#endif /* TOUCHSENSORS_H_ */