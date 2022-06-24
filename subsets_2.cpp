#include<bits/stdc++.h>
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    set<vector<int>> ans;
    
    n=pow(2,n);
    for(int i=0;i<n;i++){
        int x=i;
        vector<int> tmp;
        int j=0;
        while(x>0){
            if(x&1){
                tmp.push_back(arr[j]);
            }
            j++;
            x=x>>1;
        }
        sort(tmp.begin(),tmp.end());
        ans.insert(tmp);
    }
    vector<vector<int>> fans(ans.begin(),ans.end());
    return fans;
}