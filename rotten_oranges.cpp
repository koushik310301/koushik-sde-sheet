#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here.
    queue<pair<int,int>> q;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
        }
    }
    
    while(q.empty()==false){
        ans++;
        int sz=q.size();
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            if(x+1<n && y>=0 && y<m){
                if(grid[x+1][y]==1) {
                    grid[x+1][y]=2; 
                    q.push({x+1,y});   
                }
            }
            if(x-1>=0 && y>=0 && y<m){
                if(grid[x-1][y]==1){
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    
                }
            }
            if(y+1<m && x>=0 && x<n){
                if(grid[x][y+1]==1){ 
                    grid[x][y+1]=2;
                    q.push({x,y+1});}
            }
            if(y-1>=0 && x>=0 && x<n){
                if(grid[x][y-1]==1) {
                    grid[x][y-1]=2;
                    q.push({x,y-1});}
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1) return -1;
        }
    }
    if(ans==0) return ans;
    return ans-1;
}