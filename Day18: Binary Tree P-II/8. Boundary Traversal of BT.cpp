bool isLeaf(TreeNode<int> *root) {
  return !root -> left && !root -> right;
}

void addLB(TreeNode<int> *root, vector<int> &res){
    TreeNode<int> *cur = root->left;

    while (cur) {
        if (!isLeaf(cur)) res.push_back(cur->data);
        if (cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

void addRB(TreeNode<int> *root, vector<int> &res){
    TreeNode<int> *cur = root->right;
    vector<int> temp;
    while(cur){
        if(!isLeaf(cur)) temp.push_back(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
    for(int i=temp.size()-1; i>=0; --i){
        res.push_back(temp[i]);
    }
}

void addleaves(TreeNode<int> *root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left) addleaves(root->left, res);
    if(root->right) addleaves(root->right, res);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    vector<int> res;
    if(!root) return res;
    if(!isLeaf(root)) res.push_back(root->data);

    addLB(root, res);
    addleaves(root, res);
    addRB(root, res);
    return res;
}
