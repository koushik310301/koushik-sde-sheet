#include<bits/stdc++.h>
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    int n=v.size();
    n=pow(2,n);
    for(int i=0;i<n;i++){
        vector<int> tmp;
        int j=0;
        int x=i;
        while(x>0){
            if(x&1){
                tmp.push_back(v[j]);
            }
            j++;
            x=x>>1;
        }
        ans.push_back(tmp);
    }
    return ans;
}