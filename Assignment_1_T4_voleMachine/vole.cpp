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

//class Register

void Register::setRegister(const int& address,const string& value)
{
    regist[address]=value;
}

string Register::getRegister(const int& address)
{
     return regist[address];
}
    
//class CU 

void CU::load(char opCode,string registerAdress,string memoryAddress,Memory& mainMemory,Register& regist)
{
    //mahmoud will write code here.
    int memoryCell = fromHexToDec(memoryAddress);
    int registerCell=fromHexToDec(registerAdress);
    if(opCode=='1')
    {
        string bitPattern=mainMemory.getMemory(memoryCell);
        regist.setRegister(registerCell,bitPattern);
    }else{
        string bitPattern=to_string(memoryCell);
        regist.setRegister(registerCell,bitPattern);
    }
}

void CU::store(string registerAdress,string memoryAddress,Memory& mainMemory,Register& regist)
{
    int memoryCell= fromHexToDec(memoryAddress);
    int registerCell = fromHexToDec(registerAdress);
    string bitPattern=regist.getRegister(registerCell);
    mainMemory.setMemory(memoryCell,bitPattern);
}

void CU::move(string registerAdress , string registerAdress2 , Memory& mainMemory,Register& regist)
{
    //saif omar will write code here.
}

void CU::add(char opCode,string registerAdress,string registerAdress2,string registerAdress3, Memory& mainMemory,Register& regist)
{

    //saif omar will write code here
}

void CU::jump(string registerAdress,string memoryCell,Memory& mainMemory,Register& regist)
{
    //hassan momen will write code here.
    int rcell = fromHexToDec(registerAdress);
    int mcell = fromHexToDec(memoryCell);

    if(regist.getRegister(rcell) == regist.getRegister(0))
    {
        PC = stoi(mainMemory.getMemory(mcell)); // fix this , you need to point to an address not a data.
    }
    else{
        PC = PC+1;
    }

}

void CU::halt()
{
    //hassan momen will write code here.
    //no need to code any thing, will be handled in gui.
}

void CU::execute()
{
    string instruct;
    instruct=getIR();
    switch(instruct[0])
    {
        case '1':
            // will use load.
        case '2':
            //will use load also.
        
            //continue
    }
}




//class CPU

void CPU::fetch(Memory& mainMemory)
{
    IR = mainMemory.getMemory(PC)+mainMemory.getMemory(PC+1);
}

void CPU::decode(string &ir)
{
     char proc = ir[0];
    if(proc == '1' || proc == '2' || proc == '3' || proc == 'B' || proc == 'C' )
    {
        char reg_f = ir[1];
        int mem_f =  stoi(ir.substr(2));

    }
    else if(proc == '4' )
    {
        char reg_f = ir[2];
        char reg_s = ir[3];
    }
    else if(proc == '5' || proc == '6' )
    {
        char reg_f = ir[1];
        char reg_s = ir[2];
        char reg_t = ir[3];
    }

}



//class Machine

void Machine::loadInstruction(const string& instruction,int address)
{
    machineMemory.setMemory(address,instruction);
}

void Machine::process()
{
    
}

void Machine::displayStatus(char choice)
{
    
}


