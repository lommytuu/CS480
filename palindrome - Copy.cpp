/*
Name:               Tommy Luu
WSU ID:             P476T774
Course:             CS 400
Program Number:     5

*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
    //Variable Declarations
    stack<char> pal;
    string strInput, strReverse = "";
    char ch;

    cout << "Please enter a word for palindrome check: \n";

    //Get potential palindrome from user
    getline(cin, strInput);

    //Iterate through each character in equation
    //Push each character to stack
    for(int i = 0; i < strInput.length(); i++)
    {
        ch = strInput[i];
        pal.push(ch);
    }

    //Pop each character and add to string to reverse the input string
    while(pal.empty() == false)
    {
        strReverse += pal.top();
        pal.pop();
    }

    //Compare the input string vs the reverse string to determine if palindrome
    if(strInput == strReverse)
        cout << "The phrase is a palindrome.";
    else
        cout << "The phrase is not a palindrome.";

    return 0;
}

