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
#include<bits/stdc++.h>

TreeNode<int>* build(vector<int> &ino, int inoStart, int inoEnd, vector<int> &pro, int proStart, int proEnd, unordered_map<int,int>& mp){
    
    if(inoStart>inoEnd || proStart>proEnd) return NULL;
    
    TreeNode<int>* root= new TreeNode<int>(pro[proStart]);
    
    int ind=mp[root->data];
    int noOfEleOnLeft = ind-inoStart;
    
    root->left=build(ino,inoStart,ind-1,pro,proStart+1,proStart+noOfEleOnLeft,mp);
    root->right=build(ino,ind+1,inoEnd,pro,proStart+noOfEleOnLeft+1,proEnd,mp);
    
    return root;
    
}

TreeNode<int>* preOrderTree(vector<int> &pro){
    // Write your code here.
    unordered_map<int,int> mp;
    vector<int> ino=pro;
    sort(ino.begin(),ino.end());
    for(int i=0;i<ino.size();i++){
        mp[ino[i]]=i;
    }
    return build(ino,0,ino.size()-1,pro,0,pro.size()-1,mp);
}