#pragma once

#include "mbed.h"
#include <cstdint>
#include <memory>




struct Data {
    Mutex mutex;
    ConditionVariable buyPotion;
    ConditionVariable takePotion;

    Data() : buyPotion(mutex), takePotion(mutex) {}
};


class Table {
private:
    std::shared_ptr<Data> data;
    uint8_t * tableBuffer; 
    uint8_t actualCapatcityOfTable; 
    uint8_t index;
    uint8_t capacityOfTable;

public:
    Table(uint8_t * tableBuffer, uint8_t actualCapatcityOfTable, uint8_t index, uint8_t capacityOfTable, std::shared_ptr<Data> data)
    : tableBuffer(tableBuffer), actualCapatcityOfTable(actualCapatcityOfTable), index(index), capacityOfTable(capacityOfTable), data(data) {}
    uint8_t * getTableBuffer();
    void setTableBuffer(const uint8_t * tableBuffer);
    uint8_t getactualCapacityOfTable();
    void setActualCapacityOfTable(const uint8_t& actualCapatcityOfTable);
    uint8_t getIndex();
    void setIndex(const uint8_t& index);
    uint8_t getCapacityOfTable();
    void setCapacityOfTable(const uint8_t& capacity);
    std::shared_ptr<Data> getData();

    void sleep_s(const uint8_t& sec);
};
