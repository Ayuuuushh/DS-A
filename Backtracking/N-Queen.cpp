#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void addSolu(vector<vector<char>>& board, vector<vector<string>> &ans, int n){

        vector<string> temp;

        for(int i=0;i<n;i++){
            string output="";
            for(int j=0;j<n;j++){
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col,vector<vector<char>>& board, int n ){

        int x=row,y=col;
        while(y>=0){
           if(board[x][y]=='Q')
           return false;
           y--;
        }

        x=row;
        y=col;
        while(x<n && y>=0){
          if(board[x][y]=='Q')
           return false;
           x++;
           y--;
        }

        x=row;
        y=col;
        while(x>=0 && y>=0){
            if(board[x][y]=='Q')
           return false;
           x--;
           y--;
        }

        return true;
    }
    void solve(int col,vector<vector<char>> &board, vector<vector<string>> &ans, int n){

        if(col==n){
            addSolu(board,ans,n);
            return;
        }

        for(int row=0;row<n;row++){

            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1, board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;

        solve(0, board, ans, n);
        return ans;

    }
};
int main() {
    Solution sol;
    int n = 4;
    vector<vector<string>> result = sol.solveNQueens(n);

    // Display the result
    for (const auto& config : result) {
        for (const string& row : config) {
            cout << row << endl;
        }
        cout << "----------" << endl;
    }

    return 0;
}
