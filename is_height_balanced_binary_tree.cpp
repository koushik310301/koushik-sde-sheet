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
int height(BinaryTreeNode<int>* t){
    if(t==NULL) return 0;
    int l=0;
    int r=0;
    
    l=height(t->left);
    r=height(t->right);
    
    return 1+max(l,r);
}

bool preorder(BinaryTreeNode<int>* root){
    if(root){
        int lh=height(root->left);
        int rh=height(root->right);
        
        
        return abs(lh-rh)<=1 && preorder(root->right) && preorder(root->left);
    }
    return true;
}


bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root==NULL) return true;
    preorder(root);
}