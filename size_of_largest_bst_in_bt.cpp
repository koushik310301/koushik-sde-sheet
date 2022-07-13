/************************************************************

    Following is the Binary Tree node structure
    
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

class info{
    public:
    int maxi,mini,check,size;
};

info preorder(TreeNode<int>* root,int &ans){
    if(root==NULL){
        return {INT_MIN,INT_MAX,true,0};    
    }
    info left=preorder(root->left,ans);
    info right=preorder(root->right,ans);
    
    info currNode;
    currNode.maxi=max(root->data,right.maxi);
    currNode.mini=min(root->data,left.mini);
    currNode.size=left.size+right.size+1;
    
    if((left.check && right.check) && (root->data>left.maxi && root->data<right.mini)){
        currNode.check=true;
    }
    else{
        currNode.check=false;
    }
    if(currNode.check) ans=max(ans,currNode.size);
    return currNode;
    
}

int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int ans=0;
    preorder(root,ans);
    return ans;
}
