#include<bits/stdc++.h>
using namespace std;

// Stack Implmentation
class Stack{

    public:
    int *arr;
    int size;
    int top;


    // Constructor
    Stack(int size){
        this->size = size;
        top = -1;
        arr = new int[size];
    }

    // Operations

    void push(int d){
        if(size - top > 1)
        {
            top++;
            arr[top] = d;
        }
        else{
            cout << "Stack Overflow " << endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout << " Stack is Empty" << endl;
        }
    }

    int peek(){

        if(top >= 0){
            return arr[top];
        }
        else{
            cout <<"stack is Empty" << endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        else
            return false;    
       
    }

};
int main(){
   
   Stack stl(5);

   stl.push(9);
   stl.push(8);
   stl.pop();
   stl.pop();
   cout << stl.isEmpty();
   cout << stl.peek();
return 0 ;
}