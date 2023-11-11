#include <bits/stdc++.h>
using namespace std;

class Heap
{

public:
    int arr[100];
    int size;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    // Insertion
    void insert(int val)
    {

        size = size + 1;
        int index = size;
        arr[size] = val;

        while (index > 1)
        {

            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // Deletion
    void deletionfromHeap()
    {

        if (size == 0)
        {
            cout << "Nothing to Delete" << endl;
            return;
        }

        // step1->put last element into first element
        arr[1] = arr[size];

        // step->2 delete last element
        size--;

        // step->3 put first Node to its correct position
        int i = 1;
        while (i < size)
        {

            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if (leftChild < size && arr[i] < arr[leftChild])
            {
                swap(arr[leftChild], arr[i]);
                i = leftChild;
            }

            else if (rightChild < size && arr[i] < arr[rightChild])
            {
                swap(arr[rightChild], arr[i]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

// Heapify Algorithms

void Heapify(vector<int> &arr, int i)
{

    int n = arr.size() - 1;
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
        largest = left;

    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, largest);
    }
}

int main()
{

    Heap *hp = new Heap;
    hp->insert(50);
    hp->insert(40);
    hp->insert(30);
    hp->insert(20);
    hp->insert(10);
    hp->insert(1);

    hp->print();

    cout << endl;
    hp->deletionfromHeap();
    hp->print();


    vector<int> arr = {-1, 54, 53, 55, 50, 52};
    int n = arr.size() / 2;
    for (int i = n / 2; i > 0; i--)
    {
        Heapify(arr, i);
    }

    cout << endl;
    cout << "Printing after Heapify Algo" << endl;

    for (int i = 1; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}