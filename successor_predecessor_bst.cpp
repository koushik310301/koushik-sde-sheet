/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };->data

*************************************************************/
#include<bits/stdc++.h>
void inorder(BinaryTreeNode<int>* root,vector<int>& v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    vector<int> v;
    pair<int,int> ans;
    inorder(root,v);
    for(int i=0;i<v.size();i++){
        if(v[i]==key){
            if(i-1>=0) ans.first=v[i-1];
            else ans.first=-1;
            if(i+1<v.size()) ans.second=v[i+1];
            else ans.second=-1;
            break;
        }
    }
    return ans;
}
