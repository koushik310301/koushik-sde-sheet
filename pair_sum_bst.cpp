/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
void inorder(BinaryTreeNode<int>* root,vector<int>& v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> v;
    inorder(root,v);
    for(int i=0;i<v.size();i++){
        if(binary_search(v.begin(),v.end(),k-v[i])) return true;
    }
    return false;
}