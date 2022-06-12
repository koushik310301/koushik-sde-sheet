/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>

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
    };

***********************************************************/
void inorder(BinaryTreeNode<int>* t,vector<int>& ans){
    if(t){
        ans.push_back(t->data);
        inorder(t->left,ans);
        inorder(t->right,ans);
    }
}
bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.
    
    if(root1==NULL || root2==NULL) return root1==root2;
    
    if(root1->data!=root2->data) return false;
    
    return identicalTrees(root1->left,root2->left) && identicalTrees(root1->right,root2->right);
}