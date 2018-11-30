
 int VELOCITY_MAX = 0x7f;
 int VELOCITY_OFF = 0x00;

 int MIDI_CHANNEL_OUT = 0x09;

 int KICK_NOTE = 0x09;
 int KICK_2_NOTE = 0x0a;
 int SNARE_NOTE = 0x0b;
 int RIMSHOT_NOTE = 0x0c;
 int CYMBAL_NOTE = 0x0d;
 int OPEN_HAT_NOTE = 0x0e;
 int CLOSED_HAT_NOTE = 0x0f;
 int CLAVE_NOTE = 0x10;
 int HAND_CLAP_NOTE = 0x11;
 int LOW_TOM_NOTE = 0x12;
 int MID_TOM_NOTE = 0x13;
 int HIGH_TOM_NOTE = 0x14;
 int LOW_CONGA_NOTE = 0x15;
 int MID_CONGA_NOTE = 0x16;
 int HIGH_CONGA_NOTE = 0x17;
 int COWBELL_NOTE = 0x18;
 int MARACA_NOTE = 0x19;


 int lastVal = HIGH;

 int inPins[] = {2, 3, 4, 5, 6, 7};
 int lastVals[] = {LOW, LOW, LOW, LOW, LOW, LOW};
 int notes[] = {KICK_NOTE, SNARE_NOTE, CLOSED_HAT_NOTE, OPEN_HAT_NOTE, MID_TOM_NOTE, HAND_CLAP_NOTE};
 
 int NUM_PINS = 6; 
 
void setup() {

  Serial.begin(31250);   // Set MIDI baud rate
  for (int i = 0; i < NUM_PINS; i++)
  {  
     pinMode(inPins[i], INPUT_PULLUP);
  }
  
}


void loop() {

   
   cc(MIDI_CHANNEL_OUT, 67, 100);

    delay(1000);

   cc(MIDI_CHANNEL_OUT, 67, 2);

   delay(1000);
}

// plays a MIDI note. Doesn't check to see that cmd is greater than 127, or that
// data values are less than 127:
void noteOn(int cmd, int pitch, int velocity) {
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}


void cc(int channel, int cc, int val)
{
  noteOn(channel | 0xB0, cc, val);
}


