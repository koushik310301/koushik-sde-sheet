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

TreeNode<int>* build(int st, int end, vector<int>& ino, vector<int>& pro,vector<int>& rcnt){
    if(st>end) return NULL;
    
    TreeNode<int>* root= new TreeNode<int>(pro[rcnt[0]]);
    rcnt[0]++;
    
    int ind=0;
    for(int i=st;i<=end;i++){
        if(root->data==ino[i]){
            ind=i;
            break;
        }
    }
    root->left=build(st,ind-1,ino,pro,rcnt);
    root->right=build(ind+1,end,ino,pro,rcnt);
    return root;
}


TreeNode<int> *buildBinaryTree(vector<int> &ino, vector<int> &pro)
{
	//    Write your code here
   
   
    
    //return build(ino,0,ino.size()-1,pro,0,pro.size()-1,mp);
    vector<int> rcnt={0};
    return build(0,ino.size()-1,ino,pro,rcnt);
}