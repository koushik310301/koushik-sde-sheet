/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        int sz=q.size();
        vector<BinaryTreeNode<int>*> v;
        for(int i=0;i<sz;i++){
            auto tmp=q.front();
            q.pop();
            v.push_back(tmp);
            if(tmp->left!=NULL) q.push(tmp->left);
            if(tmp->right!=NULL) q.push(tmp->right);
        }
        for(int i=0;i<sz-1;i++){
            v[i]->next=v[i+1];
        }
        v.back()->next=NULL;
    }
    
    
}