#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    int queue[MAX];
    int front, rear;

public:

    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    // Enqueue Operation
    void enqueue(int value)
    {
        // Check Overflow
        if((rear + 1) % MAX == front)
        {
            cout << "Circular Queue Overflow\n";
        }
        else
        {
            // First Element
            if(front == -1)
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear = (rear + 1) % MAX;
            }

            queue[rear] = value;

            cout << value << " inserted into circular queue\n";
        }
    }

    // Dequeue Operation
    void dequeue()
    {
        // Check Underflow
        if(front == -1)
        {
            cout << "Circular Queue Underflow\n";
        }
        else
        {
            cout << queue[front] << " deleted from circular queue\n";

            // If only one element exists
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % MAX;
            }
        }
    }

    // Display Queue
    void display()
    {
        if(front == -1)
        {
            cout << "Circular Queue is Empty\n";
        }
        else
        {
            cout << "\nCircular Queue Elements:\n";

            int i = front;

            while(true)
            {
                cout << queue[i] << " ";

                if(i == rear)
                {
                    break;
                }

                i = (i + 1) % MAX;
            }

            cout << endl;
        }
    }
};

int main()
{
    CircularQueue q;

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