/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
class Solution {
public:
    bool check(vector<vector<char>>&board,int i,int j,char ele){
        for(int I=0;I<9;I++){
            if(board[I][j]==ele||board[i][I]==ele) return false;
        }
        int x = 3*(i/3),y = 3*(j/3);
        for(int I =x;I<x+3;I++){
            for(int J=y;J<y+3;J++){
                if(board[I][J]==ele) return false;
            }
        }
        return true;
    }
    void solve(vector<vector<char>>&board,int idx1,int idx2,bool &flag){
        if(idx1==9){flag=1;return;}
        if(idx2==9) solve(board,idx1+1,0,flag);
        else if(board[idx1][idx2]!='.') solve(board,idx1,idx2+1,flag);
        else{
            for(char ele='1';ele<='9';ele++){
                if(!check(board,idx1,idx2,ele))    continue;
                board[idx1][idx2]=ele;
                solve(board,idx1,idx2+1,flag);
                if(!flag)    board[idx1][idx2]='.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool flag=0;
        solve(board,0,0,flag);
    }
};
