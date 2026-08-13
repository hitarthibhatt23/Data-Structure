#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

// Function to perform calculation
int calculate(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;

    case '-':
        return a - b;

    case '*':
        return a * b;

    case '/':
        return a / b;

    case '^':
        return pow(a, b);

    default:
        return 0;
    }
}

// Function to evaluate postfix expression
int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (char ch : postfix)
    {
        // If character is a number
        if (isdigit(ch))
        {
            s.push(ch - '0');
        }

        // If character is an operator
        else
        {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result = calculate(a, b, ch);

            s.push(result);
        }
    }

    return s.top();
}

int main()
{
    string postfix;

    cout << "===== POSTFIX EXPRESSION EVALUATION =====" << endl;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);

    cout << "Postfix Expression: " << postfix << endl;
    cout << "Result: " << result << endl;

    return 0;
}
