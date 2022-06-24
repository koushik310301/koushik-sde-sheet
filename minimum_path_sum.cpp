#include<bits/stdc++.h>

int fun(int x, int y, vector<vector<int>>& grid, int n,int m,vector<vector<int>>& dp){
    if(x<0 || x==n || y<0 || y==m) return INT_MAX;
    
    if(dp[x][y]!=-1) return dp[x][y];
    if(x==n-1 && y==m-1) return grid[x][y];
    
    int down=fun(x+1,y,grid,n,m,dp);
    int right=fun(x,y+1,grid,n,m,dp);
    
    return dp[x][y]=grid[x][y]+min(down,right);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
   
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    return fun(0,0,grid,n,m,dp);
}