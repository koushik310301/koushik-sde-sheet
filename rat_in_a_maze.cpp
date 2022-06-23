#include<bits/stdc++.h>
void fun(int x, int y, vector<vector<int>>& maze,vector<vector<int>>& ans,  vector<vector<int>>& mat,int n){
    
    if(x<0 || x==n || y<0 || y==n || maze[x][y]==0 || mat[x][y]==1) return;
    
    if(x==n-1 && y==n-1 && maze[x][y]==1){
        vector<int> tmp;
        mat[x][y]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               tmp.push_back(mat[i][j]);
            }
        }
        mat[x][y]=0;
        ans.push_back(tmp);
        return;
    }
    
    mat[x][y]=1;
    fun(x+1,y,maze,ans,mat,n);
    fun(x,y+1,maze,ans,mat,n);
    fun(x-1,y,maze,ans,mat,n);
    fun(x,y-1,maze,ans,mat,n);
    mat[x][y]=0;
    
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> mat(n,vector<int>(n,0));
    
    
    fun(0,0,maze,ans,mat,n);
    return ans;
}