#include "Hero.h"


uint8_t Hero::getId() {
    return this->id;
}

TypOfHeroe Hero::getType() {
    return this->typ;
}

void Hero::setId(const uint8_t& id) {
    this->id = id;
}


std::string Hero::enumToString(TypOfHeroe type) {

    switch (type) {
        case TypOfHeroe::ARCHER:
        return "ARCHER";

        case TypOfHeroe::KILLER:
        return "KILLER";

        case TypOfHeroe::MAGICIAN:
        return "MAGICIAN";

        default:
        return "SOLDIER";

    }

}

void Hero::heroFunction(const std::shared_ptr<Table>& heroTable) {
    uint8_t * tableBuffer = heroTable->getTableBuffer();
    std::shared_ptr<Data> data = heroTable->getData();
    heroTable->sleep_s(time);
    std::string enumToString = this->enumToString(this->getType());
    std::string hero_id_str = " ";

    switch (this->getType()) {
        case TypOfHeroe::ARCHER:
            this->typeCounter[0]++;
            break; 

        case TypOfHeroe::KILLER:
            this->typeCounter[1]++;
            break; 

        case TypOfHeroe::MAGICIAN:
            this->typeCounter[2]++;
            break; 

        default:
            this->typeCounter[3]++;
            break;  
    }
    

    hero_id_str = "hero with ID " + std::to_string(getId()) + " have class " + enumToString + " ! ";
    uart->writeMessage(hero_id_str.c_str());


    hero_id_str = "Hero with id " + std::to_string(this->getId()) + " and class " + enumToString + " goes for potion!";
    uart->writeMessage(hero_id_str.c_str());

    data->mutex.lock();
    while (heroTable->getIndex() <= 0) {
        uart->writeMessage("Not enought potions we will wait!");
        data->takePotion.wait();
    }

    tableBuffer[heroTable->getIndex()]--;
    heroTable->setIndex(heroTable->getIndex() - 1);
    heroTable->setActualCapacityOfTable(heroTable->getactualCapacityOfTable() - 1);
    heroTable->setTableBuffer(tableBuffer);

    std::string take_str = "Hero with ID " + std::to_string(getId()) + " take potion!";
    uart->writeMessage(take_str.c_str());
    data->buyPotion.notify_one();
    data->mutex.unlock();


    hero_id_str = "Hero with id " + std::to_string(this->getId()) + " and class " + enumToString + " goes to adventure !";
    uart->writeMessage(hero_id_str.c_str());

    
    if (this->typ == TypOfHeroe::ARCHER && this->epicChance <= 2) {
        hero_id_str = "Hero with id " + std::to_string(this->getId()) + " and class " + enumToString + " gets Epic Weapon !";
        uart->writeMessage(hero_id_str.c_str());
        this->epicWeaponsCounter[0]++;
    } 

    if (this->typ == TypOfHeroe::KILLER && this->epicChance <= 5) {
        hero_id_str = "Hero with id " + std::to_string(this->getId()) + " and class " + enumToString + " gets Epic Weapon !";
        uart->writeMessage(hero_id_str.c_str());
        this->epicWeaponsCounter[1]++;
    }

    if (this->typ == TypOfHeroe::MAGICIAN && this->epicChance <= 9) {
        hero_id_str = "Hero with id " + std::to_string(this->getId()) + " and class " + enumToString + " gets Epic Weapon !";
        uart->writeMessage(hero_id_str.c_str());
        this->epicWeaponsCounter[2]++;
    }

    if (this->typ == TypOfHeroe::SOLDIER && this->epicChance == 10) {
        hero_id_str = "Hero with id " + std::to_string(this->getId()) + " and class " + enumToString + " gets Epic Weapon !";
        uart->writeMessage(hero_id_str.c_str());
        this->epicWeaponsCounter[3]++;
    }

    std::string hero_ended_str = "Hero with ID " + std::to_string(getId()) + " ended!";
    uart->writeMessage(hero_ended_str.c_str());
}






