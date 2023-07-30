#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool f(BinaryTreeNode<int> *root, long int lb, long int ub){
    if(root == NULL) return true;
    if(root->data >= ub || root->data <= lb) return false;
    return f(root->left, lb, root->data) && f(root->right, root->data, ub);
}

bool validateBST(BinaryTreeNode<int> *root) {
    return f(root, INT_MIN, INT_MAX);
}
