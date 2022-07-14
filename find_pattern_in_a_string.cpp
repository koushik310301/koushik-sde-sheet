#include<bits/stdc++.h>
void buildPitable(string p, vector<int>& pt)
{
    int index=0;
    for(int i=1;i<p.length();)
    {
        if(p[i]==p[index])
        {
            pt[i]=index+1;
            index++;
            i++;
        }
        else
        {
            if(index!=0)
            {
                index=pt[index-1];    
            }
            else{
                pt[i]=0;
                i++;
            }
        }
    }
}

bool KMP(string s, string p, vector<int>& pt){
    int i=0;
    int j=0;
    
    while(i<s.length() && j<p.length()){
        if(s[i]==p[j]){
            i++;
            j++;
        }
        else{
            if(j!=0){
                j=pt[j-1];
            }
            else{
                i++;
            }
        }
    }
    if(j==p.length()) return true;
    return false;
}



bool findPattern(string p, string s)
{
    // Write your code here.
    vector<int> pt(p.length(),0);
    buildPitable(p,pt);
    return KMP(s,p,pt);
    
}