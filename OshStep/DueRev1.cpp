/*
 * DueRev1.cpp
 *
 * Created: 2/27/2015 11:01:12 PM
 *  Author: hawthm
 */ 

 #include "sam.h"
 #include "DueRev1.h"

 // Stores our TC0 callback
 void (*__due_tc0_callback)(void);

 // Timer setup and interrupt attachment
 void setupTimer0(long time, void(*callback)(void)) {
     
     PMC->PMC_PCER0 = 1 << 27;                   // Enable Clock for TC0
     TC0->TC_CHANNEL->TC_CCR = TC_CCR_CLKDIS;    // Disable TC clock
     TC0->TC_CHANNEL->TC_IDR = 0xFFFFFFFF;       // Disable interrupts
     TC0->TC_CHANNEL->TC_SR;                     // Clear status register

     // Set mode
     TC0->TC_CHANNEL->TC_CMR = TC_CMR_CPCTRG | TC_CMR_TCCLKS_TIMER_CLOCK5;
     
     TC0->TC_CHANNEL[0].TC_RC = time;            // Compare value

     // Configure and enable interrupt on RC compare
     NVIC_EnableIRQ((IRQn_Type) ID_TC0);
     TC0->TC_CHANNEL->TC_IER = TC_IER_CPCS;

     // Reset counter (SWTRG) and enable counter clock(CLKEN)
     TC0->TC_CHANNEL[0].TC_CCR = TC_CCR_CLKEN | TC_CCR_SWTRG;

 }

 void TC0_Handler(void) {
     __due_tc0_callback();
 }

 void pinSetMode(Port p, int pin, Mode m) {
    switch (m) {
      case INPUT:
        switch (p) {
          case A:
            PIOA->PIO_PER=1<<pin;
            PIOA->PIO_ODR=1<<pin;
            break;
          case B:
            PIOB->PIO_PER=1<<pin;
            PIOB->PIO_ODR=1<<pin;
            break;
          case C:
            PIOC->PIO_PER=1<<pin;
            PIOC->PIO_ODR=1<<pin;
            break;
          case D:
            PIOD->PIO_PER=1<<pin;
            PIOD->PIO_ODR=1<<pin;
            break;
        }
        break;
      case OUTPUT:
        switch (p) {
          case A:
            PIOA->PIO_PER=1<<pin;
            PIOA->PIO_OER=1<<pin;
            break;
          case B:
            PIOB->PIO_PER=1<<pin;
            PIOB->PIO_OER=1<<pin;
            break;
          case C:
            PIOC->PIO_PER=1<<pin;
            PIOC->PIO_OER=1<<pin;
            break;
          case D:
            PIOD->PIO_PER=1<<pin;
            PIOD->PIO_OER=1<<pin;
            break;
        }
        break;
      case PERIPHERAL_A:
        switch (p) {
          case A:
            PIOA->PIO_PDR=1<<pin;
            PIOA->PIO_ABSR &= ~(1<<pin);
            break;
          case B:
            PIOB->PIO_PDR=1<<pin;
            PIOB->PIO_ABSR &= ~(1<<pin);
            break;
          case C:
            PIOC->PIO_PDR=1<<pin;
            PIOC->PIO_ABSR &= ~(1<<pin);
            break;
          case D:
            PIOD->PIO_PDR=1<<pin;
            PIOD->PIO_ABSR &= ~(1<<pin);
            break;
        }
        break;
      case PERIPHERAL_B:
        switch (p) {
          case A:
            PIOA->PIO_PDR=1<<pin;
            PIOA->PIO_ABSR |=1 <<pin;
            break;
          case B:
            PIOB->PIO_PDR=1<<pin;
            PIOB->PIO_ABSR |= 1<<pin;
            break;
          case C:
            PIOC->PIO_PDR=1<<pin;
            PIOC->PIO_ABSR |= 1<<pin;
            break;
          case D:
            PIOD->PIO_PDR=1<<pin;
            PIOD->PIO_ABSR |= 1<<pin;
            break;
          }
          break;
    }
 }

 void pinEnablePullup(Port p, int pin) {
    switch (p) {
      case A:
        PIOA->PIO_PUER=1<<pin;
        break;
      case B:
        PIOB->PIO_PUER=1<<pin;
        break;
      case C:
        PIOC->PIO_PUER=1<<pin;
        break;
      case D:
        PIOD->PIO_PUER=1<<pin;
        break;
    }
 }

 void pinDisablePullup(Port p, int pin) {
    switch (p) {
      case A:
        PIOA->PIO_PUDR=1<<pin;
        break;
      case B:
        PIOB->PIO_PUDR=1<<pin;
        break;
      case C:
        PIOC->PIO_PUDR=1<<pin;
        break;
      case D:
        PIOD->PIO_PUDR=1<<pin;
        break;
    }
 }

 void pinSetOutput(Port p, int pin, int level) {
    switch (level) {
      case HIGH:
        switch (p) {
          case A:
            PIOA->PIO_SODR=1<<pin;
            break;
          case B:
            PIOB->PIO_SODR=1<<pin;
            break;
          case C:
            PIOC->PIO_SODR=1<<pin;
            break;
          case D:
            PIOD->PIO_SODR=1<<pin;
            break;
        }
        break;
      case LOW:
        switch (p) {
          case A:
            PIOA->PIO_CODR=1<<pin;
            break;
          case B:
            PIOB->PIO_CODR=1<<pin;
            break;
          case C:
            PIOC->PIO_CODR=1<<pin;
            break;
          case D:
            PIOD->PIO_CODR=1<<pin;
            break;
        }
        break;
    }
 }

 int pinGetOutputStatus(Port p, int pin) {
    switch (p) {
      case A:
        return (PIOA->PIO_ODSR >> pin) & 0x1;
      case B:
        return (PIOB->PIO_ODSR >> pin) & 0x1;
      case C:
        return (PIOC->PIO_ODSR >> pin) & 0x1;
      case D:
        return (PIOD->PIO_ODSR >> pin) & 0x1;
    }
    return -1;
 }