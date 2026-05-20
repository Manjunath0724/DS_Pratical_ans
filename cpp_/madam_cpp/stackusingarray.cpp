#include <iostream>
using namespace std;

#define MAX 100

int stackArr[MAX];
int top = -1;

void push(int value) {
  if (top == MAX - 1)
    cout << "Stack Overflow\n";
  else {
    top++;
    stackArr[top] = value;
  }
}

void pop() {
  if (top == -1)
    cout << "Stack Underflow\n";
  else {
    cout << "Deleted: " << stackArr[top] << endl;
    top--;
  }
}

void display() {
  for (int i = top; i >= 0; i--)
    cout << stackArr[i] << " ";
  cout << endl;
}

int main() {
  int choice, value;

  do {
    cout << "\n1.Push 2.Pop 3.Display 4.Exit\n";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value: ";
      cin >> value;
      push(value);
      break;

    case 2:
      pop();
      break;

    case 3:
      display();
      break;
    }

  } while (choice != 4);

  return 0;
}