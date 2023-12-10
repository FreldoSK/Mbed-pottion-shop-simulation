#include "Shop.h"


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
    std::shared_ptr<Data> data = shopTable->getData();
    uart->writeMessage("SHOP START WORKING!");

    for (int i=0; i < this->numberOfHeroes; i++) {
        shopTable->sleep_s(time);
        data->mutex.lock();

        while (shopTable->getCapacityOfTable() <= shopTable->getactualCapacityOfTable()) {
            uart->writeMessage("TABLE IS FULL WE WILL WAIT UNTIL TABPLE WILL BE CLEAN!");
            data->buyPotion.wait();
        }

        tableBuffer[shopTable->getIndex()]++;
        shopTable->setIndex(shopTable->getIndex() + 1);
        shopTable->setActualCapacityOfTable(shopTable->getactualCapacityOfTable() + 1);
        shopTable->setTableBuffer(tableBuffer);

        uart->writeMessage("ON TABLE IS ONE MORE POTION!");
        data->takePotion.notify_one();
        data->mutex.unlock();
        
    }

    uart->writeMessage("SHOP STOPED PRODUCTION OF POTIONS!!!");
    data->ended = true;
}