#include<bits/stdc++.h>
using namespace std;
bool checkPalindrome(char s[] ,int n){
    int st  =0 ;
    int e = n- 1;
    while(st<=e){
        if(s[st] != s[e] ){
            return 0 ;
        }
        else{
            st++;
            e--;

        }
    }
    return 1;
}
int main(){
   char s[20];
   cin>>s;
   int n = strlen(s);
   cout <<" Palindrome or not : "<<checkPalindrome(s , n);
return 0 ;
}