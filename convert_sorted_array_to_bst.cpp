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
TreeNode<int>* build(int st, int end, vector<int>& arr, int n){
    if(st>end) return NULL;
    if(st==end) return new TreeNode<int>(arr[st]);
    
    int mid = (st+end)/2;
    
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left=build(st,mid-1,arr,n);
    root->right=build(mid+1,end,arr,n);
    
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return build(0,n-1,arr,n);
}