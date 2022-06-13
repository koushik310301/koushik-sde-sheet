#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.4
    int n=arr.size();
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i : arr){
        mp[i]++;
    }
    for(auto ls : mp){
        if(ls.second > n/3) ans.push_back(ls.first);
    }
    return ans;
}