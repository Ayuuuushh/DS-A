#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{

    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    int pivotIndex = s + cnt;
    swap(arr[pivotIndex], arr[s]);

    // left & right systemmm...
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        if (arr[i] <= arr[pivotIndex])
        {
            i++;
        }

        if (arr[j] > arr[pivotIndex])
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e)
{

    if (s >= e)
        return;
    // partition karo
    int p = partition(arr, s, e);

    // left part sort
    quickSort(arr, s, p - 1);

    // right part sort
    quickSort(arr, p + 1, e);
}
int main()
{
    int arr[9] = {4, 2, 5, 2, 5, 6, 7, 4, 3};
    int n = 9;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}