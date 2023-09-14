#include <bits/stdc++.h>
using namespace std;
int main()
{
    // creation
    stack<int> s;

    // push operation
    s.push(5);
    s.push(6);
    s.push(7);

    //pop operation
    s.pop();

    //top element
    cout << "top element : " << s.top() << endl ;

    //get size
    cout << s.size();

    return 0;
}