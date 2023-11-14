#include "Hero.h"


unsigned short Hero::getId() {
    return this->id;
}

TypOfHeroe Hero::getType() {
    return this->typ;
}

unsigned short Hero::getNumberOfHeroes() {
    return this->numberOfHeroes;
}

void Hero::setId(unsigned short id) {
    this->id = id;
}

void Hero::setType(TypOfHeroe typ) {
    this->typ = typ;
}

void Hero::setNumberOfHeroes(unsigned short numberOfHeroes) {
    this->numberOfHeroes = numberOfHeroes;
}






