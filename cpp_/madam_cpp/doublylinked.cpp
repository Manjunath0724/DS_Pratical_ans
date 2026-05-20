#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *prev, *next;
};

Node *head = NULL;

void display() {
  Node *temp = head;

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

void insertEnd(int value) {
  Node *newNode = new Node();

  newNode->data = value;
  newNode->next = NULL;

  if (head == NULL) {
    newNode->prev = NULL;
    head = newNode;
    return;
  }

  Node *temp = head;

  while (temp->next != NULL)
    temp = temp->next;

  temp->next = newNode;
  newNode->prev = temp;
}

void insertBeginning(int value) {
  Node *newNode = new Node();

  newNode->data = value;
  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL)
    head->prev = newNode;

  head = newNode;
}

void deleteBeginning() {

  if (head == NULL)
    return;

  Node *temp = head;

  head = head->next;

  if (head != NULL)
    head->prev = NULL;

  delete temp;
}

void deleteEnd() {

  if (head == NULL)
    return;

  Node *temp = head;

  while (temp->next != NULL)
    temp = temp->next;

  if (temp->prev != NULL)
    temp->prev->next = NULL;
  else
    head = NULL;

  delete temp;
}

int main() {

  int choice, value;

  do {

    cout << "\n1.Display\n2.Insert End\n3.Delete End\n";
    cout << "4.Insert Beginning\n5.Delete Beginning\n6.Exit\n";

    cin >> choice;

    switch (choice) {

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
      cin >> value;
      insertBeginning(value);
      break;

    case 5:
      deleteBeginning();
      break;
    }

  } while (choice != 6);

  return 0;
}