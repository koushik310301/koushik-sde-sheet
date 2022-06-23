#include<bits/stdc++.h>
vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    int n=num.size();
    n=pow(2,n);
    for(int i=0;i<n;i++){
        int x=i;
        int sum=0;
        int j=0;
        while(x>0){
            if(x&1){
                sum+=num[j];
            }
            j++;
            x=x>>1;
        }
        ans.push_back(sum);
    }
    sort(ans.begin(),ans.end());
    
    return ans;
}