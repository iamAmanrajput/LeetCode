class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    int childCount;

    TrieNode(char d)
    {
        data = d;

        // initialize all children as NULL
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }

        childCount = 0;      // number of children
        isTerminal = false;  // marks end of word
    };
};

class Solution {
public:

// Insert word into Trie
void insertWord(TrieNode *root, string word)
{
    // if word finished → mark terminal
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';   // mapping a-z → 0-25

    TrieNode *child;

    // if already exists → move ahead
    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        // create new node if not present
        child = new TrieNode(ch);
        root->childCount++;          // increase child count
        root->children[index] = child;
    }

    // recursive call for remaining string
    insertWord(child, word.substr(1));
};

// Find LCP using Trie
void findLcp(string first, string& ans, TrieNode* root){

    // stop if current node is end of any word
    if(root->isTerminal){
        return;
    }

    for(int i = 0; i < first.size(); i++){
        char ch = first[i];

        // continue only if exactly one child exists
        if(root->childCount == 1){
            ans.push_back(ch);

            int index = ch - 'a';   // move to next node
            root = root->children[index];
        }
        else{
            break;  // multiple paths → LCP ends
        } 

        // stop if any word ends here
        if(root->isTerminal){
            break;
        }
    }
};

    string longestCommonPrefix(vector<string>& strs) {

        TrieNode* root = new TrieNode('-');  // root node

        // insert all words into Trie
        for(int i = 0; i < strs.size(); i++){
            insertWord(root, strs[i]);
        }

        string ans = "";
        string first = strs[0];

        // find LCP using first string
        findLcp(first, ans, root);

        return ans;
    }
};