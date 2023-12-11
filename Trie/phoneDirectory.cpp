#include <bits/stdc++.h>
using namespace std;

class Trienode
{

public:
    char data;
    Trienode *children[26];
    bool isEnd;

    Trienode(char ch)
    {
        data = ch;

        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isEnd = false;
    }
};

class Trie
{

public:
    Trienode *root;
    Trie()
    {
        root = new Trienode('\0');
    }

    void insert(string word)
    {

        Trienode *currNode = root;
        for (int i = 0; i < word.length(); i++)
        {

            char index = word[i] - 'a';

            if (currNode->children[index] == NULL)
            {

                currNode->children[index] = new Trienode(index);
            }
            currNode = currNode->children[index];
        }

        currNode->isEnd = true;
    }

    void printallSuggestion(Trienode *curr, vector<string> &temp, string prefix)
    {

        if (curr->isEnd)
            temp.push_back(prefix);

        for (char i = 'a'; i < 'z'; i++)
        {

            Trienode *next = curr->children[i - 'a'];

            if (next != NULL)
            {
                prefix.push_back(i);
                printallSuggestion(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string str)
    {

        vector<vector<string>> output;
        Trienode *prev = root;
        string prefix = "";

        for (int i = 0; i < str.size(); i++)
        {

            char lastch = str[i];
            prefix.push_back(lastch);

            Trienode *curr = prev->children[lastch - 'a'];

            if (curr == NULL)
            {
                break;
            }

            vector<string> temp;
            printallSuggestion(curr, temp, prefix);
            output.push_back(temp);
            temp.clear();

            prev = curr;
        }

        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string> &contactList, string &queryStr)
{

    Trie *t = new Trie();

    for (int i = 0; i < contactList.size(); i++)
    {

        string str = contactList[i];
        t->insert(str);
    }

    return t->getSuggestion(queryStr);
}
int main()
{

    // string size
    int totalString;
    cout << "No. of contacts" << endl;
    cin >> totalString;

    vector<string> contacts;

    cout << "Enter the string" << endl;
    for (int i = 0; i < totalString; i++)
    {
        string s;
        cin >> s;
        contacts.push_back(s);
    }

    cout << "Enter search String" << endl;
    string query;
    cin >> query;

    // Implementation area;

    vector<vector<string>> output;
    output = phoneDirectory(contacts, query);

    for (int i = 0; i < output.size(); i++)
    {
        cout << endl;
        for (int j = 0; j < output[i].size(); j++)
        {
            cout << output[i][j] << " ";
        }
    }

    return 0;
}