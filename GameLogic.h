#pragma once
#include "mbed.h"
#include "Hero.h"
#include "Shop.h"
#include "Table.h"
#include "Uart.h"
#include <cstdint>
#include <memory>
#include <time.h>

class GameLogic {
private:
    std::shared_ptr<Uart> uart;
    std::shared_ptr<Shop> shop;

    void sleep_s(const uint8_t& sec);

public:
    GameLogic(std::shared_ptr<Uart> uart, std::shared_ptr<Shop> shop) 
    : uart(uart), shop(shop) {}
    void heroFunction(const std::shared_ptr<Table>& heroTable);
    void shopFunction(const std::shared_ptr<Table>& shopTable);
};