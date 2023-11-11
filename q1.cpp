#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    int arr[4] = {3, 2, 1, 4};
    map<int, int> mp;

    // find all the indexes
    for (int i = 0; i < 4; i++)
    {
        mp[arr[i]] = i;
    }
    //sorting the array
    sort(begin(arr), end(arr));


    //finding the displacement
    int diff[4];

    for (int i = 0; i < 4; i++)
    {
        diff[i] = i - mp[arr[i]];
        if(diff[i] < 0) 
        diff[i] = !diff[i];
        cout << diff[i] << " ";
    }
    cout<<endl;
    //multiplying & summing up
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        sum += diff[i]*arr[i];
        cout << sum;
    }

    cout << sum;

    return 0;
}