#pragma once

#include "Table.h"

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
public:
    Hero(const unsigned short& id, const TypOfHeroe& typ)
    : id(id), typ(typ) {}
    
    TypOfHeroe getType();
    void setType(TypOfHeroe typ);
    unsigned short getId();
    void setId(unsigned short id);

};


