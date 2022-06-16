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

int height(TreeNode<int> *root,int & ans){
    if(root==NULL) return 0;
    int l=height(root->left,ans);
    int r=height(root->right,ans);
    ans=max(ans,l+r);
    return 1+max(l,r);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans=0;
    height(root,ans);
    return ans;
    
}
