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
    uint8_t capacityOfTable = 3; 
    uint8_t actualCapacityOfTable = 0;
    uint8_t * tableBuffer = (uint8_t*) malloc (sizeof(uint8_t) * capacityOfTable);
    uint8_t * typeCounter = (uint8_t*) malloc (sizeof(uint8_t) * 4);
    uint8_t * epicWeapons = (uint8_t*) malloc (sizeof(uint8_t) * 4);

    uint8_t heroTime = 1 + rand() % 2;
    uint8_t shopTime = 1 + rand() % 1;

    Thread shop_thread;
    Thread heroes_thread[numberOfHeroes];

    std::vector<std::shared_ptr<Hero>> heroes;

    std::shared_ptr<Data> data = std::make_unique<Data>();
    std::shared_ptr<Uart> uart = std::make_shared<Uart>(USBTX, USBRX);
    std::shared_ptr<Table> table = std::make_shared<Table>(tableBuffer, actualCapacityOfTable, capacityOfTable, data);
    std::shared_ptr<Shop> shop = std::make_shared<Shop>(shopTime, numberOfHeroes, uart);
  
    for (int i = 0; i < numberOfHeroes; i++) {
        TypOfHeroe randomHeroType = static_cast<TypOfHeroe>(std::rand() % (ARCHER + 1));
        uint8_t idOfHero = 1 + rand() % numberOfHeroes;
        uint8_t chance = 1 + rand() % 10;

        heroes.push_back(std::make_shared<Hero>(idOfHero, randomHeroType, uart, heroTime, chance, typeCounter, epicWeapons));
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
        break;
    }

    


    
    


    free(tableBuffer);
    free(typeCounter);
    free(epicWeapons);



}