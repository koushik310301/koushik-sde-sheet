#include<bits/stdc++.h>
int fun(int ind, int w, int n, vector<int>& values, vector<int>& weights,vector<vector<int>>& dp){
    if(ind==n || w==0) return 0;
    
    if(dp[w][ind]!=-1) return dp[w][ind];
    
    int pick=0;
    if(w>=weights[ind]){
        pick+=values[ind]+fun(ind+1,w-weights[ind],n,values,weights,dp);
    }
    int npick=fun(ind+1,w,n,values,weights,dp);
    
    return dp[w][ind]=max(pick,npick);
    
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int>> dp(w+1,vector<int>(n,-1));
    return fun(0,w,n,values,weights,dp);
}