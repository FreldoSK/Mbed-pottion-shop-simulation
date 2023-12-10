#include "Uart.h"

uint8_t Uart::getCounter() {
    return this->counter;
}

void Uart::setCounter(const uint8_t counter) {
    this->counter = counter;
}

void Uart::readMessage() {
    while (this->serial_port.read(buffer, MAXIMUM_BUFFER_SIZE)) {
        const char character = buffer[0];
        
        if (std::isalpha(character)) {

            if (character == 'y') {
                this->setChar('y');
                writeMessage("y");
                return;
            }

            if (character == 'n') {
                this->setChar('n');
                writeMessage("n");
                return;
            }  else {
                writeMessage("ERROR : BAD INPUT ! try it again !");
                this->setChar(' ');
                readMessage();
            }
        }

        if (std::isdigit(character)) {
            switch (character) {
            case '0':
                this->setCounter(0);
                writeMessage("0");
                return;
            case '1':
                this->setCounter(1);
                writeMessage("1");
                return;
            case '2':
                this->setCounter(2);
                writeMessage("2");
                return;
            case '3':
                this->setCounter(3);
                writeMessage("3");
                return;
            case '4':
                this->setCounter(4);
                writeMessage("4");
                return;
            case '5':
                this->setCounter(5);
                writeMessage("5");
                return;
            case '6':
                this->setCounter(6);
                writeMessage("6");
                return;
            case '7':
                this->setCounter(7);
                writeMessage("7");
                return;                                                
            case '8':
                this->setCounter(8);
                writeMessage("8");
                return;
            case '9':
                this->setCounter(9);
                writeMessage("9");
                return;
            default:
                writeMessage("ERROR, TRY AGAIN !!!");
                readMessage();    
            }
        } else {
            writeMessage("BAD INPUT ! TRY AGAIN!!!");
            readMessage();
        }
    }
}

void Uart::setChar(const char character) {
    this->character = character;
}

char Uart::getChar() {
    return this->character;
}

void Uart::clearScreen() {
    const char regex[] = "\e[1;1H\e[2J";
    this->serial_port.write(regex, strlen(regex));
    ThisThread::sleep_for(100ms);
}

void Uart::writeMessage(const char * message) {
    std::string messageWithNewLine = std::string(message) + "\n";
    this->serial_port.write(messageWithNewLine.c_str(), messageWithNewLine.length());
    ThisThread::sleep_for(100ms);
}


void Uart::printResult(uint8_t * classArray, uint8_t * epicArray) {
    writeMessage("\n\n-*-*-*-*-*-*-*|STATS|-*-*-*-*-*-*-*");
    std::string numOfArch = "Number of Archers was " + std::to_string(classArray[0]);
    writeMessage(numOfArch.c_str());
    std::string numOfKill = "Number of Killers was " + std::to_string(classArray[1]);
    writeMessage(numOfKill.c_str());
    std::string numOfMag = "Number of Magicians was " + std::to_string(classArray[2]);
    writeMessage(numOfMag.c_str());
    std::string numOfSol = "Number of Soldiers was " + std::to_string(classArray[3]);
    writeMessage(numOfSol.c_str());
    writeMessage("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    writeMessage("\n\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    std::string epicArcher = "Archers get " + std::to_string(epicArray[0]) + " epic weapons !";
    writeMessage(epicArcher.c_str());
    std::string epicKiller = "Killers get " + std::to_string(epicArray[1]) + " epic weapons !";
    writeMessage(epicKiller.c_str());
    std::string epicMagician = "Magicians get " + std::to_string(epicArray[2]) + " epic weapons !";
    writeMessage(epicMagician.c_str());
    std::string epicSoldiers = "Soldiers get " + std::to_string(epicArray[3]) + " epic weapons !";
    writeMessage(epicSoldiers.c_str());
    writeMessage("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
}