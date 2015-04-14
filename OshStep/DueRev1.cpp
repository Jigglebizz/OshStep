/*
 * DueRev1.cpp
 *
 * Created: 2/27/2015 11:01:12 PM
 *  Author: hawthm
 */ 

#include "sam.h"
#include "DueRev1.h"

#include "lib/Reporting.h"

#include <tgmath.h> // For log2

uint8_t __isr_enabled_mask = 0;

volatile __IsrBank __isr_a;
volatile __IsrBank __isr_b;
volatile __IsrBank __isr_c;
volatile __IsrBank __isr_d;

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
            // Enable clock if it isn't enabled
            if (~(PMC->PMC_PCSR0 >> ID_PIOA) & 0x1)
                PMC->PMC_PCER0 = 0x1u<<ID_PIOA;
            PIOA->PIO_PER=0x1u<<pin;
            PIOA->PIO_ODR=0x1u<<pin;
            break;
          case B:
            if (~(PMC->PMC_PCSR0 >> ID_PIOB) & 0x1)
                PMC->PMC_PCER0 = 0x1u<<ID_PIOB;
            PIOB->PIO_PER=0x1u<<pin;
            PIOB->PIO_ODR=0x1u<<pin;
            break;
          case C:
            if (~(PMC->PMC_PCSR0 >> ID_PIOC) & 0x1)
                PMC->PMC_PCER0 = 0x1u<<ID_PIOC;
            PIOC->PIO_PER=0x1u<<pin;
            PIOC->PIO_ODR=0x1u<<pin;
            break;
          case D:
            if (~(PMC->PMC_PCSR0 >> ID_PIOD) & 0x1)
                PMC->PMC_PCER0 = 0x1u<<ID_PIOD;
            PIOD->PIO_PER=0x1u<<pin;
            PIOD->PIO_ODR=0x1u<<pin;
            break;
        }
        break;
      case OUTPUT:
        switch (p) {
          case A:
            PIOA->PIO_PER=0x1u<<pin;
            PIOA->PIO_OER=0x1u<<pin;
            break;
          case B:
            PIOB->PIO_PER=0x1u<<pin;
            PIOB->PIO_OER=0x1u<<pin;
            break;
          case C:
            PIOC->PIO_PER=0x1u<<pin;
            PIOC->PIO_OER=0x1u<<pin;
            break;
          case D:
            PIOD->PIO_PER=0x1u<<pin;
            PIOD->PIO_OER=0x1u<<pin;
            break;
        }
        break;
      case PERIPHERAL_A:
        switch (p) {
          case A:
            PIOA->PIO_PDR=0x1u<<pin;
            PIOA->PIO_ABSR &= ~(0x1u<<pin);
            break;
          case B:
            PIOB->PIO_PDR=0x1u<<pin;
            PIOB->PIO_ABSR &= ~(0x1u<<pin);
            break;
          case C:
            PIOC->PIO_PDR=0x1u<<pin;
            PIOC->PIO_ABSR &= ~(0x1u<<pin);
            break;
          case D:
            PIOD->PIO_PDR=0x1u<<pin;
            PIOD->PIO_ABSR &= ~(0x1u<<pin);
            break;
        }
        break;
      case PERIPHERAL_B:
        switch (p) {
          case A:
            PIOA->PIO_PDR=0x1u<<pin;
            PIOA->PIO_ABSR |=1 <<pin;
            break;
          case B:
            PIOB->PIO_PDR=0x1u<<pin;
            PIOB->PIO_ABSR |= 0x1u<<pin;
            break;
          case C:
            PIOC->PIO_PDR=0x1u<<pin;
            PIOC->PIO_ABSR |= 0x1u<<pin;
            break;
          case D:
            PIOD->PIO_PDR=0x1u<<pin;
            PIOD->PIO_ABSR |= 0x1u<<pin;
            break;
          }
          break;
    }
}

void pinEnablePullup(Port p, int pin) {
    switch (p) {
      case A:
        PIOA->PIO_PUER=0x1u<<pin;
        break;
      case B:
        PIOB->PIO_PUER=0x1u<<pin;
        break;
      case C:
        PIOC->PIO_PUER=0x1u<<pin;
        break;
      case D:
        PIOD->PIO_PUER=0x1u<<pin;
        break;
    }
}

void pinDisablePullup(Port p, int pin) {
    switch (p) {
      case A:
        PIOA->PIO_PUDR=0x1u<<pin;
        break;
      case B:
        PIOB->PIO_PUDR=0x1u<<pin;
        break;
      case C:
        PIOC->PIO_PUDR=0x1u<<pin;
        break;
      case D:
        PIOD->PIO_PUDR=0x1u<<pin;
        break;
    }
}

void pinSetOutput(Port p, int pin, int level) {
    switch (level) {
      case HIGH:
        switch (p) {
          case A:
            PIOA->PIO_SODR=0x1u<<pin;
            break;
          case B:
            PIOB->PIO_SODR=0x1u<<pin;
            break;
          case C:
            PIOC->PIO_SODR=0x1u<<pin;
            break;
          case D:
            PIOD->PIO_SODR=0x1u<<pin;
            break;
        }
        break;
      case LOW:
        switch (p) {
          case A:
            PIOA->PIO_CODR=0x1u<<pin;
            break;
          case B:
            PIOB->PIO_CODR=0x1u<<pin;
            break;
          case C:
            PIOC->PIO_CODR=0x1u<<pin;
            break;
          case D:
            PIOD->PIO_CODR=0x1u<<pin;
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

int pinReadInput(Port p, int pin) {
    switch (p) {
      case A:
        return (PIOA->PIO_PDSR >> pin) & 0x1;
      case B:
        return (PIOB->PIO_PDSR >> pin) & 0x1;
      case C:
        return (PIOC->PIO_PDSR >> pin) & 0x1;
      case D:
        return (PIOD->PIO_PDSR >> pin) & 0x1;
    }
    return -1;
}

void attachInterrupt(Port p, int pin, void(*isr)(Port, int)) {
    // Initialize interrupt for Port
    volatile __IsrBank *isr_bank = 0;
    switch (p) {
      case A:
        isr_bank = &__isr_a;
        if (!(__isr_enabled_mask & __ISR_ENABLED_A)) {
            __isr_enabled_mask |= __ISR_ENABLED_A;
            NVIC_EnableIRQ((IRQn_Type) ID_PIOA);
        }
        break;
      case B:
        isr_bank = &__isr_b;
        if (!(__isr_enabled_mask & __ISR_ENABLED_B)) {
            __isr_enabled_mask |= __ISR_ENABLED_B;
            NVIC_EnableIRQ(PIOB_IRQn);  
        }
        break;
      case C:
        isr_bank = &__isr_c;
        if (!(__isr_enabled_mask & __ISR_ENABLED_C)) {
            __isr_enabled_mask |= __ISR_ENABLED_C;
            NVIC_EnableIRQ((IRQn_Type) ID_PIOC);
        }
        break;
      case D:
        isr_bank = &__isr_d;
        if (!(__isr_enabled_mask & __ISR_ENABLED_D)) {
            __isr_enabled_mask |= __ISR_ENABLED_D;
            NVIC_EnableIRQ((IRQn_Type) ID_PIOD);
        }
        break;
    }

    (*isr_bank)[pin] = isr;
    switch (p) {
      case A:
        PIOA->PIO_IER = 0x1u << pin;
        break;
      case B:
        PIOB->PIO_IER = 0x1u << pin;
        break;
      case C:
        PIOC->PIO_IER = 0x1u << pin;
        break;
      case D:
        PIOD->PIO_IER = 0x1u << pin;
        break;
    }

}

// This is some nonsense. I'm sorry. It should be really fast.
void pioIsr(Port p) {
    int pin_mask = 0;
    volatile __IsrBank *isr_bank = 0;

    switch (p) {
      case A:
        pin_mask = PIOA->PIO_ISR;
        isr_bank = &__isr_a;
        break;
      case B:
        pin_mask = PIOB->PIO_ISR;
        isr_bank = &__isr_b;
        break;
      case C:
        pin_mask = PIOC->PIO_ISR;
        isr_bank = &__isr_c;
        break;
      case D:
        pin_mask = PIOD->PIO_ISR;
        isr_bank = &__isr_d;
        break;
    }
    
    int pin = log2(pin_mask);       // Convert the mask to a pin number quickly
    __Isr isr = (*isr_bank)[pin];

    if (isr != NULL) {
        isr(p, pin);
    }
}

void PIOA_Handler(void) {
    pioIsr(A);
}

void PIOB_Handler(void) {
    pioIsr(B);
}

void PIOC_Handler(void) {
    pioIsr(C);
}

void PIOD_Handler(void) {
    pioIsr(D);
}