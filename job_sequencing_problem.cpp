#include<bits/stdc++.h>
bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]!=b[0]) return a[0]<b[0];
    return a[1]<b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),cmp);
//     for(auto ls : jobs){
//         cout<<ls[0]<<"--"<<ls[1]<<endl;
//     }
    priority_queue<int> pq;
    for(auto ls : jobs){
        pq.push(-ls[1]);
        while(pq.size()>ls[0]) pq.pop();
    }
    int ans=0;
    //cout<<"--------------"<<endl;
    while(pq.empty()==false){
        ans+=pq.top();
        //cout<<pq.top()<<" ";
        pq.pop();
    }
    return ans*-1;
}
