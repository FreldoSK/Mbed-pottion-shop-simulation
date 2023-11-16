#include "GameLogic.h"
#include <string>

Mutex mutex;
ConditionVariable buyPotion(mutex);
ConditionVariable takePotion(mutex);


void GameLogic::heroFunction(std::unique_ptr<Table> heroTable) {

    for (int i=0; i < heroTable->getCapacityOfTable(); i++) {
        ThisThread::sleep_for(2000ms);
        uart->writeMessage("HERO GOES FOR POTION!");
        mutex.lock();
    

        while (heroTable->getCapacityOfTable() <= 0) {
            uart->writeMessage("NOT ENOUGHT POTION WE NEED TO WAIT!");
            takePotion.wait();    
        }

        heroTable->setTableBuffer(heroTable->getTableBuffer() - 1);
        uart->writeMessage("HERO TAKE A POTION!");
        buyPotion.notify_all();
        mutex.unlock();

    }

}

void GameLogic::shopFunction(std::unique_ptr<Table> shopTable) {

    for (int i=0; i < hero->getNumberOfHeroes(); i++) {
        ThisThread::sleep_for(3000ms);
        uart->writeMessage("SHOP START WORKING!");
        mutex.lock();


        while (shopTable->getCapacityOfTable() >= 5) {
            uart->writeMessage("TABLE IS FULL WE WHILL WAIT UNTIL TABPLE WILL BE CLEAN!");
            buyPotion.wait();
        }



        shopTable->setTableBuffer(shopTable->getTableBuffer() + 1);
        uart->writeMessage("FROM TABLE WAS PICKED UP ONE POTION!");
        takePotion.notify_all();
        mutex.unlock();
    }
        

}


void GameLogic::GamePlay() {


}

