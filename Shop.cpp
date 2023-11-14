#include "Shop.h"


uint8_t Shop::getTime() {
    return this->time;
}

std::vector<uint8_t> Shop::getPotions() {
    return this->potions;
}

void Shop::setTime(const uint8_t& time) {
    this->time = time;
}

void Shop::addPotionToTable(std::unique_ptr<Table>& table) {
        
}