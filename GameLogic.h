#pragma once
#include "mbed.h"
#include "Hero.h"
#include "Shop.h"
#include "Table.h"
#include "Uart.h"
#include <memory>





class GameLogic {
private:
    std::unique_ptr<Uart> uart;
    std::unique_ptr<Hero> hero;
    std::unique_ptr<Shop> shop;



    void heroFunction(std::unique_ptr<Table> heroTable);
    void shopFunction(std::unique_ptr<Table> shopTable);
public:
    void GamePlay();
};