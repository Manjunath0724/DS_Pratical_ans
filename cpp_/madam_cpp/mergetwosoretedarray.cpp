#include <iostream>
using namespace std;

int main() {
  int n1, n2;

  cout << "Enter size of first array: ";
  cin >> n1;

  int a[n1];

  cout << "Enter sorted elements:\n";
  for (int i = 0; i < n1; i++)
    cin >> a[i];

  cout << "Enter size of second array: ";
  cin >> n2;

  int b[n2];

  cout << "Enter sorted elements:\n";
  for (int i = 0; i < n2; i++)
    cin >> b[i];

  int c[n1 + n2];

  int i = 0, j = 0, k = 0;

  while (i < n1 && j < n2) {
    if (a[i] < b[j])
      c[k++] = a[i++];
    else
      c[k++] = b[j++];
  }

  while (i < n1)
    c[k++] = a[i++];

  while (j < n2)
    c[k++] = b[j++];

  cout << "Merged Array:\n";

  for (int x = 0; x < n1 + n2; x++)
    cout << c[x] << " ";

  return 0;
}