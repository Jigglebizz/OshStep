/*
 * SSD1305.cpp
 *
 * Created: 3/4/2015 11:37:25 PM
 *  Author: hawthm
 */ 

 #include "SSD1305.h"

 #include "parameter/SSD1305Params.h"

 #include "../Reporting.h"

 #include <stdlib.h>

 int SSD1305::open( void* params) {
    pinSetMode(dcPort,  dcPin,  OUTPUT);
    pinSetMode(resPort, resPin, OUTPUT);
    pinDisablePullup(dcPort, dcPin);
    pinDisablePullup(resPort, resPin);
    pinSetOutput(resPort, resPin, LOW);


    SPIParams *sp = (SPIParams*)malloc(sizeof(SPIParams));
    sp->csPort = csPort;
    sp->csPin  = csPin;

    SPI::Instance().open(sp);
    free(sp);

    pinSetOutput(resPort, resPin, HIGH);
    pinSetOutput(dcPort,  dcPin,  LOW);

    // Do our initialization
    SPIWriteParams* swp = (SPIWriteParams*)malloc(sizeof(SPIWriteParams));
    swp->mode = SPI_CONTINUE;
    swp->data = 0xAE;
    SPI::Instance().write((void*)swp);
    swp->data = 0xD5;
    SPI::Instance().write((void*)swp);  // set display clock divider ratio
    swp->data = 0xA0;
    SPI::Instance().write((void*)swp);
    swp->data = 0xA8;
    SPI::Instance().write((void*)swp);  // set multiplex ratio
    swp->data = 0x3F;
    SPI::Instance().write((void*)swp);
    swp->data = 0xD3;
    SPI::Instance().write((void*)swp);  // set display offset
    swp->data = 0x00;
    SPI::Instance().write((void*)swp);
    swp->data = 0x40;
    SPI::Instance().write((void*)swp);  // set display start line
    swp->data = 0xAD;
    SPI::Instance().write((void*)swp);  // set master configuration
    swp->data = 0x8E;
    SPI::Instance().write((void*)swp);
    swp->data = 0xD8;
    SPI::Instance().write((void*)swp);  // Set area color mode
    swp->data = 0x05;
    SPI::Instance().write((void*)swp);
    swp->data = 0xA1;
    SPI::Instance().write((void*)swp);  // Set segment re-map
    swp->data = 0xC8;
    SPI::Instance().write((void*)swp);  // Set com output scan direction
    swp->data = 0xDA;
    SPI::Instance().write((void*)swp);  // Set com pins hardware configuration
    swp->data = 0x12;
    SPI::Instance().write((void*)swp);
    swp->data = 0x91;
    SPI::Instance().write((void*)swp);  // Set lookup table
    swp->data = 0x3F;
    SPI::Instance().write((void*)swp);
    swp->data = 0x3F;
    SPI::Instance().write((void*)swp);
    swp->data = 0x3F;
    SPI::Instance().write((void*)swp);
    swp->data = 0x3F;
    SPI::Instance().write((void*)swp);
    swp->data = 0x81;
    SPI::Instance().write((void*)swp);  // Set current control for bank 0
    swp->data = 0x8F;
    SPI::Instance().write((void*)swp);
    swp->data = 0xD9;
    SPI::Instance().write((void*)swp);  // Set pre-charge period
    swp->data = 0xD2;
    SPI::Instance().write((void*)swp);
    swp->data = 0xDB;
    SPI::Instance().write((void*)swp);  // Set vcomh deselect level
    swp->data = 0x34;
    SPI::Instance().write((void*)swp);
    swp->data = 0xA4;
    SPI::Instance().write((void*)swp);  // Set entire display on/off
    swp->data = 0xA6;
    SPI::Instance().write((void*)swp);  // set normal/inverse display
    swp->data = 0x20;
    SPI::Instance().write((void*)swp);  // Page mode
    swp->data = 0X00;
    SPI::Instance().write((void*)swp);
    
    SPI::Instance().ioctl(SPI_BLOCK_UNTIL_TRANSFERRED, NULL);
    // Clear content
    pinSetOutput(dcPort, dcPin, HIGH);

    // Transfer 0 for every buffer
    swp->data = 0x00;
    for (int i = 0; i < ((SSD1305Params*)params)->total_buffers; i++) {
        SPI::Instance().write(swp);
    }

    SPI::Instance().ioctl(SPI_BLOCK_UNTIL_TRANSFERRED, NULL);
    pinSetOutput(dcPort, dcPin, LOW);

    swp->data = 0xAF;
    swp->mode = SPI_LAST;
    SPI::Instance().write(swp);

    free(swp);

    return 0;
 }

 int SSD1305::close() {
    return 0;
 }

 int SSD1305::write( void* params) {
    SSD1305Params *ssdp = (SSD1305Params*)params;

    pinSetOutput(dcPort, dcPin, HIGH);
    SPIWriteParams *swp = (SPIWriteParams*)malloc(sizeof(SPIWriteParams));
    
    // transfer color data (we don't use this)
    swp->data = 0x00;
    swp->mode = SPI_CONTINUE;
    for (int i = 0; i < ssdp->junk_buffer; i++) {
        SPI::Instance().write(swp);
    }

    for (int i = 0; i < ssdp->visible_buffers; i++) {
        swp->data = ssdp->buffer[i];
        if (i == ssdp->visible_buffers - 1)
            swp->mode = SPI_LAST;
        SPI::Instance().write(swp);

        if (i % ssdp->width == ssdp->width - 1 && i != ssdp->visible_buffers - 1) {
            for (int j = 0; j < ssdp->blank; j++) {
                swp->data = 255;
                SPI::Instance().write(swp);
            }
        }
    }

    free(swp);
    return 0;
 }

 void *SSD1305::read() {
    return (void*)0;
 }

 void *SSD1305::ioctl(int ioctl_t, void* params) {
    return (void*)0;
 }