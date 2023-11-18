#include "Shop.h"


uint8_t Shop::getTime() {
    return this->time;
}

void Shop::setTime(const uint8_t &time) {
    this->time = time; 
}

unsigned short Shop::getNumberOfHeroes() {
    return this->numberOfHeroes;
}

void Shop::setNumberOfHeroes(const unsigned short& numberOfHeroes) {
    this->numberOfHeroes = numberOfHeroes;
}
