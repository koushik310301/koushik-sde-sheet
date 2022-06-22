#include<bits/stdc++.h>

bool isSafe(int row, int col, vector<vector<int>>& board, int n)
{
    //column check
    for(int i=0;i<row;i++){
        if(board[i][col]==1) return false;
    }
    
    //left diagonal
    int mxl=min(row,col);
    for(int i=1;i<=mxl;i++){
        if(board[row-i][col-i]==1) return false;
    }
    
    //right diagonal
    int mxr=min(row,n-col-1);
    for(int i=1;i<=mxr;i++){
        if(board[row-i][col+i]==1) return false;
    }

    return true;
}

void solve(int row, vector<vector<int>>& board, vector<vector<int>>& ans, int n){
    if(row==n){
        vector<int> tmp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                tmp.push_back(board[i][j]);
            }
        }
        ans.push_back(tmp);
        return ;
    }
    
    for(int i=0;i<n;i++){
        if(isSafe(row,i,board,n)){
            board[row][i]=1;
            solve(row+1,board,ans,n);
            board[row][i]=0;
        }
    }
    
    
    
    
    
}
vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n,vector<int>(n,0));
    solve(0,board,ans,n);
    return ans;
}