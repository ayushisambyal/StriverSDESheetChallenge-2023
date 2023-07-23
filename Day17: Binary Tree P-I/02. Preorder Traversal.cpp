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
    if(root == NULL) return ans;

    ans.push_back(root->data);

    vector<int> l = getPreOrderTraversal(root->left);
    ans.insert(ans.end(), l.begin(), l.end());

    vector<int> r = getPreOrderTraversal(root->right);
    ans.insert(ans.end(), r.begin(), r.end());

    return ans;
}
