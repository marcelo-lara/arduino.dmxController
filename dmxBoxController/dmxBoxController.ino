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
    if(joystick.update()){
        moveHead();
    }
}


void moveHead(){

    //move
    fxHead.X = fxHead.X + (joystick.position.x/8);
    fxHead.Y = fxHead.Y + (joystick.position.y/8);

    printFxHead();
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

void printFxHead(){
    Serial.print("fxHead ch");
    Serial.print(fxHead.dmxCh);
    Serial.print("\t");
    Serial.print(fxHead.X);
    Serial.print("x\t");
    Serial.print(fxHead.Y);
    Serial.println("y");
}
