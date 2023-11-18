#include "GameLogic.h"
#include <cstdint>


Mutex mutex;
ConditionVariable buyPotion(mutex);
ConditionVariable takePotion(mutex);



void GameLogic::sleep_s(const uint8_t& sec) {
    std::chrono::seconds timeInSeconds(sec);
    ThisThread::sleep_for(timeInSeconds);
}


void GameLogic::heroFunction(const std::shared_ptr<Table>& heroTable) {

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
        buyPotion.notify_one();
        mutex.unlock();
        uart->writeMessage("HERO ENDED!");
    }

}

void GameLogic::shopFunction(const std::shared_ptr<Table>& shopTable) {

    for (int i=0; i < shop->getNumberOfHeroes(); i++) {
        sleep_s(shop->getTime());
        uart->writeMessage("SHOP START WORKING!");
        mutex.lock();
        //TODO: Treba urobiť vector hráčov a za každým ako niekto odíde, tak sa odstráni hráč, ktorí išiel preč 
        while (shopTable->getCapacityOfTable() >= 5 && shop->getNumberOfHeroes() > 0) {
            uart->writeMessage("TABLE IS FULL WE WHILL WAIT UNTIL TABPLE WILL BE CLEAN!");
            buyPotion.wait();
        }



        shopTable->setTableBuffer(shopTable->getTableBuffer() + 1);
        uart->writeMessage("FROM TABLE WAS PICKED UP ONE POTION!");
        takePotion.notify_one();
        mutex.unlock();
        uart->writeMessage("SHOP ENDED !");
    }
        

}



