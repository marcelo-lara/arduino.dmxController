#include "dmxBoxController.h"
#include <fixture.Head.h>
//joystick controller
#include <Joystick.h>
Joystick joystick;
FxHead fxHead;

void setup(){
    Serial.begin(115200);
    joystick.calibrate();
}

void loop(){
    if(joystick.update(false)) moveHead();
    delay(10);
}

void moveHead(){
    //ignore center
    if( joystick.position.x<10 && joystick.position.x>-10 &&
        joystick.position.y<10 && joystick.position.y>-10) return;

    //calc
    long newX=fxHead.X+((long)joystick.position.x/8L);
    long newY=fxHead.Y+((long)joystick.position.y/8L);

    //fix boundaries
    if(newX<0) newX=0;
    if(newY<0) newY=0;
    if(newX>0xFFFF) newX=0xFFFF;
    if(newY>0xFFFF) newY=0xFFFF;

    //send only on move
    if(newX==fxHead.X && newY==fxHead.Y) return;

    //move
    fxHead.X = newX;
    fxHead.Y = newY;
}



int lastPos;
void printDigitalJoy(){
    int joypos = joystick.digitalPosition();
    if(lastPos==joypos) return;
    lastPos=joypos;

    switch (joypos)
    {
        case joystick_pos_center   : Serial.println("joystick_pos_center"); break;
        case joystick_pos_up       : Serial.println("joystick_pos_up"); break;
        case joystick_pos_down     : Serial.println("joystick_pos_down"); break;
        case joystick_pos_left     : Serial.println("joystick_pos_left"); break;
        case joystick_pos_right    : Serial.println("joystick_pos_right"); break;
        case joystick_pos_upleft   : Serial.println("joystick_pos_upleft"); break;
        case joystick_pos_upright  : Serial.println("joystick_pos_upright"); break;
        case joystick_pos_downleft : Serial.println("joystick_pos_downleft"); break;
        case joystick_pos_downright: Serial.println("joystick_pos_downright"); break;
        default: Serial.println("joystick_pos unknown!!");break;
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// debug
void printJoystick(){
    Serial.print("joy ");
    Serial.print(joystick.position.x);
    Serial.print("x\t");
    Serial.print(joystick.position.y);
    Serial.print("y |\t");

}

void printFxHead(){
    Serial.print("fxHead ch");
    Serial.print(fxHead.dmxCh);
    Serial.print("\t");
    Serial.print(fxHead.X,HEX);
    Serial.print("x\t");
    Serial.print(fxHead.Y,HEX);
    Serial.println("y");
}
