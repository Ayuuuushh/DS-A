#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};



node* insert(node *root, int d)
{

    if (root == NULL)
    {
        root = new node(d);
        return root;
    }

    if (d < root->data)
    {
        root->left = insert(root->left, d);
    }

    else
    {

        root->right = insert(root->right, d);
    }

    return root;
}
    void takeInput(node* &root)
    {
        int d;
        cin >> d;

        while(d != -1){
            root = insert(root,d);
            cin>>d;
        }
           
        
    }

    void levelOrderTraversal(node* root) {
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}
int main()
{

    node *root = NULL;

    takeInput(root);
    levelOrderTraversal(root);

    return 0;
}