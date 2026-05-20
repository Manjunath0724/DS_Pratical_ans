#include <iostream>
using namespace std;

#define MAX 100

class QueueArray
{
    int queue[MAX];
    int front, rear;

public:

    QueueArray()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue Operation
    void enqueue(int value)
    {
        if(rear == MAX - 1)
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            if(front == -1)
            {
                front = 0;
            }

            rear++;

            queue[rear] = value;

            cout << value << " inserted into queue\n";
        }
    }

    // Dequeue Operation
    void dequeue()
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
        }
        else
        {
            cout << queue[front] << " deleted from queue\n";

            front++;
        }
    }

    // Display Queue
    void display()
    {
        if(front == -1 || front > rear)
        {
            cout << "Queue is Empty\n";
        }
        else
        {
            cout << "\nQueue Elements:\n";

            for(int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    QueueArray q;

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