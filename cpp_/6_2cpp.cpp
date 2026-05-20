#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class QueueLinkedList
{
    Node *front, *rear;

public:

    QueueLinkedList()
    {
        front = NULL;
        rear = NULL;
    }

    // Enqueue Operation
    void enqueue(int value)
    {
        Node* newNode = new Node();

        newNode->data = value;
        newNode->next = NULL;

        if(rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;

            rear = newNode;
        }

        cout << value << " inserted into queue\n";
    }

    // Dequeue Operation
    void dequeue()
    {
        if(front == NULL)
        {
            cout << "Queue Underflow\n";
        }
        else
        {
            Node* temp = front;

            cout << front->data << " deleted from queue\n";

            front = front->next;

            delete temp;

            if(front == NULL)
            {
                rear = NULL;
            }
        }
    }

    // Display Queue
    void display()
    {
        if(front == NULL)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            Node* temp = front;

            cout << "\nQueue Elements:\n";

            while(temp != NULL)
            {
                cout << temp->data << " ";

                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    QueueLinkedList q;

    int choice, value;

    while(true)
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                q.enqueue(value);
                break;

            case 2:

                q.dequeue();
                break;

            case 3:

                q.display();
                break;

            case 4:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}