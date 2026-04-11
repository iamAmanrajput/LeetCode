class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char d) {
        this->data = d;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// Insert word into Trie
void insertWord(TrieNode* root, string word) {
    if (word.length() == 0) {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';

    TrieNode* child;

    if (root->children[index] != NULL) {
        child = root->children[index];
    } else {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insertWord(child, word.substr(1));
}

class Solution {

    // DFS to collect max 3 suggestions
    void storeSuggestions(TrieNode* curr, vector<string>& temp,
                          string& prefix) {

        // stop if already 3 suggestions collected
        if (temp.size() == 3)
            return;

        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {

            // early stop if 3 suggestions found
            if (temp.size() == 3)
                return;

            int index = ch - 'a';
            TrieNode* next = curr->children[index];

            if (next != NULL) {
                prefix.push_back(ch);
                storeSuggestions(next, temp, prefix);
                prefix.pop_back(); // backtrack
            }
        }
    }

    vector<vector<string>> getSuggestions(TrieNode* root, string input) {

        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < input.size(); i++) {

            char lastch = input[i];
            prefix.push_back(lastch); // update prefix

            int index = lastch - 'a';
            TrieNode* curr = prev->children[index];

            if (curr == NULL) {
                // fill remaining with empty lists
                while (i < input.size()) {
                    output.push_back({});
                    i++;
                }
                break;
            } else {
                vector<string> temp;

                storeSuggestions(curr, temp, prefix);

                output.push_back(temp);
                prev = curr;
            }
        }
        return output;
    }

public:
    vector<vector<string>> suggestedProducts(vector<string>& products,
                                             string searchWord) {

        // sort for lexicographical order
        sort(products.begin(), products.end());

        TrieNode* root = new TrieNode('-');

        // insert all products
        for (int i = 0; i < products.size(); i++) {
            insertWord(root, products[i]);
        }

        return getSuggestions(root, searchWord);
    }
};