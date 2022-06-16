/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
#include<bits/stdc++.h>
void inorder(BinaryTreeNode<int>* root,vector<BinaryTreeNode<int>*>& v){
    if(root){
        inorder(root->left,v);
        v.push_back(root);
        inorder(root->right,v);
    }
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    if(root==NULL || (root->left==NULL && root->right==NULL)) return root;
    vector<BinaryTreeNode<int>*> v;
    inorder(root,v);
    for(int i=1;i<v.size()-1;i++){
        v[i]->right=v[i+1];
        v[i]->left=v[i-1];
    }
    v[0]->right=v[1];
    v[0]->left=NULL;
    v.back()->right=NULL;
    v.back()->left=v[v.size()-2];
    return v[0];
    
}