#pragma once
/////////////////////////////////////
// Dragon DMX control library
#include <RF24.h>
#include "rfDmxPacket.h"

#ifndef dragonDmxControl_h
#define dragonDmxControl_h

class dragonDmxControl
{
  public:
    dragonDmxControl(RF24 &_radio);
    void  setup();
    void  rfSend(RfDmxPacket *dmxPacket);
  	bool  radio_status;

  private:
  	RF24* radio;
};
#endif
