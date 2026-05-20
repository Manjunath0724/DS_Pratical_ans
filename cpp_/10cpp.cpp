#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

Node *head = NULL;

// Display List
void display()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";
    }
    else
    {
        Node *temp = head;

        cout << "\nLinked List:\n";

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

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;

        temp->next = NULL;

        cout << "Last node deleted\n";
    }
}

// Insert at Beginning
void insertBeginning(int value)
{
    Node *newNode = new Node();

    newNode->data = value;

    newNode->next = head;

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
        newNode->next = head;

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

        temp->next = newNode;
    }

    cout << value << " inserted at position " << pos << endl;
}

// Count Nodes
void countNodes()
{
    int count = 0;

    Node *temp = head;

    while(temp != NULL)
    {
        count++;

        temp = temp->next;
    }

    cout << "Number of nodes: " << count << endl;
}

// Sort Linked List
void sortList()
{
    if(head == NULL)
    {
        cout << "List is Empty\n";

        return;
    }

    Node *i, *j;

    for(i = head; i != NULL; i = i->next)
    {
        for(j = i->next; j != NULL; j = j->next)
        {
            if(i->data > j->data)
            {
                int temp = i->data;

                i->data = j->data;

                j->data = temp;
            }
        }
    }

    cout << "List Sorted Successfully\n";
}

// Insert in Sorted List
void insertSorted(int value)
{
    Node *newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL || value < head->data)
    {
        newNode->next = head;

        head = newNode;
    }
    else
    {
        Node *temp = head;

        while(temp->next != NULL && temp->next->data < value)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;

        temp->next = newNode;
    }

    cout << value << " inserted into sorted list\n";
}

int main()
{
    int choice, value, pos;

    while(true)
    {
        cout << "\n1. Display";
        cout << "\n2. Insert at End";
        cout << "\n3. Delete from End";
        cout << "\n4. Insert at Specific Position";
        cout << "\n5. Count Nodes";
        cout << "\n6. Insert at Beginning";
        cout << "\n7. Delete from Beginning";
        cout << "\n8. Sort List";
        cout << "\n9. Insert in Sorted List";
        cout << "\n10. Exit";

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

                cout << "Enter position: ";
                cin >> pos;

                insertPosition(value, pos);

                break;

            case 5:

                countNodes();

                break;

            case 6:

                cout << "Enter value: ";
                cin >> value;

                insertBeginning(value);

                break;

            case 7:

                deleteBeginning();

                break;

            case 8:

                sortList();

                break;

            case 9:

                cout << "Enter value: ";
                cin >> value;

                insertSorted(value);

                break;

            case 10:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}