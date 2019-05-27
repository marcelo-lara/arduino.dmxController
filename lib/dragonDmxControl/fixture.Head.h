///////////////////////////////////////
// DMX Channels
//

#define fxHead_Xmsb         0   //XY pos:  Xmsb + Xlsb (16bit)
#define fxHead_Xlsb         1
#define fxHead_Ymsb         2
#define fxHead_Ylsb         3
#define fxHead_XYspeed      4
#define fxHead_Dimmer       5
#define fxHead_Shutter      6
#define fxHead_ColorWheel   7
#define fxHead_GoboWheel    8
#define fxHead_Reset        11

////////////////////////////////////////////
// Fx  /////////////////////////////////////

// Shutter
#define fxHead_Shutter_closed         000
#define fxHead_Shutter_strobe         128
#define fxHead_Shutter_open           255

struct FxHead
{
    byte dmxCh = 1;    //dmx base channel

    short X = 32765;    //16bit (Xmsb + Xlsb)
    short Y = 32765;    //16bit (Ymsb + Ylsb)
    byte Shutter=0;    //closed
    byte Gobo=0;       //open     
    byte Color=0;      //white
    byte Dimmer = 127; //50% ligth
};
