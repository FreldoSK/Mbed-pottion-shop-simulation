#pragma once

#include "Table.h"
#include "Uart.h"
#include <memory>

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
public:
    Hero(const unsigned short& id, const TypOfHeroe& typ, std::shared_ptr<Uart> uart)
    : id(id), typ(typ), uart(uart) {}
    
    TypOfHeroe getType();
    void setType(TypOfHeroe typ);
    unsigned short getId();
    void setId(unsigned short id);
    void heroFunction(const std::shared_ptr<Table>& heroTable);
};


