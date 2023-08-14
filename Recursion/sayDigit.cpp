#include<bits/stdc++.h>
using namespace std;



void  sayDigit(int n){
    string arr[10] ={
       "zero", "one","two","three","four","five","six","seven","eight","nine"
    };
        // base case
    if(n==0)return;

    //processing
    int digit = n % 10; // 143 3
    n = n / 10;

    //recursive call
    sayDigit(n);

    //print
    cout << arr[digit] << " ";
}
int main(){
   int n;
   cin >> n;
    cout << endl;
   sayDigit(n);
return 0 ;
}


// https://drive.google.com/file/d/11e3PJz1Fq5frLQgM_xVVyq_5Lngn77sc/view