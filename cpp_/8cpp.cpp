#include <iostream>
using namespace std;

#define MAX 5

class Deque
{
    int deque[MAX];
    int front, rear;

public:

    Deque()
    {
        front = -1;
        rear = -1;
    }

    // Insert at Beginning
    void insertFront(int value)
    {
        if((front == 0 && rear == MAX - 1) || (front == rear + 1))
        {
            cout << "Deque Overflow\n";
        }
        else
        {
            // First element
            if(front == -1)
            {
                front = rear = 0;
            }

            // Circular movement
            else if(front == 0)
            {
                front = MAX - 1;
            }
            else
            {
                front--;
            }

            deque[front] = value;

            cout << value << " inserted at beginning\n";
        }
    }

    // Insert at End
    void insertRear(int value)
    {
        if((front == 0 && rear == MAX - 1) || (front == rear + 1))
        {
            cout << "Deque Overflow\n";
        }
        else
        {
            // First element
            if(front == -1)
            {
                front = rear = 0;
            }

            // Circular movement
            else if(rear == MAX - 1)
            {
                rear = 0;
            }
            else
            {
                rear++;
            }

            deque[rear] = value;

            cout << value << " inserted at end\n";
        }
    }

    // Delete from Beginning
    void deleteFront()
    {
        if(front == -1)
        {
            cout << "Deque Underflow\n";
        }
        else
        {
            cout << deque[front] << " deleted from beginning\n";

            // Only one element
            if(front == rear)
            {
                front = rear = -1;
            }
            else if(front == MAX - 1)
            {
                front = 0;
            }
            else
            {
                front++;
            }
        }
    }

    // Delete from End
    void deleteRear()
    {
        if(front == -1)
        {
            cout << "Deque Underflow\n";
        }
        else
        {
            cout << deque[rear] << " deleted from end\n";

            // Only one element
            if(front == rear)
            {
                front = rear = -1;
            }
            else if(rear == 0)
            {
                rear = MAX - 1;
            }
            else
            {
                rear--;
            }
        }
    }

    // Display Deque
    void display()
    {
        if(front == -1)
        {
            cout << "Deque is Empty\n";
        }
        else
        {
            cout << "\nDeque Elements:\n";

            int i = front;

            while(true)
            {
                cout << deque[i] << " ";

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
    Deque d;

    int choice, value;

    while(true)
    {
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete at Beginning";
        cout << "\n4. Delete at End";
        cout << "\n5. Display";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                d.insertFront(value);

                break;

            case 2:

                cout << "Enter value: ";
                cin >> value;

                d.insertRear(value);

                break;

            case 3:

                d.deleteFront();

                break;

            case 4:

                d.deleteRear();

                break;

            case 5:

                d.display();

                break;

            case 6:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}