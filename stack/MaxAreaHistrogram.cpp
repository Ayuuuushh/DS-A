#include<bits/stdc++.h>
using namespace std;

void Print(int arr[],int n){

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
}
 int largestRectangleArea(vector<int>& heights) {
        
        stack<int> st;
        int n = heights.size();
        int leftSmaller[n], rightSmaller[n];

        int Maxarea = 0;
        

        //step1 -> left Smaller

        for(int i = 0 ; i < n ; i++){

            while((!st.empty()) && heights[st.top()] >= heights[i])
            st.pop();

            if(st.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = st.top() + 1;
            st.push(i);
        }


        //emptying the stack
        while(!st.empty())
        st.pop();

        //step2 -> right Smaller

    for(int i = n-1 ; i >=0 ; i--){

        while((!st.empty()) && heights[st.top()] >= heights[i])
            st.pop();

             if(st.empty()) rightSmaller[i] = n-1;
              else rightSmaller[i] = st.top()  - 1;
              st.push(i);


            
        //step3 -> Calculate area

    Maxarea = max((rightSmaller[i]  - leftSmaller[i] + 1) * heights[i], Maxarea);

    }

    Print(leftSmaller, n);
    cout << endl;
    Print(rightSmaller, n);
    cout << endl;

     return Maxarea;
    }
int main(){


    vector<int> arr = {2,1,5,6,2,3};
    
   cout <<  largestRectangleArea(arr);
   
return 0 ;
}