#include<bits/stdc++.h>


vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++){
        auto ls=q[i];
        if(ls[0]==0){
            pq.push(ls[1]);
        }
        else{
            int x=pq.top();
            pq.pop();
            ans.push_back(x);
        }
    }
    return ans;
}
