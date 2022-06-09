#include<bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
    vector<int> ans;
    vector<int> ind(n,0);
    unordered_map<int,list<int>> adj;
    for(auto ls : edges){
        adj[ls[0]].push_back(ls[1]);
        ind[ls[1]]++;
    }
    
    vector<int> vis(n,0);
    queue<int> q;
    for(int i=0;i<n;i++){
        if(ind[i]==0){
            q.push(i);
        }
    }
    while(q.empty()==false){
        int x=q.front();
        ans.push_back(x);
//         vis[x]=1;
        q.pop();
        for(int i : adj[x]){
            ind[i]--;
            if(ind[i]==0) q.push(i);
        }
        
    }
    return ans;
}