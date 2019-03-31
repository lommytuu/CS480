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

//Template class for stacks in function
template <class T>
//Compare stack function
bool compareStacks(stack<T> a, stack<T> b)
{
    T temp1;
    T temp2;

    //Return false if stacks aren't the same size
    if(a.size() != b.size())
        return false;

    //Compare each element of stack 
    while(a.empty() == false)
    {
        temp1 = a.top();
        temp2 = b.top();

        if(temp1 != temp2)
            return false;

        a.pop();
        b.pop();
    }

    //Return true if each element is equal
    return true;
}

int main(void)
{
    //Variable Declarations
    stack<int> istk1, istk2;
    stack<double> dstk1, dstk2;
    stack<char> cstk1, cstk2;
    string strInput, strReverse = "";

    //INTEGER STACKS
    //Populate both stacks with the same information
    for(int i = 0; i < 5; i++)
    {
        istk1.push(i);
        istk2.push(i);
    }
    
    //Compare the stacks, they should be equal
    if(compareStacks(istk1, istk2))
        cout << "These integer stacks are the same.\n";
    else
        cout << "These integer stacks are not equal.\n";

    //Empty the second stack
    while(istk2.empty() == false)
    {
        istk2.pop();
    }

    //Populate with different elements
    for(int i = 7; i < 12; i++)
    {
        istk2.push(i);
    }

    //Compare the stacks, they should be NOT equal
    if(compareStacks(istk1, istk2))
        cout << "These integer stacks are the same.\n";
    else
        cout << "These integer stacks are not equal.\n";

    //DOUBLE STACKS
    //Push elements to double stacks
    cout << endl;

    dstk1.push(3.1);
    dstk1.push(2.6);
    dstk1.push(4.5);
    dstk2.push(3.1);
    dstk2.push(2.6);
    dstk2.push(4.5);
   
    //Compare the stacks, they should be equal
    if(compareStacks(dstk1, dstk2))
        cout << "These double stacks are the same.\n";
    else
        cout << "These double stacks are not equal.\n";

    //Empty the second stack
    while(dstk2.empty() == false)
    {
        dstk2.pop();
    }
    
    //Push new values to second stack
    dstk2.push(48485.43);
    dstk2.push(45.7985);

     //Compare the stacks, they should NOT be equal
    if(compareStacks(dstk1, dstk2))
        cout << "These double stacks are the same.\n";
    else
        cout << "These double stacks are not equal.\n";

    //CHAR STACKS
    cout << endl;

    cstk1.push('c');
    cstk1.push('h');
    cstk1.push('a');
    cstk1.push('r');

    cstk2.push('c');
    cstk2.push('h');
    cstk2.push('a');
    cstk2.push('r');

     //Compare the stacks, they should be equal
    if(compareStacks(cstk1, cstk2))
        cout << "These char stacks are the same.\n";
    else
        cout << "These char stacks are not equal.\n";

    //Empty the second stack
    while(cstk2.empty() == false)
    {
        cstk2.pop();
    }

    cstk2.push('s');
    cstk2.push('i');
    cstk2.push('k');
    cstk2.push('e');

    //Compare the stacks, they should NOT be equal
    if(compareStacks(cstk1, cstk2))
        cout << "These char stacks are the same.\n";
    else
        cout << "These char stacks are not equal.\n";

    return 0;
}

