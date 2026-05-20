#include <iostream>
using namespace std;

#define MAX 100

class StackArray
{
    int stack[MAX];
    int top;

public:

    StackArray()
    {
        top = -1;
    }

    // Push Operation
    void push(int value)
    {
        if(top == MAX - 1)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            top++;
            stack[top] = value;

            cout << value << " inserted into stack\n";
        }
    }

    // Pop Operation
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            cout << stack[top] << " deleted from stack\n";

            top--;
        }
    }

    // Display Stack
    void display()
    {
        if(top == -1)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            cout << "\nStack Elements:\n";

            for(int i = top; i >= 0; i--)
            {
                cout << stack[i] << endl;
            }
        }
    }
};

int main()
{
    StackArray s;
    int choice, value;

    while(true)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
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
                s.display();
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}