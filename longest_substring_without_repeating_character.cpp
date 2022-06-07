//longest_substring_without_repeating_character
#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    int ans=0;
        int i=-1;
        int j=-1;
        int n=s.length();
        map<char,int> mp;
        while(true){
            bool f1=false;
            bool f2=false;
            while(i<n-1){
                f1=true;
                i++;
                mp[s[i]]++;
                if(mp[s[i]]==2) break;
                else{
                    ans=max(ans,i-j);
                }
            }
            
            
            
            while(j<i){
                f2=true;
                j++;
                mp[s[j]]--;
                if(mp[s[j]]==1) break;
            }
            
            if(f1==false && f2==false) break;
        }
        return ans;
    
    
}