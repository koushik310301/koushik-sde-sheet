#include<bits/stdc++.h>
void fun(vector<char>& arr, vector<char>& v,int cnt,vector<string>& fans){
    int n=arr.size();
    string ans="";
    if(cnt==n){
        for(auto i : v) ans+=i;
        fans.push_back(ans);
        return ;
    }
    
    for(int i=0;i<n;i++){
        if(v[i]=='#'){
            v[i]=arr[cnt];
            fun(arr,v,cnt+1,fans);
            v[i]='#';
        }
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
        int n=s.length();
        vector<char> v(n,'#');
        vector<string> fans;
    
        vector<char> arr(n,'#');
        for(int i=0;i<s.length();i++){
            arr[i]=s[i];
        }
    
        int cnt=0;
        for(int i=0;i<n;i++){
            if(v[i]=='#'){
                v[i]=arr[cnt];
                fun(arr,v,cnt+1,fans);
                v[i]='#';
            }
        }
    return fans;
}