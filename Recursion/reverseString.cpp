#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s, int start, int size)
{

    // base case
    if (start > size)
        return ;

    // processing
    swap(s[start], s[size]);
    start ++;
    size--;

    // recursive call
    return reverseString(s, start, size);
}
int main()
{
    string s;
    cin >> s;
    int size = s.size();
    cout << size;
    reverseString(s, 0, size - 1);
    cout << s;
    return 0;
}