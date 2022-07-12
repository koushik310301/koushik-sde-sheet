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
class BSTiterator
{
    public:
    TreeNode<int>* pt;
    stack<TreeNode<int>*> s;
    void pushStack(TreeNode<int> *node){
        while(node!=nullptr){
            s.push(node);
            node=node->left;
        }
    }
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pt=root;
        pushStack(pt);
    }

    int next()
    {
        // write your code here
        TreeNode<int>* temp=s.top();
        s.pop();
        pushStack(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        // write your code here
         return !s.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/