#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Function to determine operator precedence
int precedence(char op)
{
    if (op == '^')
        return 3;

    if (op == '*' || op == '/')
        return 2;

    if (op == '+' || op == '-')
        return 1;

    return 0;
}

// Function to check whether character is an operator
bool isOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' ||
           ch == '/' || ch == '^';
}

// Function to convert infix expression to postfix
string infixToPostfix(string infix)
{
    stack<char> s;
    string postfix = "";

    for (char ch : infix)
    {
        // If operand, add it directly to postfix
        if (isalnum(ch))
        {
            postfix += ch;
        }

        // If opening bracket
        else if (ch == '(')
        {
            s.push(ch);
        }

        // If closing bracket
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop(); // Remove '('
        }

        // If operator
        else if (isOperator(ch))
        {
            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch))
            {
                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty())
    {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "===== INFIX TO POSTFIX CONVERSION =====" << endl;

    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);

    cout << "Infix Expression  : " << infix << endl;
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
