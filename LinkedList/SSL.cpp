#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *Next;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->Next = NULL;
    }

    // Destructor
    ~Node()
    {
        int value = this->data;
        if (this->Next != NULL)
        {
            delete Next;
            this->Next = NULL;
        }
        cout << "Memory free for data : " << value << endl;
    }
};

// Insertion at head in a linked list

void insertAtHead(Node *&head, int data)
{
    // new node create
    Node *temp = new Node(data);
    temp->Next = head;
    head = temp;
}

// Insertion at tail in a Linked List

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->Next = temp;
    tail = temp;
}

// Insertion at any position

void insertAtPosition(Node *&tail, Node *&head, int position, int data)
{

    // insert at beginning
    if (position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->Next;
    }

    // insertion at last
    if (temp->Next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }
    Node *nodeToInsert = new Node(data);
    nodeToInsert->Next = temp->Next;
    temp->Next = nodeToInsert;
}

// deletion of a node in a linked list
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->Next;
        // freeing memory of start Node
        temp->Next = NULL;
        delete temp;
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->Next;
            cnt++;
        }

        prev->Next = curr->Next;
         if (prev->next == NULL)
        {
            tail = prev;
        }
        curr->Next = NULL;
        delete curr;
    }
}
// print of Linked List

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->Next;
    }
    cout << endl;
}
int main()
{
    // creating object in heap
    Node *Node1 = new Node(10);
    //    cout << Node1->data << endl;
    //    cout << Node1->Next << endl;
    Node *head = Node1;
    Node *tail = Node1;
    print(head);

    // insertAtHead(head, 12);
    // print(head);

    insertAtTail(tail, 23);
    insertAtTail(tail, 34);
    print(head);

    insertAtPosition(tail, head, 2, 56);
    print(head);
    
    deleteNode(3, head);
    print(head);
    return 0;
}