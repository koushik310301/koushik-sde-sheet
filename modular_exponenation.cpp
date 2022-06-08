#include <bits/stdc++.h> 
long long modularExponentiation(long long x, long long n, long long m) {
	// Write your code here.
//     if(n==0) return (x%m);
//     //cout<<x<<"---"<<n<<endl;
//     return ((x%m)*(modularExponentiation(x,n-1,m)%m))%m;
    long long ans=1;
    while(n){
        if(n&1){
            ans=(ans*x)%m;
        }
        x=(x*x)%m;
        n=n>>1;
    }
    return ans;
}