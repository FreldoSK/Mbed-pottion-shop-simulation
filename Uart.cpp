#include "Uart.h"
#include <cstdlib>
#include <cstring>
#include <string>

void Uart::readMessage(const char character) {
    while (this->serial_port.read(buffer, MAXIMUM_BUFFER_SIZE)) {
        if (buffer[0] == character) {
            return; 
        }
    }
}

void Uart::clearScreen() {
    const char regex[] = "\e[1;1H\e[2J";
    this->serial_port.write(regex, strlen(regex));
    ThisThread::sleep_for(100ms);
}

void Uart::writeMessage(const char * message) {
    std::string messageWithNewLine = std::string(message) + "\n";
    this->serial_port.write(messageWithNewLine.c_str(), messageWithNewLine.length());
    ThisThread::sleep_for(100ms);
}

void Uart::initMenu() {
    clearScreen();
    writeMessage("*-*-*-*-*- POTION SHOP *-*-*-*-*-");
    writeMessage("CHOSE DIFICULTY :");
    writeMessage("[1] EASY");
    writeMessage("[2] NORMAL");
    writeMessage("[3] HARD");
}
