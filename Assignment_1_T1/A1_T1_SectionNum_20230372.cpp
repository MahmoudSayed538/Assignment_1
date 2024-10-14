// File: A1_T1_SectionNum_20230372.cpp
// Purpose: Assignment1:: Task 1 :: problems :: 2,5,8,11
// Author: Mahmoud Sayed Mahmoud Younis :: Id =20230372
// Section: unknown
// Id : 20230372
// TA: unknown
// Date: 8 Oct 2024

/* 
   explanation {
        in this program the user will choose a problem from the 4 problems in        sheet 1 and they are (2,5,8,11) , in problem 2 the user will enter a         sentence and the program will convert male speech to inclusive speech
        in problem 5 the program will manage a list of up to 10 players
        and the user can choose to add a new player or show the list or
        find a certain player and show his score
        in problem 8 the program will print a fractal pattern that is based
        on pattern where the upper half == the second half and they seperated
        with a line of n length starting at i column of the output
        the user will enter (n) which must be a power of 2 and (i)
        in problem 11 the program will compare two files either character by         character or word by word depending on the user's choice
        the main program has a menu and so does each problem.
   }
 */

#include<bits/stdc++.h>
#include <cctype>
using namespace std;

// menu.
// badInput compares user input with a certain criteria.
bool badInput(const string &Input,const string &good)
{
    regex goodInput(good); // create the good input
    bool okay = regex_match(Input,goodInput);//check if the input is okay
    if(!okay)
    {
        return true;// return true if not okay
    }else{
        return false;// return false if okay
    }
}

// lowerCasingSpacing removes any spaces and lower case a given string.
string lowerCasingSpacing(const string &s) 
{
    string m="";
    for(char c : s)
    {
        if(c!=' ')
        {
            m+=tolower(c); // returning lower case letters except ' '.
        }
    }return m;
}

// menu displays a chosen user message, takes input and handles the input
// if needed.
string menu(string userMessage,bool handle,string good)
{
    string input; 
    cout<<userMessage; // speaking to the user.
    getline(cin,input);
    if(handle) // if handling is necessary
    {
        while(badInput(input,good)) // invoking badInput function.
        {
            cout<<"Error! your input wasn't correct. Please try again\n";
            getline(cin,input);
            badInput(input,good);
        }
    }return input; // return a clean input.
}




class problem_2{
    string message;
    vector <string> male={"he","He","him","Him","his","His"}; // possible male pronouns
    vector <string> female={"she","She","her","Her","her","Her"};// possible female pronouns
    string inclusive=""; // the inclusive sentence.
    string word=""; // used to contain a word.
    public:
    problem_2()
    {
        // invoking the menu function to take input and display a uniqu menu for problem_2 only.

        message=menu("This program will receive a sentence and will convert male speech to inclusive speech\nplease enter you sentence\n",false,"");

        for(int i =0 ; i<message.length() ; i++)
        {
            inclusive+=message[i];
            word+=message[i];
            if(message[i]==' ' || i+1 ==message.length()) // stopping at the end of the word or the sentence.
            {
                if(message[i]==' ')
                {
                    word.pop_back();                 // deleting the add space
                    inclusive.pop_back();
                }
                auto it = find(male.begin(),male.end(),word); // finding the word in the male vector.
                if(it != male.end())
                {
                    inclusive+=" or "+female[it-male.begin()]+' '; // if the word exists it will converted to an inclusive sentence and added to inclusive.
                }else{inclusive+=' ';}// if not then we will just add a space to inclusive.
                word=""; // emptying the word to collect the next one.
            }
        }cout<<inclusive<<'\n'; // the answer.
    }
};



class problem_5{
    string mode; // collects the user's choice between adding , printing or finding.
    vector<pair<string,int>> list; // a list for the players and their scores.

    static bool compareByValue(const pair<string,int> &a, const pair<string,int> &b)
    {
        return a.second > b.second; // comparing the players by their scores.
    }
    void add()
    {
        string name , score;
        name=menu("Enter the name of the player\n",true,"[ ]*[a-zA-Z]+[ ]*"); // getting the name of the player and handling wrong inputs.
        score=menu("Enter the score of the player\n",true,"[ ]*[0-9]+[ ]*");  // getting the score of the player and handling wrong inputs.
        int realScore=stoi(score); // getting score as an integer.
        list.push_back({name,realScore});// adding the new player.
        sort(list.begin(),list.end(),compareByValue); // sorting the players according to their scores by using the compareByValue function as comparator.
        while(list.size() > 10)
        {
            list.pop_back(); // making sure that the number of players doesn't exceed 10.
        }
    }
    void print()
    {
        if(list.empty())
        {
            cout<<"There are no players in the list\n"; // checking if the list is empty.
        }else{
            int playerNum = 1;
            for(auto players : list)
            {
                cout<<playerNum<<": "<<players.first<<": "<<players.second<<'\n';  // printing the list of players.
                playerNum++;
            }
        }
    }
    void find()
    {
        string playerToFind;
        playerToFind=menu("Enter the name of the player\n",true,"[ ]*[a-zA-Z]+[ ]*"); // getting the name of the player and handling wrong input.
        playerToFind = lowerCasingSpacing(playerToFind); //modifying the name so it can be compared easily.
        bool exists = false;  
        for(auto players : list)
        {
            string comparator = lowerCasingSpacing(players.first); // modifying the players name so it can be compared easily.
            if(comparator==playerToFind)
            {
                cout<<players.first<<": "<<players.second<<'\n'; // printing the player's data.
                exists=true;// the player exists.
                break;
            }
        } if(!exists)
        {
            cout<<"This player doesn't exist as a top scorer\n";
        }
    }

    public:
    problem_5()
    {

        while(true)
        {
            // getting the chosen mode and handling wrong input.
            mode=menu("This program manages a list of up to 10 players and their high scores\nType (a) to add a new player and score\nType (b) to see the list\nType (c) to enter a player's name and out put his score\nor Type (0) to exit\n",true,"[ ]*[a,b,c,A,B,C,0]+[ ]*");
            mode=lowerCasingSpacing(mode); // modifying the input so it can be compared easily.
            if(mode == "a")
            {
                add();
            }else if (mode == "b")
            {
                print();
            }else if (mode == "c")
            {
                find();
            }else
            {
                cout<<"Returning to the main menu\n";
                break;
            }

        }

    }

};
class problem_8{
    int n; // the longest line in the pattern.
    int i; // the starting column of output

    // powerOf2 checks if n is a power of 2.
    bool powerOf2(const int &n)
    {
        int m = 1; 
        while(m<n)
        {
            m*=2;  
        }if(m==n)
        {
            return true;
        }else{
            return false;
        }
    }

    // space prints a (i) numbers of spaces.
    void space(int i)
    {
        for(int m =0 ; m<i ; m++)
        {
            cout<<" ";
        }
    }

    //star prints a (n) number of stars.
    void star(int n)
    {
        for(int m = 0 ; m<n ; m++)
        {
            cout<<"* ";
        }
    }

    //the pattern is generated by printing the top half and the lower half seperated by a line of length (n) starting at column (i)
    void pattern( int n , int i)
    {
        if(n==1) // printing the last star and stopping the recursion.
        {
            space(i);
            cout<<"*\n";
            return;
        }pattern(n/2,i); // the first half.
        space(i); // making sure the output starts it column (i).
        star(n); // pringtin (n) stars ( the longest line )
        cout<<'\n';

        pattern(n/2,i+(n/2)); // the second half.
    }
    public:
        problem_8()
        {
            // getting n and i as two strings x and y to handle any wrong input.
            string x = menu("This program generates a fractal pattern with the longest line being (n) and (n) must be a power of (2) and not (0) starting at column (i) please enter the value of (n)\n",true,"[ ]*[0-9]+[ ]*");
            string y = menu("Please enter the value of (i)\n",true,"[ ]*[0-9]+[ ]*");
            n = stoi(x);
            while(!powerOf2(n)) // making sure n is a power of 2.
            {
                cout<<"The number (n) must be a power of two please try again\n";
                string s = menu("",true,"[ ]*[0-9]+[ ]*");
                n=stoi (s);
            }
            i = stoi(y);
           pattern(n,i);

        }

};
class problem_11{
    string choice; // getting the user's choice wether to compare the files by character or by word.
    ifstream loadFile () // a function to load a file and make sure it loads correctly.
    {
        string fileName;
        getline(cin,fileName); // getting the file name.
        ifstream File(fileName);
        while(!File.is_open()) // making sure it exists
        {
            cout<<"The file you are trying to load doesn't exist\nplease try again\n"; // output until the right name is entered.
            getline(cin,fileName);
            ifstream File (fileName); 
        }return File; // loaded the file.
    }

// compare the files by character.
    void compareByChar(ifstream &file1, ifstream &file2) {
        string line1, line2; // used to store the text from the two files.
        int lineNum = 0; // used to store the current line's number.
        bool Identical = true;

        while (getline(file1, line1) && getline(file2, line2)) {
        lineNum++;
        if (line1 != line2) {  // picking the first difference
            Identical = false;
            cout << "Files differ at line " << lineNum << ":" << '\n';  // printing the number of the line.
            cout << "File 1: " << line1 << '\n';
            cout << "File 2: " << line2 << '\n';  // printing the content of the line.
            return;
        }
    }

    if (file1.eof() && file2.eof()) {  // checking if both the files reached the end .
        if (Identical) {
            cout << "Files are identical." << '\n'; 
        }
    } else {
        cout << "Files have different lengths." << '\n';
    }
}

void compareByWord(ifstream &file1, ifstream &file2) {
    string line1, line2;
    int lineNumber = 0;

    // To store words for comparison
    vector<string> words1, words2;

    while (getline(file1, line1)) {
        lineNumber++;
        // Use istringstream to split line into words
        istringstream stream1(line1);
        string word;

        while (stream1 >> word) {
            words1.push_back(word); // Store words in vector
        }

        // Now read the corresponding line from the second file
        if (getline(file2, line2)) {
            istringstream stream2(line2);
            while (stream2 >> word) {
                words2.push_back(word); // Store words in vector
            }
        } else {
            cout << "File 1 has more lines than File 2." << '\n';
            return;
        }

        // Compare the two vectors
        if (words1 != words2) {
            cout << "Files differ at line " << lineNumber << ":" << '\n';
            cout << "File 1 line: " << line1 << '\n';
            cout << "File 2 line: " << line2 << '\n';
            cout << "First different word: ";

            // Find the first differing word
            auto minSize = min(words1.size(), words2.size());
            for (size_t i = 0; i < minSize; ++i) {
                if (words1[i] != words2[i]) {
                    cout << words1[i] << " vs " << words2[i] << '\n';
                    break;
                }
            }
            return;
        }

        // Clear word vectors for the next line
        words1.clear();
        words2.clear();
    }

    // If file2 still has lines left
    if (getline(file2, line2)) {
        cout << "File 2 has more lines than File 1." << '\n';
    } else {
        cout << "Files are identical." << '\n';
    }
}

    public:
        problem_11()
        {
            cout<<"Enter the name of the first file\n";
            ifstream firstFile=loadFile(); // loading the first file.
            cout<<"Enter the name of the second file\n";
            ifstream secondFile=loadFile(); // loading the second file.
            choice = menu("Enter (a) for character by character comparison\nor (b) for word by word comparison\n",true,"[ ]*[a,b]+[ ]*");// explained before.
            choice = lowerCasingSpacing(choice);
            if(choice=="a")
            {
                compareByChar(firstFile,secondFile);
            }else 
            {
                compareByWord(firstFile,secondFile);
            }
        }
};
int main()
{

    while(true)
    {
        // every thing here were explained before.
        string choice=menu("Please choose the program you wish to use (2,5,8,11) or type (0) to exit\n",true,"[ ]*[0,2,5,8,11]+[ ]*");
        choice=lowerCasingSpacing(choice);
        if(choice=="2")
        {
            problem_2 solution;
        }else if(choice=="5")
        {
            problem_5 solution;
        }else if(choice=="8")
        {
            problem_8 solution;
        }else if(choice=="11")
        {
            problem_11 solution;
        }else{
            cout<<"Thank you for using the program\n";
            break;
        }
    }
}
