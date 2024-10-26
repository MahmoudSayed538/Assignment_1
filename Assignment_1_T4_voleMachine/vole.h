#pragma once
#include <bits/stdc++.h>
#include <string>
using namespace std;

class Memory{
    vector<string> registers;
    vector<vector<string>> mainMemory;
    public:
    Memory()
    {
        registers.assign(16,"00");
        mainMemory.assign(16,vector<string>(16,"00"));
    }
    void setMemory(const int& address,const string& value);
    string getMemory(const int& address);
    void setRegister(const int& address,const string& value);
    string getRegister(const int& address);
};

class CU{
    public:
        void load(char opCode,int registerAdress,int memoryCell,Memory& mainMemory);
        void store(int registerAdress,int memoryCell,Memory& mainMemory);
        void move(int registerAdress , int registerAdress2 , Memory& mainMemory);
        void add(char opCode,int registerAdress,int registerAdress2,int registerAdress3, Memory& mainMemory);
        void jump(int registerAdress,int memoryCell,Memory& mainMemory);
        void halt();
};

class ALU{
    public:
        string fromHextoBinary(const string& hex);
        string fromHextoFloat(const string& hex);
        int fromHextoInt(const string& hex);
};

class CPU {
    string IR; // instruction register .
    int PC; // program counter.
    CU controlUnit;
    ALU logicalUnit;
    public:
        void fetch(Memory& mainMemory); //fetches the instruction from the memory and assign it to IR
void decode(int& registerAdress,int& memoryCell); // decodes the instruction in IR.
        void execute(Memory& machineMemory); // executes the current instruction and increases PC by 2.
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


