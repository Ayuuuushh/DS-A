#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~node()
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
void insert(node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        node *newNode = new node(d);
        tail = newNode;
        newNode->next = tail;
    }
    else
    {
        // non empty list
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }

        // element found at curr->dats and that is representing element

        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
// printing in circular linked list
void print(node *tail)
{

    node *temp = tail;

    // empty list
    if (tail == NULL)
    {
        cout << "List is Empty " << endl;
        return;
    }

    do
    {
        cout << tail->data << "->";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}
void deleteNode(node *&tail, int element)
{
    // no element present
    if (tail == NULL)
    {
        cout << "Empty List , Check again" << endl;
        return;
    }

    else
    {
        // element present condition
        node *prev = tail;
        node *curr = prev->next;

        while (curr->data != element)
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == prev)
        {
            tail = NULL;
        }
        else if (curr == tail)
        {
            tail = prev;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
int lengthofLL(node *&tail)
{
    int cnt = 0;
    node *temp = tail;
    map<node *, bool> visited;

    while (visited[temp->next] != true)
    {
        cnt++;
        visited[temp] = true;
        temp = temp->next;
    }
    cout << "length of LL : " << cnt << endl;
    return cnt;
}
void split(node *&tail)
{
    int cnt = 0;
    int length = lengthofLL(tail);
    node* newTail = NULL;
    node *temp = tail;
    if (length % 2 == 0)
    {
        while (cnt < (length / 2))
        {
            cnt++;
            temp = temp->next;
        }
        newTail = temp->next;
        temp->next = tail;
        print(tail);

        node* newTemp = newTail;
         while (cnt < length-1)
        {
            cnt++;
            newTemp = newTemp->next;
        }
        newTemp->next = newTail;
       
        print(newTail);
    }
}
int main()
{

    node *tail = NULL;
    print(tail);
    insert(tail, 4, 6);

    insert(tail, 6, 8);
    insert(tail, 8, 34);
    insert(tail, 8, 12);
    insert(tail, 6, 7);
    insert(tail, 6, 7);
    insert(tail, 6, 7);
    // insert(tail, 6, 78);
    print(tail);
    int length = lengthofLL(tail);
    cout << endl
         << "Tail : " << tail->data << endl;
         split(tail);

    return 0;
}