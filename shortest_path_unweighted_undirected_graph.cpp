
#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// Write your code here
    vector<int> vis(n+1,0);
    vector<int> par(n+1,-1);
    vector<int> ans;
    
    unordered_map<int,list<int>> adj;
    for(auto ls : edges){
        adj[ls.first].push_back(ls.second);
        adj[ls.second].push_back(ls.first);
    }
	queue<int> q;
    q.push(s);
    vis[s]=1;
    while(q.empty()==false){
        int x=q.front();
        q.pop();
        for(auto ls : adj[x]){
            if(vis[ls]==0){
                q.push(ls);
                par[ls]=x;
                vis[ls]=1;
            }
        }
    }
    ans.push_back(t);
    while(t!=s){
        t=par[t];
        ans.push_back(t);
    }
    reverse(ans.begin(),ans.end());
    //for(int i : ans) cout<<i<<" ";
    return ans;
}
