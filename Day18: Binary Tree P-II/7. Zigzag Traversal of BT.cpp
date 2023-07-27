vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // flag = 1 => left - right
    // flag = 0 => right - left
    vector<int> res;
    if(root == NULL) return res;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool flag = 1;

    while(!q.empty()){
        int n = q.size();
        vector<int> row(n);
        
        for(int i=0; i<n; i++){
            BinaryTreeNode<int> *node = q.front();
            q.pop();

            // find the idx to fill node's val in ans/ row
            int id = (flag) ? i : n-i-1;
            row[id] = node->data;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        flag = !flag;
        res.insert(res.end(), row.begin(), row.end());
    }
    return res;
}
