#include <algorithm>
#include <memory>
#include <type_traits>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>
#include "mbed.h"
#include "Table.h"
#include "Uart.h"
#include "Shop.h"
#include "Hero.h"
#include "Led.h"
#include "Joystick.h"

#define NUM_OF_CLASSES 4

struct Details {
    uint8_t numberOfHeroes;  
    uint8_t capacityOfTable; 
    uint8_t heroTime;
    uint8_t shopTime;
    bool joystick;
};



void initStartBoard(std::shared_ptr<Uart>& uart, const std::unique_ptr<Joystick>& joystick, const std::shared_ptr<Details>& details);
void initStartJoy(std::shared_ptr<Uart>& uart, const std::shared_ptr<Details>& details, const std::unique_ptr<Joystick>& joystick);
void boardOrJoy(std::shared_ptr<Uart>& uart, const std::unique_ptr<Joystick>& joystick, const std::shared_ptr<Details>& details);

void gamePlay(std::shared_ptr<Uart>& uart, const std::unique_ptr<Joystick>& joystick, const std::shared_ptr<Details>& details);

