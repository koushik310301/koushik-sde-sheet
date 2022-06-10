#include <bits/stdc++.h> 
int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
    unordered_map<int,int> mp;
    for(int i : arr){
        mp[i]++;
        if(mp[i]==2) return i;
    }
    return -1;
}
