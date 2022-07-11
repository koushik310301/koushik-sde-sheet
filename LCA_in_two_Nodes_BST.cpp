/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* preorder(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q){
   
    if(root==NULL || root==p || root==q) return root;
    auto n1=preorder(root->left,p,q);
    auto n2=preorder(root->right,p,q);
    
    
    
    if(n1==NULL) return n2;
    else if(n2==NULL) return n1;
    return root;
}
TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q)
{
	// Write your code here
    return preorder(root,p,q);
}
