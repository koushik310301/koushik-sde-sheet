#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
  // Write your code here.
    vector<vector<long long int>> ans;
    ans.push_back({1});
    if(n==1) return ans;
    ans.push_back({1,1});
    if(n==2) return ans;
    int ind=1;
    for(int s=3;s<=n;s++){
        vector<long long> v(s,1);
        for(long long i=1;i<v.size()-1;i++){
            v[i]=ans[ind][i-1]+ans[ind][i];
        }
        ind++;
        ans.push_back(v);
        
    }
    return ans;
    
}
