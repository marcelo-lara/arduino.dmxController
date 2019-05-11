/////////////////////////////////////////////////
// DMX slave
//
#include "dmxSlave.h"

//rf module
#include <RF24.h>
#define rf_ce     9
#define rf_csn    8
RF24 radio(rf_ce, rf_csn);

//relays
#define io_data   5
#define io_latch  6
#define io_clk    7

//dmx
#include <dragonDmxControl.h>
#define dmx_mode  2 

//status led
#define status    3

void setup() { 
    Serial.begin(250000);
    Dmx.setup();

}
void loop() {

}