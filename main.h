#include <algorithm>
#include <cstdlib>
#include <cstdint>
#include <cstdlib>
#include <memory>
#include <string>
#include <vector>
#include "mbed.h"
#include "Table.h"
#include "Uart.h"
#include "Shop.h"
#include "Hero.h"
#include "Led.h"


struct Details {
    unsigned short numberOfHeroes;  
    uint8_t capacityOfTable; 
    uint8_t heroTime;
    uint8_t shopTime;
};

void initStart(std::shared_ptr<Uart>& uart, const std::shared_ptr<Details>& details);
void gamePlay(std::shared_ptr<Uart>& uart, const std::shared_ptr<Details>& details);

