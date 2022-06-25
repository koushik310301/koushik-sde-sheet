#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
     vector<int> ans;
        deque<int> dq;
        for(int i=0;i<nums.size();i++){
            //out of bound case
            if(dq.empty()==false && dq.front()==i-k) dq.pop_front();
            
            //nge concept
            while(dq.empty()==false && nums[i]>nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            
            
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
}