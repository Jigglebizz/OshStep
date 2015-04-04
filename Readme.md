## A Note on Development and Collaboration
This project has been in development for quite a while. It started in the Arduino IDE, met its limits, and moved on to Atmel Studio 6.2. There have been a lot of challenges getting this to work in Atmel Studio, as I'm very new to embedded system development and C++ in general. My expertise is in languages like Java and C#. This project, if anything, has proven to me how much a language can matter. I always thought that C++ was C syntax with Java-like features. Hooboy, the Stack Overflow community would eat me alive.

I recognize that collaboration on this project may be a near-impossibility, but if you are interested please do not hesitate to contact me and ask what can be done. I have several prototype boards and extra components to populate them that I would gladly email over sneakernet to those interested.

## Project Description
OSHStep is my attempt to bring a fully-featured professional hardware step sequencer to the masses. Does the world really need another step sequencer? In my opinion, yes it does. Step sequencers frequently implement a static grid structure to store their patterns. The OSHStep will handle patterns in a fully-dynamic linked list structure. This means you get polyphony, infinite resolution (to a certain degree), ghost notes, variable speed rolls - all the features you would come to expect from a DAW's MIDI sequencer - in hardware!

In order to bypass the limitations of a static grid, you are either forced to use hardware that depends on a DAW (Ableton Push, NI Maschine, MPC Rennaisance), or shell out enough cash to buy an entire synthesizer (Cirkon Sequentix, Standalone MPC Series). In my opinion, you shouldn't have to take out a loan to get a hands-on electronic music workflow.

The OSHStep is entirely open-source - The hardware design files are created in DipTrace, a (sort of) free software suite for PCB CAD work. Our platform is the Arduino Due - part of the Arduino suite of OSH prototyping boards. The total cost of materials, at present, including the Arduino Due, PCB, and 128x32 OLED display falls just short of $150. That's nearly 10% the cost of the "professional grade" sequencers!

## Features
# Implemented
* OLED Display Integration
* Graphics Library for Display
  * Bitmap Support
  * Text Support
* Bitmap-to-code conversion script (requires Perl)
* SPI Drivers
* Debugging/Reporting Mechanism
* Shift Register drivers
* Support for 24 RG indication LED's

# TODO
* MIDI/UART Drivers
* Encoder Drivers
* Touch-Sensor Drivers
* Pattern/Song Data Structure
* EEPROM Storage
* Lots of front-end work
* Sequencer mechanism