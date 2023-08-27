#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
   
};
// display in DLL
void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";
    cout << endl;
}

// insert at head
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
// insert at tail

void insertAtTail(Node *&tail, Node *&head, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else
    {

        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
// insert at position
void insertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    Node *temp = head;
    // inserting at first
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    // inserting at last
    if (temp->next == NULL)
    {
        insertAtTail(tail, head, d);
        return;
    }
    Node *nodeToInsert = new Node(d);

    // node to insert
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void reverse(Node*&head){
   Node*curr = head;
    Node*prev = NULL;
    while(curr->next == NULL){
        curr->next =prev;
        prev->next = curr->next;
        curr->prev = NULL;
        curr=curr->next;

    }
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    insertAtHead(head, tail, 54);
    print(head);
    insertAtTail(tail, head, 34);
    print(head);

    insertAtPosition(head, tail, 3, 67);
    print(head);
    insertAtPosition(head, tail, 1, 110);
    print(head);
    insertAtPosition(head, tail, 5, 102);
    print(head);
    print(head);
    // cout << endl <<tail->data;

     reverse(head);
     print(head);
    return 0;

}