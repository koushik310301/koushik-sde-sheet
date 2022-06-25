/************************************************************

    Following is the TreeNode class structure:

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
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void preorder(BinaryTreeNode<int>* t, vector<int>& v){
    if(t){
        preorder(t->left,v);
        v.push_back(t->data);
        preorder(t->right,v);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    
    vector<int> v;
    preorder(node,v);
    int prev=-1;
    int i=0;
    while(i<v.size() && x>v[i]){
        i++;
    }
    if(i==v.size()) return -1;
    return v[i];
}