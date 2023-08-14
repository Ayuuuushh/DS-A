#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int size) // 2 3 4 54 3 
{

    // base case
    if (size == 1 || size == 0) // false
        return true;

    // processing

    if(arr[0] > arr[1]) // 3 2 //false ;
    return false;
    else{    // 
        //recursive call
        bool remainingPart = isSorted(arr + 1 , size-1);  // 3 s4
        return remainingPart;
    }
}
int main()
{   
    int size ;
    cin >> size;
    int arr[size];
    for(int i = 0; i < size; i++)
    {
    
        cin >> arr[i];
    }
    bool ans = isSorted(arr, size);

    cout << ans;
    return 0;
}