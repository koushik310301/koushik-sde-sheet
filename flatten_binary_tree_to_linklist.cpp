/************************************************************

    Following is the TreeNode class structure.

    template <typename T>
    class TreeNode {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void preorder(TreeNode<int> *root,vector<TreeNode<int>*>& v){
    if(root){
        v.push_back(root);
        preorder(root->left,v);
        preorder(root->right,v);
    }
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    vector<TreeNode<int>*> v;
    preorder(root,v);
    int n=v.size();
    if(n==1) return root;
    
    for(int i=1;i<n-1;i++){
        v[i]->right=v[i+1];
        v[i]->left=NULL;
    }
    v[0]->right=v[1];
    v[n-1]->right=NULL;
    v[n-1]->left=NULL;
    return v[0];
}