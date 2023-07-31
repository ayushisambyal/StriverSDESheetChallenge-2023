#include<bits/stdc++.h>
#include <sstream> 
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
// Encode a tree to a single string
string serializeTree(TreeNode<int> *root)
{
    if (!root) return "";

    string s = "";
    queue<TreeNode<int>*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode<int>* cur = q.front();
        q.pop();

        if (cur == NULL) s.append("#,");
        else {
            s.append(to_string(cur->data) + ",");
            q.push(cur->left);
            q.push(cur->right);
        }
    }
    return s;
}

TreeNode<int>* deserializeTree(string &data)
{
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');

    TreeNode<int> *root = new TreeNode<int>(stoi(str));
    queue<TreeNode<int>*> q;
    q.push(root);
    
    while(!q.empty()){
        TreeNode<int> *node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#") node->left = NULL;
        else{
            TreeNode<int>* leftNode = new TreeNode<int>(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#") node->right = NULL;
        else{
            TreeNode<int> *rightNode = new TreeNode<int>(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
