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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    vector<int> l = getPostOrderTraversal(root->left);
    ans.insert(ans.end(), l.begin(), l.end());

    vector<int> r = getPostOrderTraversal(root->right);
    ans.insert(ans.end(), r.begin(), r.end());

    ans.push_back(root->data);

    return ans;
}
