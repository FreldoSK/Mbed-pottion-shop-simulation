#include "Table.h"
#include <cstdint>



uint8_t * Table::getTableBuffer() {
    return this->tableBuffer;
}

void Table::setTableBuffer(const uint8_t * tableBuffer) {
    this->tableBuffer = const_cast<uint8_t*>(tableBuffer);
}


uint8_t Table::getactualCapacityOfTable() {
    return this->actualCapatcityOfTable;
}

void Table::setActualCapacityOfTable(const uint8_t& actualCapatcityOfTable) {
    this->actualCapatcityOfTable = actualCapatcityOfTable;
}

uint8_t Table::getIndex() {
    return this->index;
}

void Table::setIndex(const uint8_t& index) {
    this->index = index;
}

uint8_t Table::getCapacityOfTable() {
    return this->capacityOfTable;
}

void Table::setCapacityOfTable(const uint8_t& capacity) {
    this->capacityOfTable = capacity;
}

void Table::sleep_s(const uint8_t& sec) {
    std::chrono::seconds timeInSeconds(sec);
    ThisThread::sleep_for(timeInSeconds);
}



