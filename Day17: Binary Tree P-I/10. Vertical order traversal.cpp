vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    if (!root) return {};

    map<int, map<int, vector<int>>> mp;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        TreeNode<int>* node = it.first;
        int v = it.second.first; // vertical distance
        int l = it.second.second; // level

        // Store the value of the node at the current vertical and level position
        mp[v][l].push_back(node->data);

        if (node->left)
            q.push({node->left, {v - 1, l + 1}});
        if (node->right)
            q.push({node->right, {v + 1, l + 1}});
    }

    vector<int> res;
    for (auto x : mp) {
        for (auto y : x.second) {
            res.insert(res.end(), y.second.begin(), y.second.end());
        }
    }

    return res;
}
