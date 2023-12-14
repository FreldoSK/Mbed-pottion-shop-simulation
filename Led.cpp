#include "Led.h"


void Led::greenLight(bool light) {
    light ? this->green = 1 : this->green = 0;
}

void Led::redLight(bool light) {
    light ? this->red = 1 : this->red = 0;
}



void Led::sleep_ms(const uint16_t& milisec) {
    std::chrono::milliseconds timeInMiliseconds(milisec);
    ThisThread::sleep_for(timeInMiliseconds);
}


void Led::ledPWM(const uint16_t& time) {
    PwmOut pwm(LED1); 

    for (int i = 1; i <= 10; i++) {
        pwm = (float)i / 10;
        sleep_ms(time);
    }

    for (int i = 10; i >= 0; i--) {
        pwm = (float)i / 10;
        sleep_ms(time);
    }
}
Led::~Led() {

}