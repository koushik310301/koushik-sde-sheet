#include<bits/stdc++.h>
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    n=pow(2,n);
    for(int i=0;i<n;i++){
        vector<int> v;
        int x=i;
        int j=0;
        long long sum=0;
        while(x>0){
            if(x&1){
                sum+=arr[j];
                v.push_back(arr[j]);
            }
            j++;
            x=x>>1;
        }
        if(sum==k) ans.push_back(v);
    }
    return ans;
}