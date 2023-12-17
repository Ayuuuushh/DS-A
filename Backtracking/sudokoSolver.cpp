#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool isSafe(int row, int col,vector<vector<char>>& board, int val ){

        for(int i=0;i<9;i++){

            if(board[row][i]==val || board[i][col]==val)
            return false;

            if(board[3*(row/3) + i/3][3*(col/3) + i%3]==val)
            return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){

        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(board[row][col]=='.'){
                for(char val='1';val<='9';val++){
                    
                        if(isSafe(row,col,board,val)){
                            board[row][col]=val;
                            bool nextPossibleSol=solve(board);
                            if(nextPossibleSol)
                            return true;
                            else
                            board[row][col]='.';

                        }
                }
                return false;
                }
            }
        }

        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        solve(board);
    }
};
int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    sol.solveSudoku(board);

    // Display the solved Sudoku board
    for (const auto& row : board) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}
