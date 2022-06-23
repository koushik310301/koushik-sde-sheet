#include<bits/stdc++.h>

bool isPalindrome(string str){

    int l=0;
    int r=str.length()-1;
    
    while(l<r){
        if(str[l]!=str[r]) return false;
        l++;
        r--;
    }
    
    return true;
}

void fun(string s, string asf,vector<vector<string>>& ans,vector<string>& v){
    if(s.length()==0) {
        ans.push_back(v);
        return;
    }
    
    for(int i=0;i<s.length();i++){
        string prefix=s.substr(0,i+1);
        string ros=s.substr(i+1);
        if(isPalindrome(prefix)){
            v.push_back(prefix);
            fun(ros,asf+prefix,ans,v);
            v.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector<vector<string>> ans;
    vector<string> v;
    fun(s,"",ans,v);
    return ans;
}