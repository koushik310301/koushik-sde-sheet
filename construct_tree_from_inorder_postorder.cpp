/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* constructTree(vector<int>& in, vector<int>& post, int s, int e, vector<int>& pr){
    if(s>e) return NULL;
    TreeNode<int>* root= new TreeNode<int>(post[pr[0]]);
    pr[0]--;
    
    int x=0;
    for(int i=s;i<=e;i++){
        if(root->data==in[i]){
            x=i;
            break;
        }
    }
    root->right=constructTree(in,post,x+1,e,pr);
    root->left=constructTree(in,post,s,x-1,pr);
    
        
    return root;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& post, vector<int>& in) 
{
	// Write your code here.
    vector<int> pr={in.size()-1};
    return constructTree(in,post,0,in.size()-1,pr);
}
