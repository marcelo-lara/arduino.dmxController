/////////////////////////////////////
// Dragon DMX control library
#include <RF24.h>

#ifndef dragonDmxControl_h
#define dragonDmxControl_h

class dragonDmxControl
{
  public:
    dragonDmxControl();
    void    setup(RF24 &_radio);


  private:
};

extern dragonDmxControl Dmx;

#endif
