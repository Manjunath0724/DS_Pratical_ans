#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

void display()
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insertEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void insertBeginning(int value)
{
    Node *newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

void deleteBeginning()
{
    if (head == NULL)
        return;

    Node *temp = head;

    head = head->next;

    delete temp;
}

void deleteEnd()
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
        temp = temp->next;

    delete temp->next;
    temp->next = NULL;
}

void countNodes()
{
    int count = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total Nodes: " << count << endl;
}

void insertAtPosition(int value, int pos)
{
    Node *newNode = new Node();
    newNode->data = value;

    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
        return;

    newNode->next = temp->next;
    temp->next = newNode;
}

void sortList()
{
    Node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {

            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void insertSorted(int value)
{
    Node *newNode = new Node();

    newNode->data = value;

    if (head == NULL || head->data >= value)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;

    while (temp->next != NULL && temp->next->data < value)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{

    int choice, value, pos;

    do
    {
        cout << "\n1.Display\n2.Insert End\n3.Delete End\n4.Insert Position\n";
        cout << "5.Count Nodes\n6.Insert Beginning\n7.Delete Beginning\n";
        cout << "8.Sort List\n9.Insert Sorted\n10.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            display();
            break;

        case 2:
            cin >> value;
            insertEnd(value);
            break;

        case 3:
            deleteEnd();
            break;

        case 4:
            cin >> value >> pos;
            insertAtPosition(value, pos);
            break;

        case 5:
            countNodes();
            break;

        case 6:
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
            cin >> value;
            insertSorted(value);
            break;
        }

    } while (choice != 10);

    return 0;
}