# DragonBox DMX Controller

---
## Background context
Inside a room with 'hidden' light effects, there is a box with celtic dragons inscriptions. When you open it, the 'dungeon scene' is played and you can control lighting and effects with the box.

## Technical reference
- One server, many addressable slaves.
- RF transport with nrf24l01. RF24 Library https://github.com/nRF24/RF24
- DMX protocol forked from https://github.com/mathertel/DMXSerial | Copyright (c) 2005-2015 by Matthias Hertel, http://www.mathertel.de

---
### DMX Box controller (dmxServer)
- AtMega328P Controller + nrf24l01P
- Analog joystic
- Buttons to control scenes/chases/blackout

### DMX slave
- AtMega328P Controller + nrf24l01P on shielded box
- Led indicators for Pwr / Status / Dmx tx
- Lights power on/off with SSR controlled by 74HC595 shiftout register
- DMX cascaded network

### dragon DMX library
Common library 
