#pragma once
#include "mbed.h"
#include <cstdint>
#include <cstring>

#define MAXIMUM_BUFFER_SIZE  32

class Uart {
private:
    char buffer[MAXIMUM_BUFFER_SIZE];
    BufferedSerial serial_port;

public:
    Uart(PinName tx, PinName rx, uint16_t bound = 9600) : serial_port(tx, rx) {
        serial_port.set_baud(bound);
        serial_port.set_format(8, BufferedSerial::None, 1);
    }

    void printResult(uint8_t * array, uint8_t * epicArray);
    void initMenu();
    void readMessage(const char character);
    void writeMessage(const char * message);
    void clearScreen();
};

