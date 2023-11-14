#include "Table.h"

uint8_t * Table::getTableBuffer() {
    return this->tableBuffer;
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



