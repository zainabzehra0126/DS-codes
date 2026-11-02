#include <iostream>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

void countingSort(int arr[], int n, int place)
{
    int output[100];
    int count[10] = {0};

    // Count occurrences
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Convert count into positions
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / place) % 10;

        output[count[digit] - 1] = arr[i];

        count[digit]--;
    }

    // Copy back
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int place = 1; max / place > 0; place = place * 10)
    {
        countingSort(arr, n, place);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

    int n = 8;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    radixSort(arr, n);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}