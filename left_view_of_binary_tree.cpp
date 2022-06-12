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

vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    if(root==NULL) return {};
    vector<vector<int>> ans;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.empty()==false){
        int sz=q.size();
        vector<int> v;
        for(int i=0;i<sz;i++){
            auto node=q.front();
            q.pop();
            v.push_back(node->data);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        ans.push_back(v);
    }
    vector<int> fans;
    for(int i=0;i<ans.size();i++){
        fans.push_back(ans[i][0]);
    }
    return fans;
}