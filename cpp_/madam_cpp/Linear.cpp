#include <iostream>
using namespace std;

int main() {
  int n, key;

  cout << "Enter size: ";
  cin >> n;

  int arr[n];

  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Enter element to search: ";
  cin >> key;

  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      cout << "Element found at position " << i + 1;
      return 0;
    }
  }

  cout << "Element not found";
}