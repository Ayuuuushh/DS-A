#include <bits/stdc++.h>
using namespace std;
int BinarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
        int mid = (start + end) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }
    return -1;
}
int main()
{
    int odd[5] = {1, 2, 35, 44, 66};
    int even[6] = {1, 23, 45, 66, 77};
    cout << BinarySearch(odd, 5, 44);
    return 0;
}