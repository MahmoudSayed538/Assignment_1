#include "vole.h"
#include <bits/fs_fwd.h>
#include <cstddef>
#include <string>
#include <cmath>
using namespace std;

// helper functions
int fromHexToDec(const string& hex) {
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
            cerr << "Invalid hexadecimal digit: " << hexDigit << endl;
            return -1;
        }

        decimalValue += value * static_cast<int>(pow(16, i));
    }

    return decimalValue;
}

string fromDectoBinary(const int& dec) {
    if (dec == 0) return "0"; 

    string binary;
    int num = dec; 

    while (num > 0) {
        binary = to_string(num % 2) + binary; 
        num /= 2; 
    }
    
    return binary; 
}

int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }
    return decimal;
}

double fromHexToFloat( string& hex) {
    int decimalValue = fromHexToDec(hex);
    string bin = fromDectoBinary(decimalValue);

    while (bin.length() < 32) {
        bin = '0' + bin; 
    }

    int sign = (bin[0] == '1') ? -1 : 1; 
    int exponent = binaryToDecimal(bin.substr(1, 8)) - 127; 
    string mantissa = bin.substr(9);

    double mantissaValue = 1.0; 
    for (int i = 0; i < mantissa.length(); ++i) {
        if (mantissa[i] == '1') {
            mantissaValue += pow(2, -(i + 1)); 
        }
    }

    double floatValue = sign * mantissaValue * pow(2, exponent);

    return floatValue;
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
        PC = mcell ; 
    }
    else{
        PC = PC+1;
    }

}

void OR(int registerAdress , int registerAdress2 , int registerAdress3, Register& regist)
{
string dataF = regist.getRegister(registerAdress);
string dataS = regist.getRegister(registerAdress2);
string result ="";
for (int i = 0; i < dataF.length(); i++) {
        if(dataF[i] == '1' || dataS[i] == '1') result += '1';
        else result += '0';
        
}
regist.setRegister(registerAdress3,result);



}

void AND(int registerAdress , int registerAdress2 , int registerAdress3, Register& regist)
{
string dataF = regist.getRegister(registerAdress);
string dataS = regist.getRegister(registerAdress2);
string result ="";
for (int i = 0; i < dataF.length(); i++) {
        if(dataF[i] == '1' && dataS[i] == '1') result += '1';
        else result += '0';
        
}

regist.setRegister(registerAdress3,result);

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
