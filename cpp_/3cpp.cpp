#include <iostream>
using namespace std;

// Display Array
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nBubble Sorted Array:\n";
    display(arr, n);
}

// Insertion Sort
void insertionSort(int arr[], int n)
{
    int key, j;

    for (int i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "\nInsertion Sorted Array:\n";
    display(arr, n);
}

// Selection Sort
void selectionSort(int arr[], int n)
{
    int minIndex;

    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }

    cout << "\nSelection Sorted Array:\n";
    display(arr, n);
}

// Merge Function
void merge(int arr[], int low, int mid, int high)
{
    int temp[100];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
}

// Merge Sort
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Partition Function for Quick Sort
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Heapify Function
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        // Manual Swap using temp
        int temp;

        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n)
{
    // Build Heap
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // Extract Elements
    for (int i = n - 1; i >= 0; i--)
    {
        // Manual Swap using temp
        int temp;

        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }

    cout << "\nHeap Sorted Array:\n";

    display(arr, n);
}

int main()
{
    int arr[100], n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "\n1. Bubble Sort";
    cout << "\n2. Insertion Sort";
    cout << "\n3. Selection Sort";
    cout << "\n4. Merge Sort";
    cout << "\n5. Quick Sort";
    cout << "\n6. Heap Sort";

    cout << "\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        bubbleSort(arr, n);
        break;

    case 2:
        insertionSort(arr, n);
        break;

    case 3:
        selectionSort(arr, n);
        break;

    case 4:
        mergeSort(arr, 0, n - 1);

        cout << "\nMerge Sorted Array:\n";
        display(arr, n);
        break;

    case 5:
        quickSort(arr, 0, n - 1);

        cout << "\nQuick Sorted Array:\n";
        display(arr, n);
        break;

    case 6:
        heapSort(arr, n);
        break;

    default:
        cout << "Invalid Choice";
    }

    return 0;
}