#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    
    vector<int> ans;
    
    
    unordered_map<int,int> mp;
    for(int i=0;i<k;i++){
        mp[arr[i]]++;
    }
    ans.push_back(mp.size());
    int i=1;
    int j=k;
    while(j<arr.size()){
        mp[arr[i-1]]--;
        if(mp[arr[i-1]]==0) mp.erase(arr[i-1]);
        mp[arr[j]]++;
        ans.push_back(mp.size());
        i++;
        j++;
    }
	
    return ans;
}
