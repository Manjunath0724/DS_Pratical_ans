#include <iostream>
using namespace std;

// LINEAR SEARCH
void linearSearch(int arr[], int n, int key)
{
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1 << endl;
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "Element not found\n";
    }
}

// BINARY SEARCH
void binarySearch(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int found = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        //mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            cout << "Element found at position " << mid + 1 << endl;
            found = 1;
            break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if (found == 0)
    {
        cout << "Element not found\n";
    }
}

// HASHING WITH LINEAR PROBING
void hashingLinearProbing()
{

    int hashTable[10];
    int key, index;

    // Initialize table with -1
    for (int i = 0; i < 10; i++)
    {
        hashTable[i] = -1;
    }

    int n;
    cout << "\nEnter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";

    for (int i = 0; i < n; i++)
    {

        cin >> key;

        index = key % 10;

        // Linear Probing
        while (hashTable[index] != -1)
        {
            index = (index + 1) % 10;
        }

        hashTable[index] = key;
    }

    cout << "\nHash Table:\n";

    for (int i = 0; i < 10; i++)
    {
        cout << i << " --> " << hashTable[i] << endl;
    }
}

int main()
{

    int arr[100], n, key, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n1. Linear Search";
    cout << "\n2. Binary Search";
    cout << "\n3. Hashing (Linear Probing)";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        cout << "Enter element to search: ";
        cin >> key;

        linearSearch(arr, n, key);
        break;

    case 2:
        cout << "Enter element to search: ";
        cin >> key;

        cout << "Note: Array must be sorted for Binary Search\n";

        binarySearch(arr, n, key);
        break;

    case 3:
        hashingLinearProbing();
        break;

    default:
        cout << "Invalid Choice";
    }

    return 0;
}