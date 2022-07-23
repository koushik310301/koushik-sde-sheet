#include<bits/stdc++.h>
int fun(int i, int j, vector<int>& arr,vector<vector<int>>& dp){
    if(i==j) return 0;
    int mini=1e9;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<=j-1;k++){
        int steps=arr[i-1]*arr[k]*arr[j]+
            fun(i,k,arr,dp)+
            fun(k+1,j,arr,dp);
        if(steps<mini) mini=steps;
    }
    return dp[i][j]=mini;
}
int matrixMultiplication(vector<int> &arr, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(n,-1));
    return fun(1,n-1,arr,dp);
}