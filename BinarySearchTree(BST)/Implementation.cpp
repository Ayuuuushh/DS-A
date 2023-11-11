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
    int getMin(node* root){

        node* temp = root;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp->data;
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

node* deletion(node* root,int d){

    if(root == NULL)
    return NULL;


    if(root->data == d){

        //No sub node
        if(!root->right && !root->left){
            delete root;
            return NULL;
        }

        //one node
        if(root->left == NULL && root->right != NULL){
            node* curr = root->right;
            delete root;
            return curr;
        }
        if(root->left != NULL && root->right == NULL){
           node* curr = root->left;
            delete root;
            return curr;
        }

        //sub-tree
        if(root->left != NULL && root->right != NULL){

            int mini = getMin(root->right);
            root->data = mini;
            root->right=deletion(root->right,mini);
            return root;
        }

    }
    else if(root->data > d){
       root->left = deletion(root->left,d);
       return root;
    }
    else{
       root->right= deletion(root->right,d);
       return root;
    }
}
int main()
{

    node *root = NULL;

    takeInput(root);
    levelOrderTraversal(root);
    cout << "deletion" << endl;

    root = deletion(root,1);
    levelOrderTraversal(root);

    return 0;
}