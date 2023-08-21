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
    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << value << endl;
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

// getLength in LL
int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
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

// deletion in DLL
void deleteNode(int position, Node *&head,Node*&tail)
{

    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
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
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;

        if (prev->next == NULL)
        {
            tail = prev;
        }
        curr->next = NULL;

        delete curr;
    }
}
int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    print(head);
    insertAtHead(head, tail, 54);
    print(head);
    cout << "length : " << getLength(head) << endl;

    insertAtTail(tail, head, 34);
    print(head);

    insertAtPosition(head, tail, 3, 67);
    print(head);
    insertAtPosition(head, tail, 1, 110);
    print(head);
    insertAtPosition(head, tail, 5, 102);
    print(head);
    deleteNode(5, head,tail);
    print(head);
    cout << endl <<tail->data;
    return 0;
}