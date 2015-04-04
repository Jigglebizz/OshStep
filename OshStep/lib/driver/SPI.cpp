/*
 * SPI.cpp
 *
 * Created: 3/1/2015 9:26:23 PM
 *  Author: hawthm
 */

 #include "SPI.h"
 #include "sam.h"
 #include "ShiftRegisters.h"
 #include "../Reporting.h"

 #include <stdlib.h> // Used for definition of NULL

 int SPI::open( void* data) {
    SPIParams *params = (SPIParams*)data;
    csPort = params->csPort;
    csPin  = params->csPin;

    // Configure cs pin
    pinSetMode(csPort,   csPin,   OUTPUT);
    pinDisablePullup(csPort, csPin);
    pinSetOutput(csPort, csPin, HIGH);

    // Configure SPI peripheral pins
    pinSetMode(misoPort, misoPin, PERIPHERAL_A);
    pinSetMode(mosiPort, mosiPin, PERIPHERAL_A);
    pinSetMode(clkPort,  clkPin,  PERIPHERAL_A);

    // Enable SPI controller
    PMC->PMC_PCER0 = 1<<ID_SPI0;    
    
    // Disable SPI in SPI controller so we can configure it
    SPI0->SPI_CR = SPI_CR_SPIDIS;

    // Mode Register = Master, Disable fault detection, NPCS[3:0] = 
    SPI0->SPI_MR = SPI_MR_MSTR | SPI_MR_MODFDIS | 0x000E0000; 

    // SPCK baudrate = MCK / SCBR = 84 MHz / 40 (0x28) = 2.1Mhz
    SPI0->SPI_CSR[0] |= 0x00002800 | SPI_CSR_NCPHA;

    // Enable SPI in SPI controller
    SPI0->SPI_CR = SPI_CR_SPIEN;    

    return 0;
 }

 int SPI::close() {
    SPI0->SPI_CR = SPI_CR_SPIDIS;
    PMC->PMC_PCDR0 = 1<<ID_SPI0;
    return 0;
 }

 int SPI::write( void* data) {
    SPIWriteParams *swp = (SPIWriteParams*)data;

    // Wait for previous transfer to complete
    while ((SPI0->SPI_SR & SPI_SR_TXEMPTY) == 0);

    // Send data
    if (!csOpen) {
        pinSetOutput(csPort, csPin, LOW);
        csOpen = 1;
    }
    SPI0->SPI_TDR = swp->data;

    // Wait til data has been sent
    // (SPI_BLOCK_UNTIL_TRANSFERRED ioctl does the same)
    while (!(SPI0->SPI_SR & SPI_SR_TXEMPTY)) {};
    if (swp->mode == SPI_LAST) {
        pinSetOutput(csPort, csPin, HIGH);
        csOpen = 0;
    }

    // We're out
    return 0;
 }

 void* SPI::read() {

    return (void*)NULL;
 }

 void* SPI::ioctl(int ioctl_t, void *params) {
    if (ioctl_t == SPI_BLOCK_UNTIL_TRANSFERRED) {
        while (!(SPI0->SPI_SR & SPI_SR_TXEMPTY)) {};
    }

    return (void*)NULL;
}