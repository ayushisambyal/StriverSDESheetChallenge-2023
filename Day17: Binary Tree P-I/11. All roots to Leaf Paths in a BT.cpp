
void helper(BinaryTreeNode<int>* root, vector<int>& currentPath, vector<string>& paths) {
    if (root == NULL) return;

    currentPath.push_back(root->data);

    if (root->left == nullptr && root->right == nullptr) {
        string pathStr;
        for (int num : currentPath) {
            pathStr += to_string(num) + " ";
        }
        paths.push_back(pathStr);
    }

    helper(root->left, currentPath, paths);
    helper(root->right, currentPath, paths);

    currentPath.pop_back();
}

vector<string> allRootToLeaf(BinaryTreeNode<int>* root) {
    vector<string> paths;
    vector<int> currentPath;

    helper(root, currentPath, paths);
    return paths;
}
