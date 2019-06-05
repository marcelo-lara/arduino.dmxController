#include "Arduino.h"
#include <avr/interrupt.h>
#include "dragonDmxControl.h"
#include <RF24.h>       
#include <printf.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <avr/wdt.h>        //watchdog

//RF settings
#define rfChannel   0x5B
#define rfPipeBox   0xD0
#define rfPipeSlave 0xD1

//constructor
dragonDmxControl::dragonDmxControl(RF24& _radio){
  radio = &_radio;
};

//setup
void dragonDmxControl::setup(){
	printf_begin();
  radio->begin();
  radio->setChannel(rfChannel);
	radio->setPALevel(RF24_PA_HIGH); //RF24_PA_HIGH | RF24_PA_LOW | RF24_PA_MAX
  radio->setAutoAck(false);
  radio->setDataRate(RF24_250KBPS);
  radio->openWritingPipe(rfPipeBox);
  radio->openReadingPipe(1,rfPipeSlave);
  radio_status = (rfChannel == radio->getChannel()); //test if radio is enabled

};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RF stuff
void dragonDmxControl::rfSend(RfDmxPacket *dmxPacket){
  memset(dmxPacket, 0, sizeof(RfDmxPacket));
  radio->write(&dmxPacket, sizeof(RfDmxPacket));
}