#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int ans=1;
    int fans=1;
    for(int i=0;i<n-1;i++){
        if(arr[i]+1==arr[i+1]){
            ans++;
        }
        else if(arr[i]==arr[i+1]) continue;
        else{
            fans=max(ans,fans);
            ans=1;
        }
    }
    fans=max(fans,ans);
    return fans;
}