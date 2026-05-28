class Solution {
public:

    struct TrieNode {
        vector<pair<char, TrieNode*>> child;
        int idx;

        TrieNode() {
            idx = -1;
        }
    };

    TrieNode* root = new TrieNode();

    bool better(vector<string>& words, int a, int b) {

        if (b == -1)
            return true;

        if (words[a].size() < words[b].size())
            return true;

        if (words[a].size() == words[b].size() && a < b)
            return true;

        return false;
    }

    TrieNode* getChild(TrieNode* node, char c) {

        for (auto &p : node->child) {
            if (p.first == c)
                return p.second;
        }

        return nullptr;
    }

    void insert(string& s, int idx, vector<string>& words) {

        TrieNode* node = root;

        if (better(words, idx, node->idx))
            node->idx = idx;

        for (int i = s.size() - 1; i >= 0; i--) {

            char c = s[i];

            TrieNode* next = getChild(node, c);

            if (!next) {
                next = new TrieNode();
                node->child.push_back({c, next});
            }

            node = next;

            if (better(words, idx, node->idx))
                node->idx = idx;
        }
    }

    int query(string& s) {

        TrieNode* node = root;

        for (int i = s.size() - 1; i >= 0; i--) {

            char c = s[i];

            TrieNode* next = getChild(node, c);

            if (!next)
                break;

            node = next;
        }

        return node->idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (auto &q : wordsQuery) {
            ans.push_back(query(q));
        }

        return ans;
    }
};