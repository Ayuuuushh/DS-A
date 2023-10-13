#include<bits/stdc++.h>
using namespace std;

int countTeams(int *arr , int n){
    int result  = 0;
    int cnt = 0;
    int i = 0 ;

    while(i < n){

        if(i + 1 == arr[i+1] && i + 2 == arr[i] ){
            cnt++;
            i+=2;
        }
        else i++;
    }
    return cnt;
}
int main(){
    int n ;
    cin >> n;
   int* arr = new int[n];

   for (int  i = 0; i < n; i++)
   {
    cin >> arr[i];
   }
 cout << countTeams(arr,n);
return 0 ;
}