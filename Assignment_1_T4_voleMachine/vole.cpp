#include "vole.h"
#include <bits/fs_fwd.h>
#include <cstddef>
#include <string>
using namespace std;


//helper functions
int fromHexToDec(const string& hex)
{
        int decimalValue = 0;
    int length = hex.length();

    for (int i = 0; i < length; ++i) {
        char hexDigit = hex[length - 1 - i];
        int value;

        if (hexDigit >= '0' && hexDigit <= '9') {
            value = hexDigit - '0';
        } else if (hexDigit >= 'A' && hexDigit <= 'F') {
            value = hexDigit - 'A' + 10;
        } else if (hexDigit >= 'a' && hexDigit <= 'f') {
            value = hexDigit - 'a' + 10;
        } else {
            std::cerr << "Invalid hexadecimal digit: " << hexDigit << std::endl;
            return -1;
        }

        decimalValue += value * std::pow(16, i);
    }

    return decimalValue;
}

string fromHexToBinary(const string& hex)
{
    
}

string fromHexToFloat(const string& hex)
{

}
//class Memory

void Memory::setMemory(const int& address,const string& value)
{
    mainMemory[address]=value;
}

string Memory::getMemory(const int& address)
{
    return mainMemory[address];
}

void Memory::setRegister(const int& address,const string& value)
{
    registers[address]=value;
}

string Memory::getRegister(const int& address)
{
     return registers[address];
}
    
//class CU 

void CU::load(char opCode,string registerAdress,string memoryAddress,Memory& mainMemory)
{
    //mahmoud will write code here.
    int memoryCell = fromHexToDec(memoryAddress);
    int registerCell=fromHexToDec(registerAdress);
    if(opCode=='1')
    {
        string bitPattern=mainMemory.getMemory(memoryCell);
        mainMemory.setRegister(registerCell,bitPattern);
    }else{
        string bitPattern=to_string(memoryCell);
        mainMemory.setRegister(registerCell,bitPattern);
    }
}

void CU::store(string registerAdress,string memoryAddress,Memory& mainMemory)
{
    int memoryCell= fromHexToDec(memoryAddress);
    int registerCell = fromHexToDec(registerAdress);
    string bitPattern=mainMemory.getRegister(registerCell);
    mainMemory.setMemory(memoryCell,bitPattern);
}

void CU::move(string registerAdress , string registerAdress2 , Memory& mainMemory)
{
    //saif omar will write code here.
}

void CU::add(char opCode,string registerAdress,string registerAdress2,string registerAdress3, Memory& mainMemory)
{

    //saif omar will write code here
}

void CU::jump(string registerAdress,string memoryCell,Memory& mainMemory)
{
    //hassan momen will write code here.
}

void CU::halt()
{
    //hassan momen will write code here.
}

//helper functions



//class CPU

void CPU::fetch(Memory& mainMemory)
{
    IR = mainMemory.getMemory(PC)+mainMemory.getMemory(PC+1);
}

void CPU::decode(int& registerAdress,int& memoryCell)
{
     
}


void CPU::execute(Memory& machineMemory)
{

}

//class Machine

void Machine::loadInstruction(const string& instruction,int address)
{
    machineMemory.setMemory(address,instruction);
}

void Machine::process()
{
    processor.fetch(machineMemory);
    processor.execute(machineMemory);
}

void Machine::displayStatus(char choice)
{
    
}

//class UI 

void UI::displayMenu()
{

}

bool UI::getFileOrInstruction()
{

}

bool UI::isValid(const string& input,regex goodInput)
{

}

string UI::inputFileName()
{

}

string UI::inputInstruction()
{

}

char UI::inputChoice()
{

}
