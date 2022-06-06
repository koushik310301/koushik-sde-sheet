#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &nums, int n)
{
	// Write your code here 
    pair<int,int> ans;
    unordered_map<int,int> mp;
    for(int i : nums){
        mp[i]++;
    }
    for(int i=1;i<=n;i++){
        if(mp[i]==0){
            ans.first=i;
        }
        else if(mp[i]==2){
            ans.second=i;
        }
    }
    
    return ans;
	
}
