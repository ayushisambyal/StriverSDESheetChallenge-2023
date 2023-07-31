#include<bits/stdc++.h>
/*
    Time Complexity : O(N*W) (insert - O(W), search - O(W))
    Where N is the number of queries and W is the average length of input string.

    Space Complexity : O(N*W)
    Where N is the number of words inserted and W is the average length of words.
*/


/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
    
};*/

bool isEmpty(TrieNode* root)                  
{ 
    for (int i = 0; i < 26; i++) {
    	
        if (root->children[i]) {
            return false; 
        }
    }
    return true; 
}

TrieNode* deleteWordHelper(TrieNode* root, string word, int depth){
	
	if(root == NULL){
		return NULL;			
	}

	if(depth == word.size()){                    //Processing last character of word
		
		if(root->isEnd){
			root->isEnd = false;                 //To delete word
		}
		
		if(isEmpty(root)){                       //To check if current node is prefix
			delete(root);
			root = NULL;
		}

		return root;
	}
	
	int index = word[depth] - 'a';               //If not the last character
	
	root->children[index] = deleteWordHelper(root->children[index], word, depth+1); //Recursive call
	
	if(isEmpty(root) && root->isEnd == false){   // If current node does not
		delete (root);                           // have child and also is not
		root = NULL;                             // the end of any word
	}
	
	return root;		
}

TrieNode* solution::deleteWord(TrieNode* root, string word) {
	
	int depth = 0;                               //Maintaining depth variable 

	return deleteWordHelper(root,word,depth);    //Calling recursive function
}


