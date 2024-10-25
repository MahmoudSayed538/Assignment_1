#include <bits/stdc++.h>
#include "vole.h"
using namespace std;
int main()
{
    UI menu;
    Machine myMachine;
    for(int i = 0 ; i<16 ; i++)
    {
        myMachine.loadInstruction();
        if(myMachine.run())
        {
            break;
        }
    }myMachine.process();
}   
