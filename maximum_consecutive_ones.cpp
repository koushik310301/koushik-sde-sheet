#include<bits/stdc++.h>
int longestSubSeg(vector<int> &nums , int n, int k){
    // Write your code here.
    int ans=0;
        deque<int> dq;
        int zc=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zc++;
            
            if(zc>k){
                int x=dq.size();
                
                ans=max(ans,x);
                while(dq.empty()==false && dq.front()!=0){
                    dq.pop_front();
                }
                zc--;
                dq.pop_front();
                dq.push_back(nums[i]);
            }
            else{
                dq.push_back(nums[i]);
            }
        }
        int x=dq.size();
                
                ans=max(ans,x);
        return ans;
}
