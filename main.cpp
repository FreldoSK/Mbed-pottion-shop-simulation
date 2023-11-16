#include "Hero.h"
#include "Shop.h"
#include <cstdint>
#include <memory>
#include <vector>
#include "Uart.h"




int main() {
    /*
    std::vector<uint8_t> potions;
    std::unique_ptr<Hero> hero = std::make_unique<Hero>(20, 1, TypOfHeroe::KILLER);
    std::unique_ptr<Shop> shop = std::make_unique<Shop>(15, potions);
    
    */

    Uart uart(USBTX, USBRX);


    uart.initMenu();

    uart.readMessage('1');
    


    
   
    

}