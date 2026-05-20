#include <iostream>
using namespace std;

int main() {
  int size;

  cout << "Enter hash table size: ";
  cin >> size;

  int hash[size];

  for (int i = 0; i < size; i++)
    hash[i] = -1;

  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int value;
    cin >> value;

    int index = value % size;

    while (hash[index] != -1)
      index = (index + 1) % size;

    hash[index] = value;
  }

  cout << "\nHash Table:\n";

  for (int i = 0; i < size; i++)
    cout << i << " --> " << hash[i] << endl;

  return 0;
}