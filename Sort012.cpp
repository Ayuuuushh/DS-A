#include<bits/stdc++.h>
using namespace std;
void Sort(int arr[] ,int n ){
    int s=0,e=n-1;
    int mid = s+(e-s)/2;
    while (s<=e)
    {
        if(arr[mid==0]){
            swap(arr[mid],arr[s]);
            s++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else 
        {
            swap(arr[mid],arr[e]);
        }
        mid = s + (e-s)/2;
    }
    
}
int main(){
   int n ;
    cin >>n;
    int arr[5]={1,1,0,2,1};
    Sort(arr,5);
   
    
return 0 ;
}