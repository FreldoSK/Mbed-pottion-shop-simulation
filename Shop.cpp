#include "Shop.h"
#include <string>


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

void Shop::sleep_s(const uint8_t& sec) {
    std::chrono::seconds timeInSeconds(sec);
    ThisThread::sleep_for(timeInSeconds);
}


void Shop::shopFunction(const std::shared_ptr<Table>& shopTable) {

    for (int i=0; i < getNumberOfHeroes(); i++) {
        sleep_s(getTime());
        uart->writeMessage("SHOP START WORKING!");
        shopTable->data.mutex.lock();

        while (shopTable->getCapacityOfTable() <= shopTable->getTableBuffer()) {
            uart->writeMessage("TABLE IS FULL WE WILL WAIT UNTIL TABPLE WILL BE CLEAN!");
            shopTable->data.buyPotion.wait();
        }

        std::string capacity_str = "ACTUAL NUMBER OF POTIONS ON TABLE : " + std::to_string(shopTable->getTableBuffer());
        uart->writeMessage(capacity_str.c_str());


        shopTable->setTableBuffer(shopTable->getTableBuffer() + 1);
        uart->writeMessage("ON TABLE IS ONE MORE POTION!");
        shopTable->data.takePotion.notify_one();
        shopTable->data.mutex.unlock();
        
    }
    uart->writeMessage("SHOP ENDED !");
}