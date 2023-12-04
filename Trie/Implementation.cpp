#include<bits/stdc++.h>
using namespace std;

class Trienode{

    public:
    char data;
    Trienode* children[26];
    bool isEnd;
    
    Trienode(char ch){
        data=ch;

        for(int i=0;i<26;i++)
        children[i]=NULL;

        isEnd=false;
    }

};

class Trie{
    
    public:
    Trienode* root;
    Trie(){
        root= new Trienode('\0');
    }

    void insertUtil(Trienode* root, string word){
        //base case
        if(word.length()==0){
        root->isEnd=true;
        return;
        }

        char index=word[0]-'A';
        Trienode*  child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new Trienode(word[0]);
            root->children[index]=child;
        }

        //recursion
        insertUtil(child,word.substr(1));
    }
    //without using recursion
      void insert(string word){
        
            Trienode* currNode=root;
        for(int i=0;i<word.length();i++){

            char index=word[i]-'a';

            if( currNode->children[index]==NULL){
                
                currNode->children[index]=new Trienode(index);
            }
                currNode=currNode->children[index];
        }

        currNode->isEnd=true;
    }
    void insertWord(string word){
        insertUtil(root,word);
    }

    //searchWord
    bool searchUtil(Trienode* root, string word){

        //base Case
        if(word.length()==0){
        return root->isEnd;
        }
        char index=word[0]-'A';
        Trienode* child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else return false;
        
        return searchUtil(child, word.substr(1));
    }
    bool searchWord(string word){
        return searchUtil(root, word);
    }
};

/*

class Trienode{

    public:
    char data;
    Trienode* children[26];
    bool isEnd;
    
    Trienode(char ch){
        data=ch;

        for(int i=0;i<26;i++)
        children[i]=NULL;

        isEnd=false;
    }

};
class Trie {
public:
 public:
    Trienode* root;
    Trie(){
        root= new Trienode('\0');
    }
    
    
    void insert(string word){
        
            Trienode* currNode=root;
        for(int i=0;i<word.length();i++){

            char index=word[i]-'a';

            if( currNode->children[index]==NULL){
                
                currNode->children[index]=new Trienode(index);
            }
                currNode=currNode->children[index];
        }

        currNode->isEnd=true;
    }

    //searchWord
    bool searchUtil(Trienode* root, string word){

        //base Case
        if(word.length()==0){
        return root->isEnd;
        }
        char index=word[0]-'a';
        Trienode* child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else return false;
        
        return searchUtil(child, word.substr(1));
    }

    bool search(string word){
        return searchUtil(root, word);
    }

       bool prefixUtil(Trienode* root, string word){

        //base Case
        if(word.length()==0){
        return true;
        }
        char index=word[0]-'a';
        Trienode* child;
        
        if(root->children[index]!=NULL){
            child=root->children[index];
        }else return false;
        
        return prefixUtil(child, word.substr(1));
    }
    
    bool startsWith(string prefix) {
        return prefixUtil(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */*/
int main(){
   
   Trie *t=new Trie();
   t->insertWord("WORD");
   cout << t->searchWord("WORDE");
return 0 ;
}