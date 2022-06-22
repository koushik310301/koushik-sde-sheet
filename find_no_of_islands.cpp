#include<bits/stdc++.h>

void dfs(int x, int y, int** arr, int n, int m,vector<vector<int>>& mat)
{
    if(x<0 || x==n || y<0 || y==m || arr[x][y]==0) return ;
    
    if(mat[x][y]==1) return;
    mat[x][y]=1;
    
    
    dfs(x+1,y,arr,n,m,mat);
    dfs(x-1,y,arr,n,m,mat);
    dfs(x,y+1,arr,n,m,mat);
    dfs(x,y-1,arr,n,m,mat);
    dfs(x+1,y+1,arr,n,m,mat);
    dfs(x+1,y-1,arr,n,m,mat);
    dfs(x-1,y+1,arr,n,m,mat);
    dfs(x-1,y-1,arr,n,m,mat);
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int cnt=0;
    vector<vector<int>> mat(n,vector<int>(m,0));
   
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1 && mat[i][j]==0){
                cnt++;
                dfs(i,j,arr,n,m,mat);
            }
        }
    }
    return cnt;
}
