#include <bits/stdc++.h> 
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
TreeNode<int> *build(vector<int> &arr, int &i, int ub){
    if(i==arr.size() || arr[i]>ub) return NULL;

    TreeNode<int> *root = new TreeNode<int>(arr[i++]);
    root->left = build(arr, i, root->data);
    root->right = build(arr, i, ub);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    int i=0;
    return build(preOrder, i, INT_MAX);
}
