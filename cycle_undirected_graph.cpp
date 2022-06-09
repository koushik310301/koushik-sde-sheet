#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int,list<int>> adj;
    for(auto ls : edges){
        adj[ls[0]].push_back(ls[1]);
        adj[ls[1]].push_back(ls[0]);
    }
    vector<int> vis(n+1,0);
    vector<int> par(n+1,-1);
    for(int k=1;k<=n;k++){
          if(vis[k]==0){
              queue<int> q;
              q.push(k);
              while(q.empty()==false){
                  auto it=q.front();
                  vis[it]=1;
                  q.pop();
                  for(auto ls : adj[it]){
                      if(vis[ls]==0){
                          vis[ls]=1;
                          par[ls]=it;
                          q.push(ls);
                      }
                      else if(par[it]!=ls){
                          return "Yes";
                      }
                  }
              }
          }  
    }
    return "No";
}
