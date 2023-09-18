#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "ayush";
    int cnt = 0;

    //approach 1
    for (int i = 0; i < str.length(); i++)
    {
        cnt++;
    }
    cout << "Length : " << cnt << endl;

    //approach 2
    // simply return length

    cout <<"Length : " << str.length();

    return 0;
}