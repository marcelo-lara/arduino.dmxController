#pragma once
struct RfDmxPacket
{
    byte command;
    byte dmxData[24];
};

// render
#define RfDmxPacket_render  0
// deliver dmx output
