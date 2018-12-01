# triggercut
Arduino-based gate to MIDI converter for Eurorack and similar.

I've been using this sketch for some time in a custom box. I put an Arduino Uno in a project box and mounted 12 1/8" jacks on the top, wiring the grounds of the jacks to the Uno's ground through a 220 Ohm resistor. There's also a MIDI output, wired up simply. Every time a trigger or gate arrives at one of the inputs, a MIDI note is sent out, and a note off is sent when the line goes low. 

I use this device to convert Eurorack gates and/or triggers to MIDI destined for an MFB Tanzbär. This sketch sends note on/off messages for the twelve most interesting voices on the Tanzbär. 
