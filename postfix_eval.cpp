/*
Name:               Tommy Luu
WSU ID:             P476T774
Course:             CS 400
Program Number:     4

*/

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <array>

using namespace std;

int main(void)
{
    //Variable Declarations
    stack<int> post;
    string input;
    int operand_1, operand_2, digit;
    char ch;

    //Get postfix equation from user
    getline(cin, input);

    //Iterate through each character in equation
    for(int i = 0; i < input.length(); i++)
    {
        ch = input[i];

        //Check if the char is a digit
        if(isdigit(ch))
        {
            //If it is a digit, push it to the stack
            digit = ch - '0';
            cout << "Push " << digit << " to stack\n";
            post.push(digit);
        }
        else
        {
            //If it is not a digit, calculate with the correct operator
            if (ch == '+')
            {
                cout << ch << " operator detected.\n";
                //Make sure there are two operands on stack
                if(post.size() > 1)
                {
                    try
                    {
                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the second operand off the stack 
                        operand_2 = post.top();
                        post.pop();
                        cout << "Pop " << operand_2 << " off stack as operand_2\n";

                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the first operand off the stack
                        operand_1 = post.top();
                        post.pop();
                        cout << "Pop " << operand_1 << " off stack as operand_1\n";
                    }
                    catch(...)
                    {
                        cerr << "Stack Underflow.";
                        return 0;
                    }

                    //Calculate and push answer to stack
                    cout << "Perform  operand_1 " << ch << " operand_2\n";
                    cout << "Push result: " << operand_1 + operand_2 << " to stack\n";
                    post.push(operand_1 + operand_2);
                }
            }
            else if(ch == '-')
            {
                cout << ch << " operator detected.\n";
                //Make sure there are two operands on stack
                if(post.size() > 1)
                {
                    try
                    {
                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the second operand off the stack 
                        operand_2 = post.top();
                        post.pop();
                        cout << "Pop " << operand_2 << " off stack as operand_2\n";

                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the first operand off the stack
                        operand_1 = post.top();
                        post.pop();
                        cout << "Pop " << operand_1 << " off stack as operand_1\n";
                    }
                    catch(...)
                    {
                        cerr << "Stack Underflow.";
                        return 0;
                    }
                    
                    //Calculate and push answer to stack
                    cout << "Perform  operand_1 " << ch << " operand_2\n";
                    cout << "Push result: " << operand_1 - operand_2 << " to stack\n";
                    post.push(operand_1 - operand_2);
                }
            }
            else if(ch == '*')
            {
                cout << ch << " operator detected.\n";
                //Make sure there are two operands on stack
                if(post.size() > 1)
                {
                    try
                    {
                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the second operand off the stack 
                        operand_2 = post.top();
                        post.pop();
                        cout << "Pop " << operand_2 << " off stack as operand_2\n";

                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the first operand off the stack
                        operand_1 = post.top();
                        post.pop();
                        cout << "Pop " << operand_1 << " off stack as operand_1\n";
                    }
                    catch(...)
                    {
                        cerr << "Stack Underflow.";
                        return 0;
                    }

                    //Calculate and push answer to stack
                    cout << "Perform  operand_1 " << ch << " operand_2\n";
                    cout << "Push result: " << operand_1 * operand_2 << " to stack\n";
                    post.push(operand_1 * operand_2);
                }
            }
            else if(ch == '/')
            {
                cout << ch << " operator detected.\n";
                //Make sure there are two operands on stack
                if(post.size() > 1)
                {
                    try
                    {
                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the second operand off the stack 
                        operand_2 = post.top();
                        post.pop();
                        cout << "Pop " << operand_2 << " off stack as operand_2\n";

                        //Check for underflow
                        if(post.empty())
                            throw;
                        //Pop the first operand off the stack
                        operand_1 = post.top();
                        post.pop();
                        cout << "Pop " << operand_1 << " off stack as operand_1\n";
                    }
                    catch(...)
                    {
                        cerr << "Stack Underflow";
                        return 0;
                    }

                    try
                    {
                        //Check to see if dividing by zero
                        if(operand_2 == 0)
                            throw operand_2;

                        //Calculate and push answer to stack
                        cout << "Perform  operand_1 " << ch << " operand_2\n";
                        cout << "Push result: " << operand_1 / operand_2 << " to stack\n";
                        post.push(operand_1 / operand_2);
                    }
                    catch(int e)
                    {
                        cerr << "Cannot divide by zero";
                        return 0;
                    }
                    
                }
            }
        }
    }

    //If there is more than 1 number on the stack, the equation is invalid
    //Otherwise, print the answer
    if (post.size() > 1)
        cout << "Invalid postfix equation.";
    else
        cout << "\nAnswer: " << post.top() << endl;
    

    return 0;
}

