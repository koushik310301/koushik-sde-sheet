#include<bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    int n=price.size();
    vector<int> ans(n,1);
    stack<int> s;
    for(int i=0;i<n;i++){
        int count=1;
        while(!s.empty() && price[i]>=price[s.top()]){
            count+=ans[s.top()];
            s.pop();
            }
            s.push(i);
            ans[i]=count;
    }
            return ans;
}