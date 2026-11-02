#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int middle = (low + high) / 2;
    int pivot = arr[middle];

    int i = low;
    int j = high;

    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i <= j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        }
    }

    return i;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = partition(arr, low, high);

        quickSort(arr, low, index - 1);
        quickSort(arr, index, high);
    }
}

int main()
{
    int arr[] = {8, 3, 1, 7, 0, 10, 2};

    int n = 7;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}