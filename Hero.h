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
    unsigned short numberOfHeroes;
    unsigned short id;
    TypOfHeroe typ;
public:
    Hero(unsigned short numberOfHeroes, unsigned short id, TypOfHeroe typ)
    : numberOfHeroes(numberOfHeroes), id(id), typ(typ) {}
    
    unsigned short getNumberOfHeroes(); 
    void setNumberOfHeroes(unsigned short numberOfHeroes);
    TypOfHeroe getType();
    void setType(TypOfHeroe typ);
    unsigned short getId();
    void setId(unsigned short id);

};


