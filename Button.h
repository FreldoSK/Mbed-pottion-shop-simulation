#pragma once
#include "mbed.h"



class Button {
private:
    InterruptIn buttonCenter;
    bool pressed;  
public:
    Button() : buttonCenter(BUTTON1), pressed(false) {
        buttonCenter.rise(callback(this, &Button::buttonPressed));
        buttonCenter.fall(callback(this, &Button::buttonReleased));
    }
    void buttonPressed();
    void buttonReleased();
    bool getSituation();
    
};