#include<bits/stdc++.h>
using namespace std;

int main(){
   int arr[5] = { 1,2 ,3 ,4, 5};
   int target ;
   int ans = 0; 
   cin  >> target;
   int i;
   for ( i = 0; i < 5; i++)
   {
    
    
     while (ans==target){
        if(arr[i]<target){
            ans+=arr[i];
            cout<<i;
        }
        }
    
   }
   
return 0 ;
}