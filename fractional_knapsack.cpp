// #include<bits/stdc++.h>
// int fun(int ind, int w,vector<pair<int, int>>& items, int n){
//     if(w<=0) return 0;
//     if(ind==n){
//         return 0;
//     }
    
//     int pick=0;
//     if(w>=items[ind].first){
//         pick=items[ind].second+fun(ind+1,w-items[ind].first,items,n);
//     }
//     int npick=fun(ind+1,w,items,n);
//     return max(pick,npick);
    
    
// }
// double maximumValue (vector<pair<int, int>>& items, int n, int w)
// {
//     // Write your code here.
//     // ITEMS contains {weight, value} pairs.
//     return (double)fun(0,w,items,n);
    
// }
#include<bits/stdc++.h>
bool compare(pair<int,int> v1,pair<int,int> v2){
    if((double)v1.second/(double)v1.first > (double)v2.second/(double)v2.first )return true;
    else return false;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),compare);
    double maxi=0;
    for(int i=0;i<n;i++){
        if(w==0)break;
        if(w>=items[i].first){
            maxi+=items[i].second;
            w=w-items[i].first;
        }
        else{maxi+=((double)w/(double)items[i].first)*(double)items[i].second;
            w=0;}
    }
    return maxi;
}