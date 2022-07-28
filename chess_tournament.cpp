#include<bits/stdc++.h>
bool isPossible(vector<int>& pos, int mid, int k , int n){
    int cc=1;
    int lastpos=pos[0];
    for(int i=0;i<n;i++){
        if(pos[i]-lastpos>=mid){
            cc++;
            if(cc==k) return true;
            lastpos=pos[i];
        }
    }
    return false;
}
int chessTournament(vector<int> pos , int n ,  int k){
	// Write your code here
    sort(pos.begin(),pos.end());
    int s=0;
    int e=pos.back();
    int ans=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(isPossible(pos,mid,k,n)){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}