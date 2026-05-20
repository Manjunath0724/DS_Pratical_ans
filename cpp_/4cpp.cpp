#include <iostream>
using namespace std;

int main()
{
    int arr1[100], arr2[100], merged[200];
    int n1, n2;

    cout << "Enter size of first sorted array: ";
    cin >> n1;

    cout << "Enter elements of first sorted array:\n";

    for(int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter size of second sorted array: ";
    cin >> n2;

    cout << "Enter elements of second sorted array:\n";

    for(int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    // Merge arrays
    while(i < n1 && j < n2)
    {
        if(arr1[i] < arr2[j])
        {
            merged[k] = arr1[i];
            i++;
        }
        else
        {
            merged[k] = arr2[j];
            j++;
        }

        k++;
    }

    // Remaining elements of arr1
    while(i < n1)
    {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    // Remaining elements of arr2
    while(j < n2)
    {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    cout << "\nMerged Sorted Array:\n";

    for(i = 0; i < k; i++)
    {
        cout << merged[i] << " ";
    }

    return 0;
}