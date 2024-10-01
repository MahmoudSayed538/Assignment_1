// File: A1_T1_SectionNum_20230372.cpp
// Purpose: Assignment1:: Task 1 :: problems :: 2,5,8,11
// Author: Mahmoud Sayed Mahmoud Younis :: Id =20230372
// Section: unknown
// Id : 20230372
// TA: unknown
// Date: 8 Oct 2024

//explantion.

#include<bits/stdc++.h>
using namespace std;

// menu.
bool badInput(string &Input,string good)
{
    regex goodInput(good);
    bool okay = regex_match(Input,goodInput);
    if(!okay)
    {
        return true;
    }else{
        return false;
    }
}regex val(string s)
{
    regex r (s);
    return r;
}

class menu {
    public:
        string input;
        string good="[ ]*[0,2,5,8,11][ ]*";
        menu()
        {
              cout<< "Choose the problem you wish to solve (2,5,8,11)\nor type 0 to exit\n";
              getline(cin,input);
              while(badInput(input,good))
              {
                  cout<<"Error, you Input is not correct\nPlease try again and make sure to choose from (2,5,8,11) as your input or type 0 to exit\n";
                  getline(cin,input);
                  badInput(input,good);
              }
        }
};


class problem_2{
    public:
        problem_2()
        {
            cout<<"code is okay\n";
        }
};
class problem_5{
    public:
        problem_5()
        {
            cout<<"code is okay\n";
        }

};
class problem_8{
    public:
        problem_8()
        {
            cout<<"code is okay\n";
        }

};
class problem_11{
    public:
        problem_11()
        {
            cout<<"code is okay\n";
        }

};

int main()
{
    while(true)
    {
        menu *Menu = new menu();
        if(regex_match(Menu->input,val("[ ]*2[ ]*")))
        {
            problem_2 *solution=new problem_2();
            delete(solution);

        }else if(regex_match(Menu->input,val("[ ]*5[ ]*")))
        {
            problem_5 *solution=new problem_5();
            delete(solution);
        }else if(regex_match(Menu->input,val("[ ]*8[ ]*")))
        {
            problem_8 *solution=new problem_8();
            delete(solution);
        }else if(regex_match(Menu->input,val("[ ]*11[ ]*")))
        {
            problem_11 *solution=new problem_11();
            delete(solution);
        }else{
            cout<<"Thank you for using the program\n";
            delete(Menu);
            break;
        }
    }
}
