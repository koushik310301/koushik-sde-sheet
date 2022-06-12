/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

#include<bits/stdc++.h>

void inorder(BinaryTreeNode<int>* t,vector<int>& ans){
    if(t){
        inorder(t->left,ans);
        ans.push_back(t->data);
        inorder(t->right,ans);
    }
}
void preorder(BinaryTreeNode<int>* t,vector<int>& ans){
    if(t){
        ans.push_back(t->data);
        preorder(t->left,ans);
        preorder(t->right,ans);
    }
}
void postrder(BinaryTreeNode<int>* t,vector<int>& ans){
    if(t){
        postrder(t->left,ans);
        postrder(t->right,ans);
        ans.push_back(t->data);
    }
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> v1;
    preorder(root,v1);
    
    vector<int> v2;
    inorder(root,v2);
    
    vector<int> v3;
    postrder(root,v3);
    
    ans.push_back(v2);
    ans.push_back(v1);
    ans.push_back(v3);
    
    return ans;
}