#include<bits/stdc++.h>
long fun(int ind, int tg,int* deno, int n,vector<vector<long>>& dp){
    
    if(ind==n){
        if(tg==0){
            //for(int i : v) cout<<i<<" ";
            //cout<<endl;
            return 1;
        }
        return 0;
    }
    
    if(dp[ind][tg]!=-1) return dp[ind][tg];
    
    long pick=0;
    if(tg>=deno[ind]){
        //v.push_back(deno[ind]);
        pick=fun(ind,tg-deno[ind],deno,n,dp);
        //v.pop_back();
    }
    long npick=0;
    npick=fun(ind+1,tg,deno,n,dp);
    
    return dp[ind][tg]=pick+npick;
    
}
long countWaysToMakeChange(int *deno, int n, int tg)
{
    //Write your code here
    //vector<int> v;
    vector<vector<long>> dp(n+1,vector<long>(tg+1,-1));
    return fun(0,tg,deno,n,dp);
}