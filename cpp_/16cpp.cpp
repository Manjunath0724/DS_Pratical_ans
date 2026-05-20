#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

// Display Circular Linked List
void display()
{
    if(head == NULL)
    {
        cout << "Circular Linked List is Empty\n";
    }
    else
    {
        Node *temp = head;

        cout << "\nCircular Linked List:\n";

        do
        {
            cout << temp->data << " ";

            temp = temp->next;

        } while(temp != head);

        cout << endl;
    }
}

// Insert at Given Position
void insertPosition(int value, int pos)
{
    Node *newNode = new Node();

    newNode->data = value;

    // Insert at beginning
    if(pos == 1)
    {
        if(head == NULL)
        {
            head = newNode;

            newNode->next = head;
        }
        else
        {
            Node *temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            newNode->next = head;

            temp->next = newNode;

            head = newNode;
        }

        cout << value << " inserted at position " << pos << endl;

        return;
    }

    Node *temp = head;

    for(int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;

    temp->next = newNode;

    cout << value << " inserted at position " << pos << endl;
}

// Delete from Given Position
void deletePosition(int pos)
{
    if(head == NULL)
    {
        cout << "List is Empty\n";

        return;
    }

    Node *temp = head;

    // Delete first node
    if(pos == 1)
    {
        if(head->next == head)
        {
            delete head;

            head = NULL;
        }
        else
        {
            Node *last = head;

            while(last->next != head)
            {
                last = last->next;
            }

            head = head->next;

            last->next = head;

            delete temp;
        }

        cout << "Node deleted from position " << pos << endl;

        return;
    }

    Node *prev = NULL;

    for(int i = 1; i < pos; i++)
    {
        prev = temp;

        temp = temp->next;
    }

    prev->next = temp->next;

    delete temp;

    cout << "Node deleted from position " << pos << endl;
}

int main()
{
    int choice, value, pos;

    while(true)
    {
        cout << "\n1. Display";
        cout << "\n2. Insert at Position";
        cout << "\n3. Delete from Position";
        cout << "\n4. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                display();
                break;

            case 2:

                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: "; 
                cin >> pos;

                insertPosition(value, pos);

                break;

            case 3:

                cout << "Enter position to delete: ";
                cin >> pos;

                deletePosition(pos);

                break;

            case 4:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}