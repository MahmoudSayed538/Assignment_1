// File: A1_T1_SectionNum_20230372.cpp
// Purpose: Assignment1:: Task 1 :: problems :: 2,5,8,11
// Author: Mahmoud Sayed Mahmoud Younis :: Id =20230372
// Section: unknown
// Id : 20230372
// TA: unknown
// Date: 8 Oct 2024

//explantion.

#include<bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <regex>
#include <string>
#include <variant>
using namespace std;

// menu.

bool badInput(string &Input)
{
    regex goodInput("[ ]*[0,2,5,8,11]?[ ]*");
    bool good = regex_match(Input,goodInput);
    if(!good)
    {
        return true;
    }else{
        return false;
    }
}

string menu()
{
    cout<< "Choose the problem you wish to solve (2,5,8,11)\nor type 0 to exit\n";
    string choice;
    getline(cin,choice);
    while(badInput(choice))
    {
        cout<<"Error, you Input is not correct\nPlease try again and make sure to choose from (2,5,8,11) as your input\n";
        getline(cin,choice);
        badInput(choice);
    }
    return choice;

}

string problem_2()
{
    string message;
    getline(cin,message);
    string masculine[3]={"he","him","his"};
    string feminine[3]={"she","her","hers"};
    // to be continued.

}

int main()
{
    while(true)
    {
        if(menu()=="0")
        {
            cout<<"Thank you for using the program\n";
            break;
        }else if (menu()=="2")
        {
            problem_2();
        }else if (menu()== "5")
        {
            //code for problem 5;
        }else if (menu()=="8")
        {
            //code for problem 8;
        }else {
            // code for problem 11;
        }
    }
}
