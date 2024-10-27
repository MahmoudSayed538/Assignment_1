#pragma once
#include <bits/stdc++.h>
#include <string>
#include <sys/ucontext.h>
#include <vector>
using namespace std;

//a global valuable needs to be declared on whole scope
extern int PC;

//helper functions

int fromHexToDec(const string& hex);
string fromHexToBinary(const string& hex);
string fromHexToFloat(const string& hex);

class Memory{
    vector<string> mainMemory;
    public:
    Memory()
    {
        mainMemory.assign(256,"00");
    }
    void setMemory(const int& address,const string& value);
    string getMemory(const int& address);
};

class Register{
    vector<string> regist;
    public:
    Register()
    {
        regist.assign(16,"00");
    }
    void setRegister(const int& address,const string& value);
    string getRegister(const int& address);
};


class CPU {
    string IR; // instruction register .
    public:
        string getIR();
        void fetch(Memory& mainMemory); //fetches the instruction from the memory and assign it to IR
        void decode(string &ir); // decodes the instruction in IR.
};

class CU: CPU{
    public:
        void load(char opCode,string registerAdress,string memoryCell,Memory& mainMemory,Register& regist);
        void store(string registerAdress,string memoryCell,Memory& mainMemory,Register& regist);
        void move(string registerAdress , string registerAdress2 , Memory& mainMemory,Register& regist);
        void add(char opCode,string registerAdress,string registerAdress2,string registerAdress3, Memory& mainMemory,Register& regist);
        void jump(string registerAdress,string memoryCell,Memory& mainMemory,Register& regist);
        void halt();
        void execute();
};


class Machine{
    Memory machineMemory;
    CPU processor;
    public:
        void loadInstruction(const string& instruction,int address);// takes instructions from the user and load it to the memory after making sure it is a valid instruction.
        void process();
        void displayStatus(char choice);
};

