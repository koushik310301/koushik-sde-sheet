// // #include<bits/stdc++.h>
// double mult(double mid, int n){
//     double ans=1.0;
//     for(int i=0;i<n;++i){
//         ans=ans*mid;
//     }
//     return ans;
// }
// double findNthRootOfM(int n, long long m) {
// 	// Write your code here.
//    double lo=1;
//    double hi=m;
//    double preci=1e-7;
//    double mid;
//    while(hi-lo>preci)
//    {
//        mid=(hi+lo)/2.0;
//        if(mult(mid,n)<m){
//            lo=mid;
//        }
//        else{
//            hi=mid;
//        }
//    }
//     return lo;
// }
double findNthRootOfM(int n, long long m) {
    double low=1,high=m,esp=1e-9;
    
    while((high -low)>esp){
        double mid=(low+high)/2.00000000;
    
        if(pow(mid,n) < m){
            low=mid;
        }
        else{
            high=mid;
        }
    }
    return low;
}




