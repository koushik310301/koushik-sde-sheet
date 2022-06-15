#include<bits/stdc++.h>
bool cmp(pair<int,int>& a, pair<int,int>& b){
    if(a.first==b.first) return a.second>b.second;
    return a.first>b.first;
}
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int> ans;
    unordered_map<int,int> mp;
    for(int i : arr) mp[i]++;
    vector<pair<int,int>> v;
    for(auto ls : mp){
        v.push_back({ls.second,ls.first});
    }
    
    sort(v.begin(),v.end(),cmp);
//     for(auto ls : v){
//         cout<<ls.first<<"--"<<ls.second<<endl;
//     }
    //reverse(v.begin(),v.end());
    for(int i=0;i<k;i++){
        ans.push_back(v[i].second);
    }
    sort(ans.begin(),ans.end());
    return ans;
}