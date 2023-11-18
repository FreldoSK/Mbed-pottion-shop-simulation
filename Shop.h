#pragma once

#include "Table.h"
#include "Uart.h"
#include <memory>


class Shop {
private:
uint8_t time;
unsigned short numberOfHeroes; 
std::shared_ptr<Uart> uart;
void sleep_s(const uint8_t& sec);


public:
Shop(const uint8_t& time, const unsigned short& numberOfHeroes, std::shared_ptr<Uart> uart)
: time(time), numberOfHeroes(numberOfHeroes), uart(uart)  {}
uint8_t getTime();
void setTime(const uint8_t& time);
unsigned short getNumberOfHeroes();
void setNumberOfHeroes(const unsigned short& numberOfHeroes);
void shopFunction(const std::shared_ptr<Table>& shopTable);
};