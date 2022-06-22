#include<bits/stdc++.h>
void fun(int n,vector<int>& candidates, int target,vector<int>& v, vector<vector<int>>& ans){
        
        if(n==candidates.size()){
            if(target==0){
                // for(int i : v){
                //     cout<<i<<" ";
                // }cout<<endl;
                sort(v.begin(),v.end());
                ans.push_back(v);
            }
            return;
        }
        
        if(candidates[n]<=target){
            v.push_back(candidates[n]);
            fun(n+1,candidates,target-candidates[n],v,ans);
            v.pop_back();
        }
        
        n++;
        while(n<candidates.size() && candidates[n-1]==candidates[n]){
            n++;
        }
        fun(n,candidates,target,v,ans);
        
        
        
    
    }
vector<vector<int>> combinationSum2(vector<int> &candidates, int n, int target)
{
	    vector<vector<int>> ans;
        vector<int> v;
        sort(candidates.begin(),candidates.end());
        fun(0,candidates,target,v,ans);
        vector<vector<int>> fans;
        for(auto list : ans){
            if(count(fans.begin(),fans.end(),list)==0){
                fans.push_back(list);
            }
        }
        return fans;
}
