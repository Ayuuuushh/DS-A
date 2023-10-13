#include<bits/stdc++.h>
using namespace std;

class node{
    
    public:

    int data;
    node* left;
    node* right;

    node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }

};

node* buildTree(node* root) {

    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void ReverseOrderTraversal(node* root) {
    deque<node*> q;
    stack<node*>S;
    q.push_back(root);
    q.push_back(NULL);
    S.push(root);
    S.push(NULL);


    while(!q.empty()) {
        node* temp = S.top();
        S.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!S.empty()) { 
                //queue still has some child ndoes
                q.push_back(NULL);
                S.push(NULL);
            }  
        }
        if(temp != NULL){
            
            if(temp ->left) {
                q.push_back(temp ->left);
                S.push(temp->left);
            }

            if(temp ->right) {
                q.push_back(temp ->right);
                S.push(temp->right);
            }
        }

    }
          while (S.empty() == false)
    {
        root = S.top();
        if(root == NULL){
        cout << endl;
        S.pop();}
        else{
        cout << root->data << " ";
        S.pop();}
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

int main(){
   
   node* root = NULL;
   root = buildTree(root);

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

   levelOrderTraversal(root);
   ReverseOrderTraversal(root);


return 0 ;
}