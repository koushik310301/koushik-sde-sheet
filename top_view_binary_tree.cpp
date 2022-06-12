/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
// void preorder(TreeNode<int> *t, int x, int y,map<int,int>& mp){
//     if(t){
//         if(mp.find(x)==mp.end()){
//             mp[x]=t->val;
//         }
//         preorder(t->left,x-1,y+1,mp);
//         preorder(t->right,x+1,y+1,mp);
//     }
// }


void preorder(TreeNode<int>* t, int x, int y, map<int,map<int,vector<int>>>& mp){
    if(t){
        mp[x][y].push_back(t->val);
        preorder(t->left,x-1,y+1,mp);
        preorder(t->right,x+1,y+1,mp);
    }
}

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    map<int,map<int,vector<int>>> mp;
    preorder(root,0,0,mp);
    
    for(auto ls1 : mp){
        vector<int> v;
        for(auto ls2 : ls1.second){
            for(auto ls3 : ls2.second){
                v.push_back(ls3);
            }
        }
        ans.push_back(v.front());
    }
    
    
    
    return ans;
}