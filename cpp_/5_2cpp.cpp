#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class StackLinkedList
{
    Node *top;

public:
    StackLinkedList()
    {
        top = NULL;
    }

    // Push Operation
    void push(int value)
    {
        Node *newNode = new Node();

        newNode->data = value;
        newNode->next = top;

        top = newNode;

        cout << value << " inserted into stack\n";
    }

    // Pop Operation
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            Node *temp = top;

            cout << top->data << " deleted from stack\n";

            top = top->next;

            delete temp;
        }
    }

    // Display Stack
    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
        }
        else
        {
            Node *temp = top;

            cout << "\nStack Elements:\n";

            while (temp != NULL)
            {
                cout << temp->data << endl;

                temp = temp->next;
            }
        }
    }
};

int main()
{
    StackLinkedList s;
    int choice, value;

    while (true)
    {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
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