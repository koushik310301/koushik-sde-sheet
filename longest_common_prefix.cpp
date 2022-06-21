#include<bits/stdc++.h>
string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    string ans="";
    int ln=INT_MAX;
    for(auto ls : arr){
        int x=ls.length();
        ln=min(ln,x);
    }
    for(int i=0;i<ln;i++){
        map<char,int> mp;
        for(int j=0;j<n;j++){
            mp[arr[j][i]]++;
        }
        if(mp.size()==1){
            for(auto ls : mp) ans+=ls.first;
        }
        else{
            break;
        }
    }
    return ans;
}


