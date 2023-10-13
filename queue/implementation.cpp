#include <bits/stdc++.h>
using namespace std;

class Queue
{
    public:
    int rear;
    int front;
    int size;
    int *arr;

    Queue()
    {
        arr = new int[100];
        front = 0;
        rear = 0;
        size = sizeof(arr);
    }


    //push operation
    push(int x)
    {
        if (rear < (size - 1))
        {
            arr[rear] = x;
            rear++;
        }
    }
    //pop operation
    int pop(){
        if(front != rear){

        int x = arr[front];
        front++;
        return x;

        }
        else
        return -1;
    }


    void print(){
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] <<" ";
        }

        cout << endl;
        
    }
};
int main()
{
    Queue* q = new Queue();
    q->push(5);
    q->print();
   cout << "Pop : " << q->pop() << endl;
    q->print();

    return 0;
}