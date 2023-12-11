#include "Button.h"




void Button::buttonPressed() {
    this->pressed = true;
}

void Button::buttonReleased() {
    this->pressed = false;
}

bool Button::getSituation() {
    return this->pressed;
}
