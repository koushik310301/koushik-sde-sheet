#include<bits/stdc++.h>
void fun(vector<vector<int>> &image, int x, int y,int oldColor ,int newColor){
    int m=image.size();
    int n=image[0].size();
    
    if(x>=0 && x<m && y>=0 && y<n && image[x][y]==oldColor){
        image[x][y]=newColor;
        fun(image,x+1,y,oldColor,newColor);
        fun(image,x-1,y,oldColor,newColor);
        fun(image,x,y+1,oldColor,newColor);
        fun(image,x,y-1,oldColor,newColor);
    }
    
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    if(newColor==image[x][y]) return image;
    fun(image,x,y,image[x][y],newColor);
    return image;
}