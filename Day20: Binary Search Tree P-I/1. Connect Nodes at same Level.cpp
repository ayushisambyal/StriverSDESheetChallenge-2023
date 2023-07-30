#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
void connectNodes(BinaryTreeNode< int > *root) {
    if(root==NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty()){
        int size=q.size();

        for(int i=0; i<size-1; i++){
            BinaryTreeNode<int>* t= q.front();
            q.pop();
            t->next=q.front();
            if(t->left) q.push(t->left);
            if(t->right) q.push(t->right);
        }

        BinaryTreeNode<int>* t= q.front();
        q.pop();
        
        if(t->left) q.push(t->left);
        if(t->right) q.push(t->right);
    }
    return;
}
