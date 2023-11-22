#pragma once

#include "Table.h"
#include "Uart.h"
#include <cstdint>
#include <memory>
#include <cstdint>
#include <string>


enum TypOfHeroe {
    SOLDIER,
    MAGICIAN,
    KILLER,
    ARCHER,
};


class Hero {
private:
    unsigned short id;
    TypOfHeroe typ;
    std::shared_ptr<Uart> uart;
    uint8_t time;
public:
    Hero(const unsigned short& id, const TypOfHeroe& typ, std::shared_ptr<Uart> uart, const uint8_t& time)
    : id(id), typ(typ), uart(uart), time(time) {}
    TypOfHeroe getType();
    void setType(const TypOfHeroe& typ);
    unsigned short getId();
    void setId(const unsigned short& id);
    void heroFunction(const std::shared_ptr<Table>& heroTable);
};


