#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
	// Write your code here.
    int maj=-1;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt==0){
            maj=arr[i];
            cnt=1;
        }
        else{
            if(arr[i]==maj) cnt++;
            else cnt--;
        }
    }
//     if(cnt>=1) return maj;
    cnt=0;
    for(int i=0;i<n;i++) if(arr[i]==maj) cnt++;
    
    if(cnt>n/2) return maj;
    
    return -1;
}