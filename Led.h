#pragma once 
#include "mbed.h"
#include "Table.h"
#include <string>
#include <cstring>
#include <chrono>
#include <cstdint>
#include <stdexcept>


class Led {
private:
DigitalOut red; 
DigitalOut green;



public:
Led(const PinName &greenPin, const PinName &redPin) : 
    red(redPin), green(greenPin)  {}

~Led();

void greenLight(bool light);
void redLight(bool light);
void ledPWM(const uint16_t& time);
void sleep_ms(const uint16_t& sec);
};