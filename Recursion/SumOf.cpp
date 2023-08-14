#include <bits/stdc++.h>
using namespace std;

int Sumof(int *arr, int size)
{
    // base case
    if (size == 0)
        return 0;
    if (size == 1)
        return arr[0];

    //recursive call
    // int remainingPart = Sumof(arr + 1, size - 1);
    // // processing
    // int sum = arr[0] + remainingPart;
        int sum = 0;
    return sum = arr[0] + Sumof(arr + 1, size - 1);
}
int main()
{

    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {

        cin >> arr[i];
    }

    int ans = Sumof(arr, size);
    cout << ans;
    return 0;
}