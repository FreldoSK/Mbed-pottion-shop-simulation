#pragma once

#include "Table.h"
#include <vector>
#include <memory>


class Shop {
private:
uint8_t time;
unsigned short numberOfHeroes; 

public:
Shop(const uint8_t& time, const unsigned short& numberOfHeroes)
: time(time), numberOfHeroes(numberOfHeroes)  {}
uint8_t getTime();
void setTime(const uint8_t& time);
unsigned short getNumberOfHeroes();
void setNumberOfHeroes(const unsigned short& numberOfHeroes);
};