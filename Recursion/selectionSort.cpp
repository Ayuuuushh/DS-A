
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size)
{
    int minIndex;
    for (int i = 0; i < size; i++)
    {
        minIndex = i;

        for (int j = i; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void selectionSort(int arr[], int start, int end)
{
    for (int i = 0; i < end; i++)
    {
        cout << arr[i] << " ";
    }

    // base case
    if (start <= end)
        return;

    // processing
    int minIndex = start;
    for (int j = start + 1; j < end; j++)
    {
        if (arr[j] < arr[minIndex])
            minIndex = j;
    }
    swap(arr[minIndex], arr[start]);

    // recursive Call

    selectionSort(arr, start + 1, end - 1);
}
int main()
{
    int arr[5] = {4, 3, 5, 6, 8};

    int size = 5;

    // int size = arr.size();
    // cout << size;

    // Using Loop
    cout << "Using Loop" << endl;
    selectionSort(arr, 5);
    cout << endl
         << endl;

    // Using recursion
    cout << "Using Recursion" << endl;
    selectionSort(arr, 0, 5);

    return 0;
}
