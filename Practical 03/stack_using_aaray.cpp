#include <iostream>
using namespace std;

#define MAX 100

class Stack
{
private:
    int arr[MAX];
    int top;

public:
    // Constructor
    Stack()
    {
        top = -1;
    }

    // Push operation
    void push(int value)
    {
        if (top == MAX - 1)
        {
            cout << "Stack Overflow!" << endl;
        }
        else
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow!" << endl;
        }
        else
        {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    // Peek operation
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Display operation
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is empty." << endl;
        }
        else
        {
            cout << "Stack elements are: ";

            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n===== STACK USING ARRAY =====" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Program terminated." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
