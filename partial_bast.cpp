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
void inorder(BinaryTreeNode<int>* t, vector<int>& v){
    if(t){
        inorder(t->left,v);
        v.push_back(t->data);
        inorder(t->right,v);
    }
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<int> v;
    inorder(root,v);
    if(v.size()==1) return true;
    for(int i=1;i<v.size();i++){
        if(v[i]<v[i-1]) return false;
    }
    return true;
}