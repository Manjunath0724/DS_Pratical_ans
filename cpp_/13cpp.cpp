// #include <iostream>
// using namespace std;

// // Node Structure
// class Node
// {
// public:
//     int data;
//     Node *left;
//     Node *right;
// };

// // Binary Tree Class
// class BinaryTree
// {
// public:

//     // Create New Node
//     Node* createNode(int value)
//     {
//         Node *newNode = new Node();

//         newNode->data = value;
//         newNode->left = NULL;
//         newNode->right = NULL;

//         return newNode;
//     }

//     // Preorder Traversal
//     void preorder(Node *root)
//     {
//         if(root != NULL)
//         {
//             cout << root->data << " ";

//             preorder(root->left);

//             preorder(root->right);
//         }
//     }

//     // Inorder Traversal
//     void inorder(Node *root)
//     {
//         if(root != NULL)
//         {
//             inorder(root->left);

//             cout << root->data << " ";

//             inorder(root->right);
//         }
//     }

//     // Postorder Traversal
//     void postorder(Node *root)
//     {
//         if(root != NULL)
//         {
//             postorder(root->left);

//             postorder(root->right);

//             cout << root->data << " ";
//         }
//     }
// };

// int main()
// {
//     BinaryTree tree;

//     // Creating Tree Manually
//     Node *root = tree.createNode(1);

//     root->left = tree.createNode(2);
//     root->right = tree.createNode(3);

//     root->left->left = tree.createNode(4);
//     root->left->right = tree.createNode(5);

//     cout << "\nPreorder Traversal:\n";
//     tree.preorder(root);

//     cout << "\n\nInorder Traversal:\n";
//     tree.inorder(root);

//     cout << "\n\nPostorder Traversal:\n";
//     tree.postorder(root);

//     cout << endl;

//     return 0;
// }


#include<iostream>
#include<stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL, *newnode;

void create();
void insert(struct node *root, struct node *newnode);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

void create()
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->left = NULL;
    newnode->right = NULL;

    cout << "Enter the element: ";
    cin >> newnode->data;

    if(root == NULL)
    {
        root = newnode;
    }
    else
    {
        insert(root, newnode);
    }
}

void insert(struct node *root, struct node *newnode)
{
    char ch;

    cout << "Do you want to add left(l) or right(r): ";
    cin >> ch;

    switch(ch)
    {
        case 'l':

            if(root->left == NULL)
            {
                root->left = newnode;
            }
            else
            {
                insert(root->left, newnode);
            }

            break;

        case 'r':

            if(root->right == NULL)
            {
                root->right = newnode;
            }
            else
            {
                insert(root->right, newnode);
            }

            break;

        default:

            cout << "Invalid Choice";
    }
}

// Inorder Traversal
void inorder(struct node *temp)
{
    if(temp != NULL)
    {
        inorder(temp->left);

        cout << temp->data << " ";

        inorder(temp->right);
    }
}

// Preorder Traversal
void preorder(struct node *temp)
{
    if(temp != NULL)
    {
        cout << temp->data << " ";

        preorder(temp->left);

        preorder(temp->right);
    }
}

// Postorder Traversal
void postorder(struct node *temp)
{
    if(temp != NULL)
    {
        postorder(temp->left);

        postorder(temp->right);

        cout << temp->data << " ";
    }
}

int main()
{
    int c;

    do
    {
        cout << "\n1. Create";
        cout << "\n2. Inorder";
        cout << "\n3. Preorder";
        cout << "\n4. Postorder";
        cout << "\n5. Exit";

        cout << "\nEnter your choice: ";
        cin >> c;

        switch(c)
        {
            case 1:

                create();
                break;

            case 2:

                cout << "\nInorder Traversal:\n";

                inorder(root);

                break;

            case 3:

                cout << "\nPreorder Traversal:\n";

                preorder(root);

                break;

            case 4:

                cout << "\nPostorder Traversal:\n";

                postorder(root);

                break;

            case 5:

                exit(0);

            default:

                cout << "Invalid Choice";
        }

    } while(c != 5);

    return 0;
}