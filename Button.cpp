#include "Button.h"


void Button::sleep_ms(const uint16_t& milisec) {
    std::chrono::milliseconds timeInMiliseconds(milisec);
    ThisThread::sleep_for(timeInMiliseconds);
}


void Button::buttonInterrupt() {
    Uart uart(USBTX, USBRX);
    uart.initMenu();
}

uint8_t Button::getValue() {
    return this->value;
}