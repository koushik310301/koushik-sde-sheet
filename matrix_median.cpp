#include<bits/stdc++.h>
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
    
    vector<int> v;
    for(int i=1;i<n;i++){
        for(int j=m-1;j>=0;j--){
            matrix[0].push_back(matrix[i][j]);
        }
    }
    sort(matrix[0].begin(),matrix[0].end());
    n=matrix[0].size()/2;
    return matrix[0][n];
    
}