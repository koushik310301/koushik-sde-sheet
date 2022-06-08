#include<bits/stdc++.h>
void dfs(vector<vector<int>>& mat,vector<int>& vis,vector<int>& v,int n, int x){
    vis[x]=1;
    v.push_back(x);
    for(int i=0;i<n;i++){
        if(vis[i]==0 && mat[x][i]==1){
            dfs(mat,vis,v,n,i);
        }
    }
    
}
vector<vector<int>> depthFirstSearch(int n, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> ans;
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(auto ls : edges){
        mat[ls[0]][ls[1]]=1;
        mat[ls[1]][ls[0]]=1;
    }
    //int cnt=0;
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        if(vis[i]==0){
            //cnt++;
            vector<int> v;
            dfs(mat,vis,v,n,i);
            ans.push_back(v);
        }
    }
    return ans;
}