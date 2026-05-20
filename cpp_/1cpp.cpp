#include <iostream>
using namespace std;

class Matrix
{
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2, i, j, k;

public:
    // Input Matrix A
    void inputA()
    {
        cout << "Enter rows and columns of Matrix A: ";
        cin >> r1 >> c1;

        cout << "Enter elements of Matrix A:\n";
        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                cin >> a[i][j];
            }
        }
    }

    // Input Matrix B
    void inputB()
    {
        cout << "Enter rows and columns of Matrix B: ";
        cin >> r2 >> c2;

        cout << "Enter elements of Matrix B:\n";
        for (i = 0; i < r2; i++)
        {
            for (j = 0; j < c2; j++)
            {
                cin >> b[i][j];
            }
        }
    }

    // Display Matrix
    void display(int x[10][10], int r, int c)
    {
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                cout << x[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Addition
    void addition()
    {
        if (r1 == r2 && c1 == c2)
        {
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c1; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }

            cout << "\nAddition of Matrix:\n";
            display(c, r1, c1);
        }
        else
        {
            cout << "Addition not possible\n";
        }
    }

    // Subtraction
    void subtraction()
    {
        if (r1 == r2 && c1 == c2)
        {
            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c1; j++)
                {
                    c[i][j] = a[i][j] - b[i][j];
                }
            }

            cout << "\nSubtraction of Matrix:\n";
            display(c, r1, c1);
        }
        else
        {
            cout << "Subtraction not possible\n";
        }
    }

    // Multiplication
    void multiplication()
    {
        if (c1 == r2)
        {

            for (i = 0; i < r1; i++)
            {
                for (j = 0; j < c2; j++)
                {
                    c[i][j] = 0;

                    for (k = 0; k < c1; k++)
                    {
                        c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
                    }
                }
            }

            cout << "\nMultiplication of Matrix:\n";
            display(c, r1, c2);
        }
        else
        {
            cout << "Multiplication not possible\n";
        }
    }

    // Transpose
    void transpose()
    {
        cout << "\nTranspose of Matrix A:\n";

        for (i = 0; i < c1; i++)
        {
            for (j = 0; j < r1; j++)
            {
                cout << a[j][i] << " ";
            }
            cout << endl;
        }
    }

    // Symmetric Matrix Check
    void symmetric()
    {
        if (r1 != c1)
        {
            cout << "Matrix is not symmetric\n";
            return;
        }

        int flag = 1;

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {
                if (a[i][j] != a[j][i])
                {
                    flag = 0;
                    break;
                }
            }
        }

        if (flag == 1)
            cout << "Matrix is Symmetric\n";
        else
            cout << "Matrix is Not Symmetric\n";
    }

    // Lower Triangular Matrix
    void lowerTriangular()
    {
        cout << "\nLower Triangular Matrix:\n";

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {

                if (i >= j)
                    cout << a[i][j] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }

    // Upper Triangular Matrix
    void upperTriangular()
    {
        cout << "\nUpper Triangular Matrix:\n";

        for (i = 0; i < r1; i++)
        {
            for (j = 0; j < c1; j++)
            {

                if (i <= j)
                    cout << a[i][j] << " ";
                else
                    cout << "0 ";
            }
            cout << endl;
        }
    }
};

int main()
{

    Matrix m;
    int c;
    m.inputA();
    m.inputB();
    cout << "Enter your choice:\n"
         << "1. addition\n"
         << "2. subtraction\n"
         << "3. multiplication\n"
         << "4. transpose\n"
         << "5. symmetric\n"
         << "6. lower triangular\n"
         << "7. upper triangular\n";
    cin >> c;

    switch (c)
    {
    case 1:
        m.addition();
        break;
    case 2:
        m.subtraction();
        break;
    case 3:
        m.multiplication();
        break;
    case 4:
        m.transpose();
        break;
    case 5:
        m.symmetric();
        break;
    case 6:
        m.lowerTriangular();
        break;
    case 7:
        m.upperTriangular();
        break;
    default:
        cout << "Invalid choice\n";
        break;
    }

    return 0;
}