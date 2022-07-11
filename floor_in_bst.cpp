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
void inorder(TreeNode<int>* root, vector<int>& v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
}
int floorInBST(TreeNode<int> * root, int k)
{
    // Write your code here
    vector<int> v;
    inorder(root,v);
    int ans=-1;
    for(auto i : v){
        if(i>k){
            break;
        }
        ans=i;
    }
    return ans;
}