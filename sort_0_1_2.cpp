#include <bits/stdc++.h> 
void sort012(int *nums, int n)
{
   //   Write your code here
    int s=0;
        int m=0;
        int end=n-1;
        while(m<=end){
            if(nums[m]==0){
                swap(nums[m],nums[s]);
                m++;
                s++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[end]);
                end--;
            }
        }
}