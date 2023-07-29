#include<bits/stdc++.h>
/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* f(vector<int> &in, int is, int ie, vector<int>  &post, int ps, int pe, map<int, int> &mp){
     if(ps > pe || is > ie) return NULL;

     TreeNode<int> *root = new TreeNode<int>(post[pe]);
     int ind = mp[post[pe]];
     int numsL = ind - is;

     root->left = f(in, is, ind-1, post, ps, ps+numsL-1, mp);
     root->right = f(in, ind+1, ie, post, ps+numsL, pe-1, mp);
     return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
     int n = inOrder.size();
     map<int, int> mp;

     for(int i=0; i<n; i++){
          mp[inOrder[i]] = i;
     }
     return f(inOrder, 0, n-1, postOrder, 0, n-1, mp);
}
