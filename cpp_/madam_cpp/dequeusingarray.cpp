#include <iostream>
using namespace std;

#define SIZE 5

int dq[SIZE];
int front = -1, rear = -1;

void insertFront(int value) {
  if (front == 0) {
    cout << "No Space\n";
    return;
  }

  if (front == -1) {
    front = rear = 0;
  } else {
    front--;
  }

  dq[front] = value;
}

void insertRear(int value) {
  if (rear == SIZE - 1) {
    cout << "No Space\n";
    return;
  }

  if (front == -1)
    front = rear = 0;
  else
    rear++;

  dq[rear] = value;
}

void deleteFront() {
  if (front == -1) {
    cout << "Deque Empty\n";
    return;
  }

  cout << "Deleted: " << dq[front] << endl;

  if (front == rear)
    front = rear = -1;
  else
    front++;
}

void deleteRear() {
  if (rear == -1) {
    cout << "Deque Empty\n";
    return;
  }

  cout << "Deleted: " << dq[rear] << endl;

  if (front == rear)
    front = rear = -1;
  else
    rear--;
}

void display() {
  for (int i = front; i <= rear; i++)
    cout << dq[i] << " ";

  cout << endl;
}

int main() {
  int choice, value;

  do {
    cout << "\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete "
            "Rear\n5.Display\n6.Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
      cin >> value;
      insertFront(value);
      break;

    case 2:
      cin >> value;
      insertRear(value);
      break;

    case 3:
      deleteFront();
      break;

    case 4:
      deleteRear();
      break;

    case 5:
      display();
      break;
    }

  } while (choice != 6);

  return 0;
}