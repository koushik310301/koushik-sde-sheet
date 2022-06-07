#include <bits/stdc++.h> 
void setZeros(vector<vector<int>> &matrix)
{
	// Write your code here.
    vector<vector<int>> v;
    int m=matrix.size();
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==0){
                vector<int> tmp;
                tmp.push_back(i);
                tmp.push_back(j);
                v.push_back(tmp);
            }
        }
    }
    for(auto ls : v){
        int r=ls[0];
        int c=ls[1];
        
        //set row 0
        for(int i=0;i<n;i++){
            matrix[r][i]=0;
        }
        for(int i=0;i<m;i++){
            matrix[i][c]=0;
        }
    }
}