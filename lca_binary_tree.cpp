#include<bits/stdc++.h>
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

void preorder(TreeNode<int>* t, vector<int>& v, vector<int>& ans, int x){
    if(t){
        v.push_back(t->data);
        if(t->data==x) ans=v;
        preorder(t->left,v,ans,x);
        preorder(t->right,v,ans,x);
        v.pop_back();
    }
}

int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    vector<int> v,ans1,ans2;
    preorder(root,v,ans1,x);
    preorder(root,v,ans2,y);
//     for(int i : ans1) cout<<i<<" ";
//     cout<<endl;
//     for(int i : ans2) cout<<i<<" ";
     int ans;
    int i=0;
    while(i<ans1.size() && i<ans2.size() && ans1[i]==ans2[i]){
        ans=ans1[i];
        i++;
    }
    return ans;
}