#include<bits/stdc++.h>
string kthPermutation(int n, int k) {
    // Write your code here.
    string ans="";
    for(int i=1;i<=n;i++){
        ans+=to_string(i);
    }
    
   for(int i=1;i<k;i++){
       next_permutation(ans.begin(),ans.end());
   }
    
    return ans;
    
}
