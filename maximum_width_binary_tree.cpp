/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return 0;
        queue<pair<TreeNode<int>*,long long>> q;
        long long ans=0;
        q.push({root,0});
        while(q.empty()==false){
            
            long long sz=q.size();
            ans=max(ans,sz);
            long long min_ind=q.front().second;
            long long first,last;
            for(long long i=0;i<sz;i++){
                long long curr_ind=q.front().second-min_ind;
                auto node= q.front().first;
                q.pop();

                if(i==0) first= curr_ind;
                if(i==sz-1) last= curr_ind;

                if(node->left) q.push({node->left,2*curr_ind+1});
                if(node->right) q.push({node->right,2*curr_ind+2});


            }
            //ans=max(ans,last-first+1);
        }
    return ans;
}