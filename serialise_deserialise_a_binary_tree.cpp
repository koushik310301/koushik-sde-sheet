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
#include<bits/stdc++.h>
string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    if(root==NULL) return "";
        string ans="";
        queue<TreeNode<int>*> q;
        q.push(root);
        while(q.empty()==false){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                if(node==NULL) ans+="#,";
                else{
                    ans+=(to_string(node->data)+',');
                }
                if(node!=NULL){
                    q.push(node->left);
                    q.push(node->right);
                }
            }
           
        }
        ans.pop_back();
        //cout<<ans<<endl;
        return ans;

}

TreeNode<int>* deserializeTree(string &data)
{
 //    Write your code here for deserializing the tree
     if(data.length()==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode<int>* root= new TreeNode<int>(stoi(str));
        queue<TreeNode<int>*> q;
        q.push(root);
        while(q.empty()==false){
            TreeNode<int>* node=q.front();
            q.pop();
            
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }
            else{
                TreeNode<int>* leftNode=new TreeNode<int>(stoi(str));
                node->left=leftNode;
                q.push(leftNode);
            }
            
            
            
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }
            else{
                TreeNode<int>* rightNode=new TreeNode<int>(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
            
            
        }
        return root;

}



