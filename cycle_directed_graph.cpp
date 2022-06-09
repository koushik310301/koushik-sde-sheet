#include<bits/stdc++.h>
bool dfs(unordered_map<int,list<int>>& adj,vector<int>& vis,vector<int>& dfs_call,int n, int src){
    vis[src]=1;
    dfs_call[src]=1;
    for(int i : adj[src]){
        
        if(vis[i]==0){
            if(dfs(adj,vis,dfs_call,n,i)){
                return true;
            }
        }
        else if(vis[i]==1 && dfs_call[i]==1) return true;
    }
    dfs_call[src]=0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
     // Write your code here.
    unordered_map<int,list<int>> adj;
    for(auto ls : edges){
        adj[ls.first].push_back(ls.second);
    }
    vector<int> vis(n+1,0);
    vector<int> dfs_call(n+1,0);
    
    for(int k=1;k<=n;k++){
          if(vis[k]==0){
              if(dfs(adj,vis,dfs_call,n,k)){
                  return true;
              }
          }  
    }
    return false;
}