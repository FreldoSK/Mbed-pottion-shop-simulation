#include "Joystick.h"


void Joystick::joyPressed(std::shared_ptr<Uart>& uart) {

    while(true) {
        if (this->joyUp.read()) {
        this->counter++;

        if (this->counter > 9) {
            this->counter = 9;
        }
            uart->writeMessage(std::to_string(this->counter).c_str());
            ThisThread::sleep_for(200ms);
        }

        if (this->joyDown.read()) {
            this->counter--;
            uart->writeMessage(std::to_string(this->counter).c_str());
            ThisThread::sleep_for(200ms);     
        }
        
        if (this->joyRight.read()) {
            if (this->counter != 0) {
                this->skiped = true;
                ThisThread::sleep_for(200ms);
                return;  
            } else {
                uart->writeMessage("BAD INPUT !");
                joyPressed(uart);
            }
        }
    }
}
void Joystick::yesOrNo(std::shared_ptr<Uart>& uart) {
    while (true) {
        if (this->joyRight.read()) {
            this->response = 1;
            ThisThread::sleep_for(200ms);
            return; 
        }

        if (this->joyLeft.read()) {
            this->response = 2;
            ThisThread::sleep_for(200ms);
            return; 
        }
    }
}



uint16_t Joystick::getCounter() {
    return this->counter;
}

void Joystick::setCounter(const uint16_t& counter) {
    this->counter = counter;
}

bool Joystick::getSkiped() {
    return this->skiped;
}

uint8_t Joystick::getResponse() {
    return this->response;
}

void Joystick::setResponse(const uint8_t& response) {
    this->response = response;
}