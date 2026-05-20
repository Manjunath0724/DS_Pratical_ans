#include <iostream>
using namespace std;

#define MAX 10

class PriorityQueue
{
    int queue[MAX];
    int priority[MAX];
    int rear;

public:

    PriorityQueue()
    {
        rear = -1;
    }

    // Insert Element
    void insert(int value, int p)
    {
        if(rear == MAX - 1)
        {
            cout << "Priority Queue Overflow\n";
        }
        else
        {
            rear++;

            queue[rear] = value;
            priority[rear] = p;

            cout << value << " inserted with priority " << p << endl;
        }
    }

    // Delete Highest Priority (Ascending)
    void deleteAscending()
    {
        if(rear == -1)
        {
            cout << "Priority Queue is Empty\n";

            return;
        }

        int index = 0;

        // Smaller number = Higher priority
        for(int i = 1; i <= rear; i++)
        {
            if(priority[i] < priority[index])
            {
                index = i;
            }
        }

        cout << queue[index] << " deleted (Highest Priority)\n";

        // Shift elements
        for(int i = index; i < rear; i++)
        {
            queue[i] = queue[i + 1];
            priority[i] = priority[i + 1];
        }

        rear--;
    }

    // Delete Highest Priority (Descending)
    void deleteDescending()
    {
        if(rear == -1)
        {
            cout << "Priority Queue is Empty\n";

            return;
        }

        int index = 0;

        // Larger number = Higher priority
        for(int i = 1; i <= rear; i++)
        {
            if(priority[i] > priority[index])
            {
                index = i;
            }
        }

        cout << queue[index] << " deleted (Highest Priority)\n";

        // Shift elements
        for(int i = index; i < rear; i++)
        {
            queue[i] = queue[i + 1];
            priority[i] = priority[i + 1];
        }

        rear--;
    }

    // Display Queue
    void display()
    {
        if(rear == -1)
        {
            cout << "Priority Queue is Empty\n";
        }
        else
        {
            cout << "\nElements with Priority:\n";

            for(int i = 0; i <= rear; i++)
            {
                cout << "Element: " << queue[i]
                     << "  Priority: " << priority[i] << endl;
            }   
        }
    }
};

int main()
{
    PriorityQueue pq;

    int choice, value, p;

    while(true)
    {
        cout << "\n1. Insert";
        cout << "\n2. Delete Ascending Priority";
        cout << "\n3. Delete Descending Priority";
        cout << "\n4. Display";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                cout << "Enter priority: ";
                cin >> p;

                pq.insert(value, p);

                break;

            case 2:

                pq.deleteAscending();

                break;

            case 3:

                pq.deleteDescending();

                break;

            case 4:

                pq.display();

                break;

            case 5:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}