#include <bits/stdc++.h>
using namespace std;

void insertionSort(int *arr, int end)
{

    if (1 >= end)
        return;
    

    insertionSort(arr, end - 1);

    int last = arr[end - 1];
    int j = end - 2;

    while (j > 0 && arr[j] > last)
    {
        swap(arr[j + 1], arr[j]);
        j--;
    }
    arr[j + 1] = last;

     for (int i = 0; i < end; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[5] = {4, 3, 5, 6, 8};

    int size = 5;

    // int size = arr.size();
    // cout << size;

    // Using Loop
    // cout << "Using Loop" << endl;
    // insertionSort(arr, 5);
    // cout << endl
    //      << endl;

    // Using recursion
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Using Recursion" << endl;

    insertionSort(arr, 5);

   
    return 0;
}