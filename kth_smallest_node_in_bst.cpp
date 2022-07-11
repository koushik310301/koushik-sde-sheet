/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
void inorder(TreeNode<int> *root,vector<int>& pq){
    if(root){
        inorder(root->left,pq);
        pq.push_back(root->data);
        inorder(root->right,pq);
    }
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    vector<int> pq;
    inorder(root,pq);
    return pq[k-1];
}