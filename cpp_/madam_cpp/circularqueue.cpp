#include <iostream>
using namespace std;

#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

void insert(int value) {
  if ((rear + 1) % SIZE == front) {
    cout << "Queue Full\n";
    return;
  }

  if (front == -1)
    front = 0;

  rear = (rear + 1) % SIZE;
  cq[rear] = value;
}

void deleteElement() {
  if (front == -1) {
    cout << "Queue Empty\n";
    return;
  }

  cout << "Deleted: " << cq[front] << endl;

  if (front == rear)
    front = rear = -1;
  else
    front = (front + 1) % SIZE;
}

void display() {
  if (front == -1) {
    cout << "Queue Empty\n";
    return;
  }

  int i = front;

  while (i != rear) {
    cout << cq[i] << " ";
    i = (i + 1) % SIZE;
  }

  cout << cq[rear] << endl;
}

int main() {
  int choice, value;

  do {
    cout << "\n1.Insert 2.Delete 3.Display 4.Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
      cin >> value;
      insert(value);
      break;

    case 2:
      deleteElement();
      break;

    case 3:
      display();
      break;
    }

  } while (choice != 4);

  return 0;
}