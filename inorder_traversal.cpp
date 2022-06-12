/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
#include<bits/stdc++.h>
void inorder(TreeNode* t,vector<int>& ans){
    if(t){
        
        inorder(t->left,ans);
        ans.push_back(t->data);
        inorder(t->right,ans);
    }
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorder(root,ans);
    return ans;
}