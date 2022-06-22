#include <bits/stdc++.h> 

vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
//     next_permutation(permutation.begin(),permutation.end());
//     return permutation;
    int ind=-1;
    for(int i=nums.size()-1;i>0;i--){
        if(nums[i]>nums[i-1]){
            ind=i;
            break;
        }
    }
    if(ind==-1){
        reverse(nums.begin(),nums.end());
        return nums;
    }
    int prev=ind;
    for(int i=ind+1;i<nums.size();i++){
        if(nums[i]>nums[ind-1] && nums[i]<=nums[prev]){
            prev=i;
        }
    }
    swap(nums[ind-1],nums[prev]);
    reverse(nums.begin()+ind,nums.end());
    return nums;
}