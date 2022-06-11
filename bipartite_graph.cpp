#include<bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
    int n=edges.size();
    unordered_map<int,list<int>> adj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(edges[i][j]) adj[i].push_back(j);
        }
    }
    
    
    vector<int> color(n,-1);
    vector<int> vis(n,0);
    queue<int> q;
    color[0]=0;
    q.push(0);
    while(q.empty()==false){
        int front=q.front();
        q.pop();
        for(auto it : adj[front]){
            if(color[front]==color[it]) return false;
            else{
                if(color[front]==0){
                    color[it]=1;
                }
                else{
                    color[it]=0;
                }
                q.push(it);
            }
        }
    }
    
    return true;
    
    
}