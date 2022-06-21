#include<bits/stdc++.h>
int atoi(string str) {
    // Write your code here.
    if(str.length()==0) return 0;
   
    long long t=1;
    long long num=0;
    for(int i=str.length()-1;i>=0;i--){
        if(int(str[i])>=48 && int(str[i])<=57){
            int u=str[i]-'0';
            num=num+t*u;
            t=t*10;
        }
    }
    if(str[0]=='-') num=num*-1;
    return num;
}