#include<bits/stdc++.h>
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    int n=vertex;
    vector<vector<int>> mat(n,vector<int>(n,0));
    for(auto ls : edges){
        mat[ls.first][ls.second]=1;
        mat[ls.second][ls.first]=1;
    }
    queue<int> q;
    vector<int> vis(n,0);
    q.push(0);
    for(int k=0;k<n;k++){
        if(vis[k]==0){
            while(q.empty()==false){
                int x=q.front();
                ans.push_back(x);
                q.pop();
                vis[x]=1;
                for(int i=0;i<n;i++){
                    if(vis[i]==0 && mat[x][i]==1) q.push(i);
                }
            }
        }
    }
    cout<<ans.size<<endl;
    for(int i : ans) cout<<i<<" ";
    return ans;
}