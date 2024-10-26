#pragma once
#include <bits/stdc++.h>
#include <string>
using namespace std;

//helper functions

int fromHexToDec(const string& hex);
string fromHexToBinary(const string& hex);
string fromHexToFloat(const string& hex);

class Memory{
    vector<string> registers;
    vector<string> mainMemory;
    public:
    Memory()
    {
        registers.assign(16,"00");
        mainMemory.assign(256,"00");
    }
    void setMemory(const int& address,const string& value);
    string getMemory(const int& address);
    void setRegister(const int& address,const string& value);
    string getRegister(const int& address);
};


class CPU {
    string IR; // instruction register .
    int PC; // program counter.
    public:
void set(int step,string instruction)
        {
            PC=step;
            IR=instruction;
        }
        void fetch(Memory& mainMemory); //fetches the instruction from the memory and assign it to IR
        void decode(int& registerAdress,int& memoryCell); // decodes the instruction in IR.
        void execute(Memory& machineMemory); // executes the current instruction and increases PC by 2.
};

class CU: CPU{
    public:
        void load(char opCode,string registerAdress,string memoryCell,Memory& mainMemory);
        void store(string registerAdress,string memoryCell,Memory& mainMemory);
        void move(string registerAdress , string registerAdress2 , Memory& mainMemory);
        void add(char opCode,string registerAdress,string registerAdress2,string registerAdress3, Memory& mainMemory);
        void jump(string registerAdress,string memoryCell,Memory& mainMemory);
        void halt();

};


class Machine{
    Memory machineMemory;
    CPU processor;
    public:
        void loadInstruction(const string& instruction,int address);// takes instructions from the user and load it to the memory after making sure it is a valid instruction.
        void process();
        void displayStatus(char choice);
};

class UI {
    Machine myMachine;
    bool fileOrInstruction;
    public:
         bool getFileOrInstruction();
         void displayMenu();
         bool isValid(const string& input,regex goodInput);
         string inputFileName();
         string inputInstruction();
         char inputChoice();
};


