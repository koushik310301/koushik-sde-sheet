int fun(int i, int j, string& s1, string& s2, int n, int m,vector<vector<int>>& dp){
    
   
    
    if(i<0){
        return j+1;
    }
    
    if(j<0){
        return i+1;
    }
    
     if(dp[i][j]!=-1) return dp[i][j];
    
    if(s1[i]==s2[j]){
        return 0+fun(i-1,j-1,s1,s2,n,m,dp);
    }
    
    //insert
    int res1=fun(i,j-1,s1,s2,n,m,dp);
    //selete
    int res2=fun(i-1,j,s1,s2,n,m,dp);
    //replcae
    int res3=fun(i-1,j-1,s1,s2,n,m,dp);
    
    return dp[i][j]=1+min(res1,min(res2,res3));
    
    
}
int editDistance(string s1, string s2)
{
    //write you code here
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return fun(n-1,m-1,s1,s2,n,m,dp);
}