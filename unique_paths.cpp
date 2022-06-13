#include <bits/stdc++.h>
int fun(int x, int y, int m, int n,vector<vector<int>>& dp){
    if(x==m-1 && y==n-1) return 1;
    if(x<0 || x==m || y<0 || y==n) return 0;
    if(dp[x][y]!=-1) return dp[x][y];
    return dp[x][y]=fun(x,y+1,m,n,dp)+fun(x+1,y,m,n,dp);
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return fun(0,0,m,n,dp);
}