#include "Hero.h"
#include <cstdint>
#include <cstdlib>
#include <string>


unsigned short Hero::getId() {
    return this->id;
}

TypOfHeroe Hero::getType() {
    return this->typ;
}


void Hero::setId(unsigned short id) {
    this->id = id;
}

void Hero::setType(TypOfHeroe typ) {
    this->typ = typ;
}


void Hero::heroFunction(const std::shared_ptr<Table>& heroTable) {
    uint8_t * tableBuffer = heroTable->getTableBuffer();
    heroTable->sleep_s(time);
    std::string hero_id_str = "HERO WITH ID " + std::to_string(getId()) + " GOES FOR POTION!";
    uart->writeMessage(hero_id_str.c_str());

    heroTable->data.mutex.lock();
    while (heroTable->getIndex() <= 0) {
        uart->writeMessage("NOT ENOUGHT POTIONS WE NEED TO WAIT!");
        heroTable->data.takePotion.wait();
    }

    tableBuffer[heroTable->getIndex()]--;
    heroTable->setIndex(heroTable->getIndex() - 1);
    heroTable->setActualCapacityOfTable(heroTable->getactualCapacityOfTable() - 1);
    heroTable->setTableBuffer(tableBuffer);

    std::string take_str = "HERO WITH ID " + std::to_string(getId()) + " TAKE A POTION!";
    uart->writeMessage(take_str.c_str());
    heroTable->data.buyPotion.notify_one();
    heroTable->data.mutex.unlock();

    std::string hero_ended_str = "HERO WITH ID " + std::to_string(getId()) + " ENDED!";
    uart->writeMessage(hero_ended_str.c_str());
}






