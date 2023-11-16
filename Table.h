#pragma once

#include "mbed.h"
#include <cstdint>
#include <memory>




class Table {
private:
    uint8_t * tableBuffer; 
    uint8_t index;
    uint8_t capacityOfTable;

public:
    Table(uint8_t * tableBuffer, uint8_t capacityOfTable)
    : tableBuffer(tableBuffer), capacityOfTable(capacityOfTable) {}
    uint8_t * getTableBuffer();
    void setTableBuffer(uint8_t * buffer);
    uint8_t getIndex();
    void setIndex(const uint8_t& index);
    uint8_t getCapacityOfTable();
    void setCapacityOfTable(const uint8_t& capacity);
    //void removePotionFromTable(uint8_t& tableBuffer);
    //void addPotionOnTable(uint8_t& tableBuffer);
};
