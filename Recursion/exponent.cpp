#include <bits/stdc++.h>
using namespace std;

void exponent(int a, int b)
{
    // base case
    if (s > b)
        return;

    int ans = a * s;

    // recursive call
    exponent(a, b);

    cout << ans;
}

int main()
{
    int a, b;
    cin >> a >> b;
    exponent(a, b);

    return 0;
}