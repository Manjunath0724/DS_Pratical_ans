#include <iostream>
using namespace std;

int main() {
  int n, choice;

  cout << "Enter number of elements: ";
  cin >> n;

  int arr[n];

  cout << "Enter elements:\n";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\n1. Ascending Priority\n2. Descending Priority\n";
  cin >> choice;

  // Sorting
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {

      if (choice == 1) {
        if (arr[j] > arr[j + 1]) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      } else {
        if (arr[j] < arr[j + 1]) {
          int temp = arr[j];
          arr[j] = arr[j + 1];
          arr[j + 1] = temp;
        }
      }
    }
  }

  cout << "\nPriority Queue:\n";

  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}