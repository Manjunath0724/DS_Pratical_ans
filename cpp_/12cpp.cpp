#include <iostream>
using namespace std;

// Node Structure
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};

// Binary Search Tree Class
class BST
{
    Node *root;

public:

    BST()
    {
        root = NULL;
    }

    // Insert Function
    Node* insert(Node *root, int value)
    {
        // Create new node
        if(root == NULL)
        {
            Node *newNode = new Node();

            newNode->data = value;
            newNode->left = NULL;
            newNode->right = NULL;

            return newNode;
        }

        // Insert in left subtree
        if(value < root->data)
        {
            root->left = insert(root->left, value);
        }

        // Insert in right subtree
        else
        {
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Display Inorder
    void inorder(Node *root)
    {
        if(root != NULL)
        {
            inorder(root->left);

            cout << root->data << " ";

            inorder(root->right);
        }
    }

    // Wrapper Function for Insert
    void insertValue(int value)
    {
        root = insert(root, value);
    }

    // Wrapper Function for Display
    void display()
    {
        cout << "\nBST Elements (Inorder Traversal):\n";

        inorder(root);

        cout << endl;
    }
};

int main()
{
    BST tree;

    int choice, value;

    while(true)
    {
        cout << "\n1. Insert";
        cout << "\n2. Display";
        cout << "\n3. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                cout << "Enter value: ";
                cin >> value;

                tree.insertValue(value);

                break;

            case 2:

                tree.display();

                break;

            case 3:

                return 0;

            default:

                cout << "Invalid Choice";
        }
    }

    return 0;
}