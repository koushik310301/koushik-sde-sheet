/*************************************************************
 
    Following is the Binary Tree node structure.

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
void preorder(BinaryTreeNode<int>* t, int x, int y, map<int,map<int,vector<int>>>& mp){
    if(t){
        mp[x][y].push_back(t->data);
        preorder(t->left,x-1,y+1,mp);
        preorder(t->right,x+1,y+1,mp);
    }
}

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    map<int,map<int,vector<int>>> mp;
    preorder(root,0,0,mp);
    
    for(auto ls1 : mp){
        vector<int> v;
        for(auto ls2 : ls1.second){
            for(auto ls3 : ls2.second){
                v.push_back(ls3);
            }
        }
        ans.push_back(v.back());
    }
    
    
    
    return ans;
    
}
