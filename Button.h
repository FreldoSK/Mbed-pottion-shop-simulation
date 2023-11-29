#pragma once
#include "mbed.h"
#include <cstdint>
#include <memory>


class Button {
private:
    InterruptIn buttonCenter;
    uint8_t value;

    void sleep_ms(const uint16_t& milisec);    


public:
    Button() : 
    buttonCenter(BUTTON1),  value(0) {
        buttonCenter.fall(callback(this, &Button::buttonInterrupt));
    }

    void buttonInterrupt();
    uint8_t getValue();
};