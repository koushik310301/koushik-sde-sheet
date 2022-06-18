/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    TreeNode<int>* root=new TreeNode<int>(preOrder[0]);
    for(int i=1;i<preOrder.size();i++){
        TreeNode<int>* ptr=root;
         TreeNode<int>* prev=NULL;
        while(ptr!=NULL){
            prev=ptr;
            if(preOrder[i]>ptr->data){
                ptr=ptr->right;
            }
            else{
                ptr=ptr->left;
            }
        }
        if(preOrder[i]>prev->data){
            prev->right=new TreeNode<int>(preOrder[i]);
        }
        else{
            prev->left=new TreeNode<int>(preOrder[i]);
        }
    }
    return root;
}