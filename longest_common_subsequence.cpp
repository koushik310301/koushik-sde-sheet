#include<bits/stdc++.h>
int fun(int i, int j, string s, string t,vector<vector<int>>& dp){
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==t[j]) return 1+fun(i-1,j-1,s,t,dp);
    return dp[i][j]=max(fun(i-1,j,s,t,dp),fun(i,j-1,s,t,dp));
}
int lcs(string s, string t)
{
	//Write your code here
    int i=s.length()-1;
    int j=t.length()-1;
    int m=s.length();
    int n=t.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return fun(i,j,s,t,dp);
}