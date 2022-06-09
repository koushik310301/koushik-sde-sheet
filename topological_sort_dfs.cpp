#include<bits/stdc++.h>
void dfs(unordered_map<int,list<int>>& adj,vector<int>& vis,stack<int>& st,int n, int src){
    vis[src]=1;
    for(int i : adj[src]){
        if(vis[i]==0){
            dfs(adj,vis,st,n,i);
        }
    }
    st.push(src);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int n, int e)  {
    // Write your code here
    stack<int> st;
    unordered_map<int,list<int>> adj;
    for(auto ls : edges){
        adj[ls[0]].push_back(ls[1]);
    }
    vector<int> vis(n,0);
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            dfs(adj,vis,st,n,i);
            //st.push(i);
        }
    }
    while(st.empty()==false){
        ans.push_back(st.top());
        st.pop();
    }
    //reverse(ans.begin(),ans.end());
    //for(int i : ans) cout<<i<<" ";
    return ans;
}