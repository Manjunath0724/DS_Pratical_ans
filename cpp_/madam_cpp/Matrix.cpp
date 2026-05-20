#include <iostream>
using namespace std;
int main() {
  int r1, c1, r2, c2;

  cout << "Enter rows and columns of Matrix A: ";
  cin >> r1 >> c1;

  int A[r1][c1];

  cout << "Enter elements of Matrix A:\n";
  for (int i = 0; i < r1; i++)
    for (int j = 0; j < c1; j++)
      cin >> A[i][j];

  cout << "Enter rows and columns of Matrix B: ";
  cin >> r2 >> c2;

  int B[r2][c2];

  cout << "Enter elements of Matrix B:\n";
  for (int i = 0; i < r2; i++)
    for (int j = 0; j < c2; j++)
      cin >> B[i][j];

  // Addition
  if (r1 == r2 && c1 == c2) {
    cout << "\nAddition:\n";
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c1; j++)
        cout << A[i][j] + B[i][j] << " ";
      cout << endl;
    }

    // Subtraction
    cout << "\nSubtraction:\n";
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c1; j++)
        cout << A[i][j] - B[i][j] << " ";
      cout << endl;
    }
  }

  // Multiplication
  if (c1 == r2) {
    int mul[r1][c2];

    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
        mul[i][j] = 0;
        for (int k = 0; k < c1; k++)
          mul[i][j] += A[i][k] * B[k][j];
      }
    }

    cout << "\nMultiplication:\n";
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++)
        cout << mul[i][j] << " ";
      cout << endl;
    }
  }

  // Transpose
  cout << "\nTranspose of Matrix A:\n";
  for (int i = 0; i < c1; i++) {
    for (int j = 0; j < r1; j++)
      cout << A[j][i] << " ";
    cout << endl;
  }

  // Symmetric
  if (r1 == c1) {
    bool sym = true;
    for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c1; j++) {
        if (A[i][j] != A[j][i]) {
          sym = false;
          break;
        }
      }
    }

    if (sym)
      cout << "\nMatrix A is Symmetric\n";
    else
      cout << "\nMatrix A is Not Symmetric\n";
  }

  // Upper Triangular
  bool upper = true;
  for (int i = 1; i < r1; i++) {
    for (int j = 0; j < i; j++) {
      if (A[i][j] != 0)
        upper = false;
    }
  }

  if (upper)
    cout << "Matrix A is Upper Triangular\n";

  // Lower Triangular
  bool lower = true;
  for (int i = 0; i < r1; i++) {
    for (int j = i + 1; j < c1; j++) {
      if (A[i][j] != 0)
        lower = false;
    }
  }

  if (lower)
    cout << "Matrix A is Lower Triangular\n";

  return 0;
}
