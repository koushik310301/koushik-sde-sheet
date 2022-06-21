#include<bits/stdc++.h>
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


void preorder(TreeNode<int>* t, int x, vector<int>& v, vector<int>& ans){
    if(t){
        v.push_back(t->data);
        if(t->data==x) ans=v;
        preorder(t->left,x,v,ans);
        preorder(t->right,x,v,ans);
        v.pop_back();
    }
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> v,ans;
    preorder(root,x,v,ans);
    return ans;
}
