//  Peak Index in a Mountain Array
// An array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Given a mountain array arr, return the index i such that arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// You must solve it in O(log(arr.length)) time complexity.

// Example 1:

// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 2

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 10

// Constraints:

// 3 <= arr.length <= 105
// 0 <= arr[i] <= 106
// arr is guaranteed to be a mountain array.

#include <bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n)
{
    int left = 0;
    int right = n - 1;
    int mid = left + (right - left) / 2; // this formula has been to be in the arr value only.
    while (left < right)
    {
        if (arr[mid] < arr[mid + 1])
            left = mid + 1; // Probably it will reach the peak element and the condition satisy till here.
        else
            right = mid;
        mid = left + (right - left) / 2;
    }
    return left;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Peak Element : " << peakElement(arr, n);
    return 0;
}