#pragma once

#include "Table.h"
#include <vector>
#include <memory>


class Shop {
private:
uint8_t time;
std::vector<uint8_t> potions;

public:
Shop(uint8_t time, std::vector<uint8_t>& potions)
: time(time), potions(potions) {}
uint8_t getTime();
std::vector<uint8_t> getPotions();
void setTime(const uint8_t& time);
void removePotionFromTable(std::unique_ptr<Table>& table);
void addPotionToTable(std::unique_ptr<Table>& table);

};