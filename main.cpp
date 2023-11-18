#include <algorithm>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include "mbed.h"
#include "Table.h"
#include "Uart.h"
#include "Shop.h"
#include "Hero.h"


int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    unsigned short numberOfHeroes = 15;  
    uint8_t tableBuffer = 0;
    uint8_t capacityOfTable = 3; 

    Thread shop_thread;
    Thread heroes_thread[10];

    std::vector<std::shared_ptr<Hero>> heroes;

    std::shared_ptr<Uart> uart = std::make_shared<Uart>(USBTX, USBRX);
    std::shared_ptr<Table> table = std::make_shared<Table>(tableBuffer, capacityOfTable);
    std::shared_ptr<Shop> shop = std::make_shared<Shop>(2, numberOfHeroes, uart);
  
    for (int i = 0; i < numberOfHeroes; i++) {
        TypOfHeroe randomHeroType = static_cast<TypOfHeroe>(std::rand() % (ARCHER + 1));
        uint8_t idOfHero = 1 + rand() % 10;
        heroes.push_back(std::make_shared<Hero>(idOfHero, randomHeroType, uart));
    }

    shop_thread.start([&]() {
        shop->shopFunction(table);
    });

    for (int i=0; i < numberOfHeroes; i++) {
        heroes[i]->heroFunction(table);
    };

    shop_thread.join();

    for (int i=0; i < numberOfHeroes; i++) {
        heroes_thread[i].join();
    }
    



    




    


}