#include <bits/stdc++.h>
using namespace std;
double median(int arr1[], int arr2[], int m, int n)
{
    int k = m + n - 1;
    int arr3[k];
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
            arr3[k--] = arr1[i--];
        else
        {
            arr3[k--] = arr2[j--];
        }
    }

    while (i >= 0)
    {
        arr3[k--] = arr1[i--];
    }
    while (j >= 0)
    {
        arr3[k--] = arr1[i--];
    }
    // int s = 0;
    // // int e = arr3.size();
    // int mid = (s + e) / 2;
    for (int l = 0; l < k; l++)
    {
        cout << arr3[l] << " ";
    }
    cout << endl;
    // double median = (arr3[mid] + arr3[mid + 1]) / 2.0000;
    // double median2 = arr3[mid];
    // // if (arr3.size() % 2 == 0)
    // //     cout << median;
    // // else
    // // {
    // //     cout<< median2;
    // // }
    return 1.000;
}
int main()
{
    int arr1[2] = {1, 2};
    int arr2[2] = {3, 4};
    cout << endl
         << median(arr1, arr2, 2, 2);
         int m = 2, n = 2;
    int k = m + n - 1;
    int arr3[k];
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (arr1[i] > arr2[j])
            arr3[k--] = arr1[i--];
        else
        {
            arr3[k--] = arr2[j--];
        }
    }

    while (i >= 0)
    {
        arr3[k--] = arr1[i--];
    }
    while (j >= 0)
    {
        arr3[k--] = arr1[i--];
    }
    // int s = 0;
    // // int e = arr3.size();
    // int mid = (s + e) / 2;
    for (int l = 0; l < k; l++)
    {
        cout << arr3[l] << " ";
    }
    cout << endl;

    return 0;
}