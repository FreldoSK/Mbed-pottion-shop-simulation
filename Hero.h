#pragma once

#include "Table.h"
#include "Uart.h"
#include <cstdint>
#include <memory>
#include <cstdint>
#include <string>
#include <vector>
#include <string>

enum TypOfHeroe {
    SOLDIER,
    MAGICIAN,
    KILLER,
    ARCHER,
};


class Hero {
private:
    uint8_t id;
    TypOfHeroe typ;
    std::shared_ptr<Uart> uart;
    uint8_t time;

    uint8_t * epicWeaponsCounter;
    uint8_t * typeCounter;
    uint8_t epicChance; 

    std::string enumToString(TypOfHeroe type);
public:
    Hero(const unsigned short& id, const TypOfHeroe& typ, std::shared_ptr<Uart> uart, const uint8_t& time, const uint8_t& epicChance, 
    uint8_t * typeCounter, uint8_t * epicWeaponsCounter)
    : id(id), typ(typ), uart(uart), time(time), epicChance(epicChance), typeCounter(typeCounter), epicWeaponsCounter(epicWeaponsCounter) {}
    TypOfHeroe getType();
    uint8_t getId();
    void setId(const uint8_t& id);
    void heroFunction(const std::shared_ptr<Table>& heroTable);

};


