#include <bits/stdc++.h>
using namespace std;

bool LinearSearch(int *arr, int size, int key)
{

    // base case
    if (size == 0)
        return false;

    if (arr[0] == key)
    {
        return true;
    }
    else
    {
        bool check = LinearSearch(arr + 1, size - 1, key);
        return check;
    }
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
    cout << "Enter the key : ";
    int key;
    cin >> key;

    bool ans = LinearSearch(arr, size, key);
    if (ans)
       { cout << "Key is Present";}
    else
    {
        cout << "Key is absent";
    }
    return 0;
}