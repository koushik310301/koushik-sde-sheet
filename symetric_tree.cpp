/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
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
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
#include<bits/stdc++.h>
void preorder(BinaryTreeNode<int>* root,BinaryTreeNode<int>* ptr){
    if(root){
        ptr=new BinaryTreeNode<int>(root->data);
        preorder(root->left,ptr->right);
        preorder(root->right,ptr->left);
    }
}
bool inorder(BinaryTreeNode<int>* root,BinaryTreeNode<int>* ptr){
    
    if(root==NULL && ptr==NULL) return true;
    if(root==NULL && ptr!=NULL) return false;
    if(root!=NULL && ptr==NULL) return false;
   
    bool res=root->data==ptr->data;
    return res && inorder(root->left,ptr->left) && inorder(root->right,ptr->right);
}
void print(BinaryTreeNode<int>* ptr){
    if(ptr){
        cout<<ptr->data<<" ";
        print(ptr->left);
        print(ptr->right);
    }
}
bool isIdentical(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2){
    if(root1==NULL || root2==NULL) return root1==root2;
    return root1->data==root2->data && isIdentical(root1->left,root2->right);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(!root) return true;
    return isIdentical(root->left, root->right);
    
}