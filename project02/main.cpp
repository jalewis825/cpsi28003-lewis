// University of Arkansas at Little Rock
// Department of Computer Science
// CPSI 28003: Algorithms
// Spring 2026
// Project 2: Infix to Postfix Conversion; Bonus: evaluate arithmetic expressions for the results; This program is not a menu-driven.
// Due Date: April 23, 2026, Thursday
// Name: Jessi Lewis
// ID-number (Last 4 Digits): 39929
// Description of the Program (2-3 sentences): This program reads arithmetic expressions from the user,
// converts them from infix notation to postfix notation using a stack-based algorithm, and then
// evaluates the postfix expression to compute a numerical result.
// Date Written: 22 April 2026
// Date Revised: 22 April 2026

#include <iostream>
#include <string>
#include <stack>
using namespace std;

// You can type an arithmetic expression with no, one or more than one spaces between each operator and operand
// If no spaces is given between each operator and operand, this function will add spaces to them

string InfixToPostfix(char *str);
int precedence(char op); // helper function to determine precedence of operators
int Evaluate(string postfix);

char *AddDelimetersToStr(char *str)
{
    int spacesNeeded = 0;
    int length = 0;
    while (str[length] != '\0') // Hit enter on my computer,
                                // it produces \0, maybe your computer may produce different
    {
        if (str[length] != ' ')
            spacesNeeded = spacesNeeded + 1;
        length = length + 1;
    }
    int size = length + spacesNeeded + 1;
    char *adjustedStr = new char[size];

    // Insert delimeters between operands and operators
    int newInx = 0;
    for (int inx = 0; inx < length; inx++)
    {
        if (str[inx] != ' ')
        {
            adjustedStr[newInx] = str[inx];
            newInx = newInx + 1;
            adjustedStr[newInx] = ' ';
            newInx = newInx + 1;
        }
    }
    adjustedStr[newInx] = '\0';
    // cout << "string with delimteres: " << adjustedStr << endl;
    // system("PAUSE");
    return adjustedStr;
}

// Returns precedence level for comparison in InfixToPostfix
// Higher value = higher priority
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1; // Lowest priority operators
    if (op == '*' || op == '/')
        return 2; // Highest priority operators
    return 0;     // '(' returns 0 so it never causes a pop
}

// Converts a space-delimited infix expression to postfix notation
// Uses STL stack to manage operators and parentheses
string InfixToPostfix(char *str)
{
    stack<char> s;
    string postfix = "";
    int i = 0;

    while (str[i] != '\0')
    {
        char token = str[i];

        // Skips spaces inserted by AddDelimetersToStr
        if (token == ' ')
        {
            i++;
            continue;
        }

        // Case 1: Open parenthesis -> push onto stack
        if (token == '(')
        {
            s.push(token);
        }

        // Case 2: Checks if operand is single digit -> append to output
        else if (token >= '0' && token <= '9')
        {
            postfix += token;
            postfix += ' ';
        }

        // Case 3: Closed parenthesis -> pop until matching '('
        else if (token == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            s.pop(); // Discard the '('
        }

        // Case 4: operator (+, -, *, /)
        else
        {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(token))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }

            s.push(token);
        }

        i++;
    }

    // Drain any operators still on the stack
    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

// Evaluates a postfix expression and returns the numerical result.
// Uses STL stack to hold operands as we compute.
int Evaluate(string postfix)
{
    stack<int> s; // Stack of operands (numbers waiting to be used for computation)
    int i = 0;    // Index for walking through postfix string

    while (i < postfix.length())
    {
        char token = postfix[i];

        // Skips spaces between tokens
        if (token == ' ')
        {
            i++;
            continue;
        }

        // Case 1: operand (single digit) -> convert to int and push
        if (token >= '0' && token <= '9')
        {
            int num = token - '0'; // Convert char digit to int (ex: '3' -> 3)
            s.push(num);
        }

        // Case 2: operator (+, -, *, /) -> pop two operands, compute, push result
        else
        {
            // First pop = right operand, second pop = left operand
            // Order matters for '-' and '/' since they aren't commutative
            int right = s.top();
            s.pop();

            int left = s.top();
            s.pop();

            int result;

            // Apply the operator to the two operands
            if (token == '+')
                result = left + right;
            else if (token == '-')
                result = left - right;
            else if (token == '*')
                result = left * right;
            else if (token == '/')
                result = left / right;

            // Push computed value back so it can be used by later operators
            s.push(result);
        }

        i++;
    }

    // After processing all tokens, the final answer is the only value left on the stack
    return s.top();
}

// Note: Changed void main() to int main() so the program would compile.
// The logic of main() is unchanged from the project prompt with the exception of adding Evaluate(postfix).
int main()
{
    // Input arithmetic expression should be less than 80 characters
    char *str = new char[80];
    while (1) // type ccontrol_c to exit the loop
    {
        // You can assume legal arithmetic expressions only
        cout << "Enter an arithmetic equation..." << endl;
        cin.getline(str, 80);
        str = AddDelimetersToStr(str);

        string postfix = InfixToPostfix(str); // Convert infix to postfix
        cout << postfix << endl;              // Print postfix expression
        cout << Evaluate(postfix) << endl;    // Print computed value
    }

    return 0;
}