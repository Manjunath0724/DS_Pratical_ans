#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *head = NULL;

void display() {

  if (head == NULL)
    return;

  Node *temp = head;

  do {
    cout << temp->data << " ";
    temp = temp->next;

  } while (temp != head);

  cout << endl;
}

void insertPosition(int value, int pos) {

  Node *newNode = new Node();
  newNode->data = value;

  if (pos == 1) {

    if (head == NULL) {

      head = newNode;
      newNode->next = head;
      return;
    }

    Node *temp = head;

    while (temp->next != head)
      temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    return;
  }

  Node *temp = head;

  for (int i = 1; i < pos - 1; i++)
    temp = temp->next;

  newNode->next = temp->next;
  temp->next = newNode;
}

void deletePosition(int pos) {

  if (head == NULL)
    return;

  Node *temp = head;

  if (pos == 1) {

    while (temp->next != head)
      temp = temp->next;

    Node *del = head;

    if (head->next == head) {
      head = NULL;
    } else {
      temp->next = head->next;
      head = head->next;
    }

    delete del;
    return;
  }

  Node *prev = NULL;

  temp = head;

  for (int i = 1; i < pos; i++) {
    prev = temp;
    temp = temp->next;
  }

  prev->next = temp->next;

  delete temp;
}

int main() {

  int choice, value, pos;

  do {

    cout << "\n1.Display\n2.Insert Position\n3.Delete Position\n4.Exit\n";

    cin >> choice;

    switch (choice) {

    case 1:
      display();
      break;

    case 2:
      cin >> value >> pos;
      insertPosition(value, pos);
      break;

    case 3:
      cin >> pos;
      deletePosition(pos);
      break;
    }

  } while (choice != 4);

  return 0;
}