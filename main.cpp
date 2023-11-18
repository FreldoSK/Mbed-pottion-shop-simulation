#include "GameLogic.h"
#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include "mbed.h"


        /*
        std::string heroType = "Hero type " + std::to_string(heroes[i]->getType());
        std::string idHero = "Hero id " + std::to_string(heroes[i]->getId());
        uart.writeMessage(heroType.c_str());
        uart.writeMessage(idHero.c_str());
        uart.writeMessage("\n");

        */



int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    unsigned short numberOfHeroes = 10;  
    uint8_t tableBuffer = 0;
    uint8_t capacityOfTable = 5; 
     
    Thread shop_thread;
    Thread heroes_thread[10];

    std::vector<std::shared_ptr<Hero>> heroes;

    std::shared_ptr<Uart> uart = std::make_shared<Uart>(USBTX, USBRX);
    std::shared_ptr<Table> table = std::make_shared<Table>(tableBuffer, capacityOfTable);
    std::shared_ptr<Shop> shop = std::make_shared<Shop>(2, numberOfHeroes);
    std::shared_ptr<GameLogic> gameLogic = std::make_shared<GameLogic>(uart, shop);

    for (int i = 0; i < numberOfHeroes; i++) {
        TypOfHeroe randomHeroType = static_cast<TypOfHeroe>(std::rand() % (ARCHER + 1));
        uint8_t idOfHero = 1 + rand() % 10;
        heroes.push_back(std::make_shared<Hero>(idOfHero, randomHeroType));
    }


    shop_thread.start([&]() {
        gameLogic->shopFunction(table);
    });

    for (int i=0; i < numberOfHeroes; i++) {
        heroes_thread[i].start([&]() {
        gameLogic->heroFunction(table);
    });

    }

    shop_thread.join();

    for (int i=0; i < numberOfHeroes; i++) {
        heroes_thread[i].join();
    }
    



    




    


}