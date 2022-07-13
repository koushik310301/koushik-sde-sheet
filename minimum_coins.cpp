#include<bits/stdc++.h>
// int fun(int ind, int tg, vector<int>& deno, int n, vector<int>& v){
//     if(tg==0){
//         return v.size();
//     }
//     int res1=INT_MAX;
//     if(tg>=deno[ind]){
//         v.push_back(deno[ind]);
//         res1=fun(ind,tg-deno[ind],deno,n,v);
//     }
//     int res2=fun(ind+1,tg,deno,n,v);
//     return min(res1,res2);
    
    
// }
int findMinimumCoins(int amt) 
{
    // Write your code here
    vector<int> deno={1,2,5,10,20,50,100,500,1000};
    int n=deno.size();
    int ans=0;
   // int i=n-1;
//     while(amt>0){
//         amt=amt/deno[i]
//     }
    for(int i =n-1;i>=0;i--){
        ans+=(amt/deno[i]);
        amt=(amt%deno[i]);
        //cout<<amt<<"---"<<ans<<endl;
    }
    return ans;
}
