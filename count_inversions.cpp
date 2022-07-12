#include <bits/stdc++.h> 

long long merge(long long *arr, vector<long long>& tmp,int left,int mid ,int right){
    int i,j,k;
    long long ans=0;
    
    i=left;
    j=mid;
    k=left;
    
    while((i<=mid-1) && (j<=right)){
        if(arr[i]<=arr[j]){
            tmp[k++]=arr[i++];
        }
        else{
            tmp[k++]=arr[j++];
            ans+=(mid-i);
        }
    }
    
    while(i<=mid-1){
        tmp[k++]=arr[i++];
    }
    
     while(j<=right){
        tmp[k++]=arr[j++];
    }
    
    for(int i=left;i<=right;i++){
        arr[i]=tmp[i];
    }
    
    
    return ans;
}


long long mergeSort(long long *arr, vector<long long>& tmp,int n, int left, int right){
    long long ans=0;
    if(right>left){
        int mid=(left+right)/2;
        ans+=mergeSort(arr,tmp,n,left,mid);
        ans+=mergeSort(arr,tmp,n,mid+1,right);
        ans+=merge(arr,tmp,left,mid+1,right);
    }
    return ans;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    vector<long long> tmp(n);
    long long ans=mergeSort(arr,tmp,n,0,n-1);
    return ans;
    
}