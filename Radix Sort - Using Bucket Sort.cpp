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

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    int place = 1;

    while (max / place > 0)
    {
        int bucket[10][100];
        int count[10] = {0};

        // Put elements into buckets
        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / place) % 10;

            bucket[digit][count[digit]] = arr[i];
            count[digit]++;
        }

        // Collect elements from buckets
        int k = 0;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < count[i]; j++)
            {
                arr[k] = bucket[i][j];
                k++;
            }
        }

        place = place * 10;
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};

    int n = 8;

    cout << "Before Sorting: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    radixSort(arr, n);

    cout << "\nAfter Sorting: ";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}