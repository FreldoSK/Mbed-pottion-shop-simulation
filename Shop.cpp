#include "Shop.h"
#include <cstdint>
#include <string>



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
    uint8_t * tableBuffer = shopTable->getTableBuffer();
    uart->writeMessage("SHOP START WORKING!");

    for (int i=0; i < this->numberOfHeroes; i++) {
        shopTable->sleep_s(time);
        shopTable->data.mutex.lock();

        while (shopTable->getCapacityOfTable() <= shopTable->getactualCapacityOfTable()) {
            uart->writeMessage("TABLE IS FULL WE WILL WAIT UNTIL TABPLE WILL BE CLEAN!");
            shopTable->data.buyPotion.wait();
        }

        tableBuffer[shopTable->getIndex()]++;
        shopTable->setIndex(shopTable->getIndex() + 1);
        shopTable->setActualCapacityOfTable(shopTable->getactualCapacityOfTable() + 1);
        shopTable->setTableBuffer(tableBuffer);

        uart->writeMessage("ON TABLE IS ONE MORE POTION!");
        shopTable->data.takePotion.notify_one();
        shopTable->data.mutex.unlock();
        
    }
    uart->writeMessage("SHOP ENDED!");


}