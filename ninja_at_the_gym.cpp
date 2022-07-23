#include<bits/stdc++.h>
void fun(int ind, int prev, vector<int>& v,vector<int>& nums ,vector<int>& ans, int n){
    if(ind==n){
       int s=0;
        for(int i : v) s+=i;
        ans.push_back(s);
        return;
    }
    
    if(prev==-1 || nums[ind]>nums[prev]){
        v.push_back(nums[ind]);
        prev=ind;
        fun(ind+1,prev,v,nums,ans,n);
        v.pop_back();
    }
    fun(ind+1,prev,v,nums,ans,n);
    
}
int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
	// Write your code here
//     vector<int> ans;
//     vector<int> v;
//     vector<int> sum(1,0);
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     fun(0,-1,v,nums,ans,n,dp,sum);
//     return *max_element(ans.begin(),ans.end());
    vector<int> dp(n,-1);
    dp[0] = rack[0];
    
    for(int i=1;i<n;i++)
    {
        int ans = rack[i];
        for(int j=0;j<i;j++)
        {
            if(rack[j]<rack[i])
            {
                ans = max(ans,rack[i]+dp[j]);
            }
        }
        dp[i] = ans;
    }
    return *max_element(dp.begin(),dp.end());
}