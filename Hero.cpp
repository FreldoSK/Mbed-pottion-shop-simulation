#include "Hero.h"
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>


unsigned short Hero::getId() {
    return this->id;
}

TypOfHeroe Hero::getType() {
    return this->typ;
}


void Hero::setId(const unsigned short& id) {
    this->id = id;
}

void Hero::setType(const TypOfHeroe& typ) {
    this->typ = typ;
}


void Hero::heroFunction(const std::shared_ptr<Table>& heroTable) {
    uint8_t * tableBuffer = heroTable->getTableBuffer();
    std::shared_ptr<Data> data = heroTable->getData();

    heroTable->sleep_s(time);
    std::string hero_id_str = "HERO WITH ID " + std::to_string(getId()) + " GOES FOR POTION!";
    uart->writeMessage(hero_id_str.c_str());

    data->mutex.lock();
    while (heroTable->getIndex() <= 0) {
        uart->writeMessage("NOT ENOUGHT POTIONS WE NEED TO WAIT!");
        data->takePotion.wait();
    }

    tableBuffer[heroTable->getIndex()]--;
    heroTable->setIndex(heroTable->getIndex() - 1);
    heroTable->setActualCapacityOfTable(heroTable->getactualCapacityOfTable() - 1);
    heroTable->setTableBuffer(tableBuffer);

    std::string take_str = "HERO WITH ID " + std::to_string(getId()) + " TAKE A POTION!";
    uart->writeMessage(take_str.c_str());
    data->buyPotion.notify_one();
    data->mutex.unlock();

    std::string hero_ended_str = "HERO WITH ID " + std::to_string(getId()) + " ENDED!";
    uart->writeMessage(hero_ended_str.c_str());
}






