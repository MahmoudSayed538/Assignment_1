#include "vole.h"
#include <string>
using namespace std;

//class Memory

void Memory::setMemory(const int& address,const string& value)
{
    mainMemory.at(address)=value[0]+value[1];
    mainMemory.at(address+1)=value[2]+value[3];
}

string Memory::getMemory(const int& address)
{
    return mainMemory.at(address)+mainMemory.at(address+1);
}

void Memory::setRegister(const int& address,const string& value)
{
     registers.at(address)=value;
}

string Memory::getRegister(const int& address)
{
     return registers.at(address);
}

void CU::load(const string& instruction, Memory& mainMemory)
{

}

//class CU

void CU::store(const string& instruction, Memory& mainMemory)
{

}

void CU::move(const string& instruction, Memory& mainMemory)
{

}

void CU::add(const string& instruction, Memory& mainMemory)
{

}

void CU::jump(const string& instruction, Memory& mainMemory)
{

}

void CU::halt(const string& instruction, Memory& mainMemory)
{

}

//class CPU

void CPU::fetch(Memory& mainMemory)
{
    IR = mainMemory.getMemory(PC);
}

void CPU::decode()
{
    char opCode=IR[0];
    switch (opCode){
        case '1':
            cout<<"";
            break;
        case '2':
            cout<<"";
            break;
        case '3':
            cout<<"";
            break;
        case '4':
            cout<<"";
            break;
        case '5':
            cout<<"";
            break;
        case '6':
            cout<<"";
            break;
        case 'B':
            cout<<"";
            break;
        case 'C':
            cout<<"";
            break;

    }
        
     
}

void CPU::execute()
{

}

//class Machine

void Machine::loadInstruction(const string& instruction)
{

}

void Machine::process()
{

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
