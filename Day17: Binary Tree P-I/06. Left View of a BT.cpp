#include <bits/stdc++.h> 
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

void lv(TreeNode<int> *node, int level, vector<int> &ans)
{
    if(node == NULL) return;
    if(level == ans.size()) 
        ans.push_back(node->data);
    lv(node->left, level+1, ans);
    lv(node->right, level+1, ans);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    lv(root, 0, ans);
    return ans;
}
