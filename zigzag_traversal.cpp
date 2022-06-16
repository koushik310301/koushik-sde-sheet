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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<int> ans;
    vector<vector<int>> v;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int>*> q;
    
    q.push(root);
    while(q.empty()==false)
    {
        int sz=q.size();
        vector<int> tmp;
        for(int i=0;i<sz;i++){
            auto node=q.front();
            tmp.push_back(node->data);
            q.pop();
            if(node->left!=NULL)  q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            
        }
        v.push_back(tmp);
    }
    for(int i=0;i<v.size();i++){
        if(i%2){
            reverse(v[i].begin(),v[i].end());
        }
        for(int x : v[i]) ans.push_back(x);
    }
    return ans;
}
