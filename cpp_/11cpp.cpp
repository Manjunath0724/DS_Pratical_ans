#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;

// Display List
void display()
{
    if(head == NULL)
    {
        cout << "Doubly Linked List is Empty\n";
    }
    else
    {
        Node *temp = head;

        cout << "\nDoubly Linked List:\n";

        while(temp != NULL)
        {
            cout << temp->data << " ";

            temp = temp->next;
        }

        cout << endl;
    }
}

// Insert at End
void insertEnd(int value)
{
    Node *newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        newNode->prev = temp;
    }

    cout << value << " inserted at end\n";
}

// Delete from End
void deleteEnd()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
    }
    else if(head->next == NULL)
    {
        delete head;

        head = NULL;

        cout << "Last node deleted\n";
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->prev->next = NULL;

        delete temp;

        cout << "Last node deleted\n";
    }
}

// Insert at Beginning
void insertBeginning(int value)
{
    Node *newNode = new Node();

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;

    cout << value << " inserted at beginning\n";
}

// Delete from Beginning
void deleteBeginning()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
    }
    else
    {
        Node *temp = head;

        head = head->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;

        cout << "First node deleted\n";
    }
}

// Insert at Specific Position
void insertPosition(int value, int pos)
{
    Node *newNode = new Node();

    newNode->data = value;

    if(pos == 1)
    {
        newNode->prev = NULL;
        newNode->next = head;

        if(head != NULL)
        {
            head->prev = newNode;
        }

        head = newNode;
    }
    else
    {
        Node *temp = head;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if(temp->next != NULL)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    cout << value << " inserted at position " << pos << endl;
}

// Delete from Specific Position
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
        head = head->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }

        delete temp;

        cout << "Node deleted from position " << pos << endl;

        return;
    }

    for(int i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    temp->prev->next = temp->next;

    if(temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;

    cout << "Node deleted from position " << pos << endl;
}

int main()
{
    int choice, value, pos;

    while(true)
    {
        cout << "\n1. Display";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete from End";
        cout << "\n4. Insert at Beginning";
        cout << "\n5. Delete from Beginning";
        cout << "\n6. Insert at Specific Position";
        cout << "\n7. Delete from Specific Position";
        cout << "\n8. Exit";

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

                insertEnd(value);

                break;

            case 3:

                deleteEnd();

                break;

            case 4:

                cout << "Enter value: ";
                cin >> value;

                insertBeginning(value);

                break;

            case 5:

                deleteBeginning();

                break;

            case 6:

                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: ";
                cin >> pos;

                insertPosition(value, pos);

                break;

            case 7:

                cout << "Enter position to delete: ";
                cin >> pos;

                deletePosition(pos);

                break;

            case 8:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}