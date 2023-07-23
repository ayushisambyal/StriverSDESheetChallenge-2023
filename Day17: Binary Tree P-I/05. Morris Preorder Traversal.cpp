#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    TreeNode * cur = root;
    while(cur != NULL){
        // base case 1: if left doesn't exist
        if(cur->left == NULL){
            ans.push_back(cur->data);
            cur = cur-> right;
        }
        // when left exists - threded binary tree
        else{
            TreeNode *temp = cur->left;
            // finding the rightmost node
            while(temp->right && temp->right != cur){
                temp = temp->right;
            }
            // if we reached rightmost - create the thread
            if(temp->right == NULL){
                temp->right = cur;
                ans.push_back(cur->data);
                cur = cur->left; // move left
            }
            // 2nd traversal - time to break threads
            else{
                temp->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}
