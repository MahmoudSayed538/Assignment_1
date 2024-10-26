#include "vole.h"
#include <bits/fs_fwd.h>
#include <cstddef>
#include <string>
using namespace std;

//class Memory

void Memory::setMemory(const int& address,const string& value)
{
    mainMemory[address][0]=value[0]+value[1];
    mainMemory[address][1]=value[2]+value[3];
}

string Memory::getMemory(const int& address)
{
    return mainMemory[address][0]+mainMemory[address][1];
}

void Memory::setRegister(const int& address,const string& value)
{
     registers.at(address)=value[0]+value[1];
     registers.at(address+1)=value[2]+value[3];
}

string Memory::getRegister(const int& address)
{
     return registers.at(address)+registers.at(address+1);
}

//class CU 

void CU::load(char opCode,int registerAdress,int memoryCell,Memory& mainMemory)
{
    //mahmoud will write code here.
}

void CU::store(int registerAdress,int memoryCell,Memory& mainMemory)
{
    //mahmoud will write code here.
}

void CU::move(int registerAdress , int registerAdress2 , Memory& mainMemory)
{
    //saif omar will write code here.
}

void CU::add(char opCode,int registerAdress,int registerAdress2,int registerAdress3, Memory& mainMemory)
{

    //saif omar will write code here
}

void CU::jump(int registerAdress,int memoryCell,Memory& mainMemory)
{
    //hassan momen will write code here.
}

void CU::halt()
{
    //hassan momen will write code here.
}

//class ALU

string ALU::fromHextoBinary(const string& hex)
{
        //mahmoud will write code here.
}

string ALU::fromHextoFloat(const string& hex)
{
        //saif will write code here.
}

int ALU::fromHextoInt(const string& hex)
{
        // hassan will write code here.
}

//class CPU

void CPU::fetch(Memory& mainMemory)
{
    IR = mainMemory.getMemory(PC);
}

void CPU::decode(int& registerAdress,int& memoryCell)
{
     char opCode=IR[0];
      registerAdress=logicalUnit.fromHextoInt(IR.substr(1,1));
      memoryCell=logicalUnit.fromHextoInt(IR.substr(2,2));
}


void CPU::execute(Memory& machineMemory)
{
    int registerAdress;
    int registerAdress2;
    int registerAdress3;
    int memoryCell;
    switch(IR[0])
    {
        case '1':
            controlUnit.load('1',registerAdress,memoryCell,machineMemory);
            break;
        case '2':
            controlUnit.load('2',registerAdress,memoryCell,machineMemory);
            break;
        case '3':
            controlUnit.store(registerAdress,memoryCell,machineMemory);
            break;
        case '4':
            controlUnit.move(IR[2],IR[3],machineMemory);
            break;
        case '5':
            controlUnit.add('5',registerAdress,registerAdress2,registerAdress3,machineMemory);
            break;
        case '6':
            controlUnit.add('6',registerAdress,registerAdress2,registerAdress3,machineMemory);
            break;
        case 'B':
            controlUnit.jump(registerAdress,memoryCell,machineMemory);
            break;
        case 'C':
            controlUnit.halt();
            break;


    }
}

//class Machine

void Machine::loadInstruction(const string& instruction,int address)
{
    machineMemory.setMemory(address,instruction);
}

void Machine::process()
{
    processor.fetch(machineMemory);
    processor.decode();
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
