/*
    Time Complexity : O(N * (2 ^(N - 1))
    Space Complexity :  O(26 * K * | word |)

    Where N is the length of sentence, 'K' is the number of words in the dictionary and | word | is the length of each word. 
    
*/

class TrieNode
{

public:
    TrieNode *children[26];
    bool isTerminal;

    TrieNode()
    {
        // Setting all children of a new trie node to NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insert(TrieNode *root, string word)
{
    TrieNode *curr = root;
    for (int i = 0; i < word.size(); i++)
    {
        // Expanding the Trie if the branch was not there yet
        if (curr->children[word[i] - 'a'] == NULL)
        {
            curr->children[word[i] - 'a'] = new TrieNode();
        }
        curr = curr->children[word[i] - 'a'];
    }
    // Mark last node as leaf
    curr->isTerminal = true;
}

void search(TrieNode *root, string &s, vector<string> &res, string temp, int pos)
{
    TrieNode *curr = root;

    for (int i = pos; i < s.size(); i++)
    {
        if (curr->children[s[i] - 'a'] == NULL)
        {
            return;
        }
        if (curr->children[s[i] - 'a']->isTerminal == true)
        {
            // Last word we found with a positive lookup
            string lastWord = temp;
            lastWord.append(s.substr(pos, i - pos + 1));

            // If it is also the last character of s, update res
            if (i == s.size() - 1)
            {
                res.push_back(lastWord);
            }
            // Recursive calls otherwise
            else
            {
                search(root, s, res, lastWord + " ", i + 1);
            }
        }
        curr = curr->children[s[i] - 'a'];
    }
    return;
}

vector<string> getAllValidSentences(string &s, vector<string> &dict)
{
    // Base Trie
    TrieNode *root = new TrieNode();

    // Add dictionary words into trie
    for (int i = 0; i < dict.size(); i++)
    {
        insert(root, dict[i]);
    }

    // Computing the final result
    vector<string> res;
    search(root, s, res, "", 0);

    return res;
}
