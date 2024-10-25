#pragma once
#include <bits/stdc++.h>
#include <cerrno>
#include <iterator>
#include <string>
#include <sys/types.h>
#include <vector>
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
    void getMemory(const int& address);
    void setRegister(const int& address,const string& value);
    void getRegister(const int& address);
};

class CU{
    public:
        void load(const string& instruction,Memory& mainMemory);
        void store(const string& instruction,Memory& mainMemory);
        void move(const string& instruction,Memory& mainMemory);
        void add(const string& instruction,Memory& mainMemory);
        void jump(const string& instruction,Memory& mainMemory);
        void halt(const string& instruction,Memory& mainMemory);
};

class CPU {
    string IR; // instruction register .
    int PC; // program counter.
    CU controlUnit;
    public:
        void fetch(Memory& mainMemory); //fetches the instruction from the memory and assign it to IR
        void decode(); // decodes the instruction in IR.
        void execute(); // executes the current instruction and increases PC by 2.
};

class Machine{
    Memory machineMemory;
    CPU processor;
    public:
        void loadInstruction();// takes instructions from the user and load it to the memory after making sure it is a valid instruction.
        void process();
};

class Main {
    Machine machine;
    public:
         void displayMenu(); 
         void displayStatus();
         void runProgram();
};
