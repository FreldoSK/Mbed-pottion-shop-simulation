#include "Button.h"
#include <cstdio>



void Button::buttonPressed() {
    this->pressed = true;
}

void Button::buttonReleased() {
    this->pressed = false;
}

bool Button::getSituation() {
    return this->pressed;
}
