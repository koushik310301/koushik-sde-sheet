/************************************************************

Following is the Binary Tree node class
    
template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

************************************************************/
#include<bits/stdc++.h>

void preorder(TreeNode<int>* t, int x, int y, map<int,map<int,vector<int>>>& mp){
    if(t){
        mp[x][y].push_back(t->data);
        preorder(t->left,x-1,y+1,mp);
        preorder(t->right,x+1,y+1,mp);
    }
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    
    map<int,map<int,vector<int>>> mp;
    preorder(root,0,0,mp);
    
    for(auto ls1 : mp){
        for(auto ls2 : ls1.second){
            for(auto ls3 : ls2.second){
                ans.push_back(ls3);
            }
        }
    }
    
    return ans;
}