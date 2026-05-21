class TrieNode {
public:
    TrieNode* child[10];   // digits 0-9 ke liye pointers

    TrieNode() {
        for(int i = 0; i < 10; i++) {
            child[i] = NULL;
        }
    }
};

class Solution {
public:

    // number ko trie me insert karne ka function
    void insert(TrieNode* root, string num) {

        TrieNode* curr = root;

        for(char ch : num) {

            int idx = ch - '0';   // digit ko index me convert

            // agar path exist nahi karta to naya node banao
            if(curr->child[idx] == NULL) {
                curr->child[idx] = new TrieNode();
            }

            // next node pe move karo
            curr = curr->child[idx];
        }
    }


    // check karo given number ka kitna prefix trie me match hota hai
    int searchPrefix(TrieNode* root, string num) {

        TrieNode* curr = root;
        int prefixLen = 0;

        for(char ch : num) {

            int idx = ch - '0';

            // agar digit exist nahi karti to prefix end
            if(curr->child[idx] == NULL) {
                break;
            }

            prefixLen++;          // prefix matched
            curr = curr->child[idx];
        }

        return prefixLen;
    }


    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        // empty trie create
        TrieNode* root = new TrieNode();


        // STEP 1:
        // arr1 ke saare numbers trie me insert karo
        for(int num : arr1) {

            insert(
                root,
                to_string(num)
            );
        }


        int ans = 0;


        // STEP 2:
        // arr2 ke har number ka maximum prefix search karo
        for(int num : arr2) {

            ans = max(
                ans,
                searchPrefix(
                    root,
                    to_string(num)
                )
            );
        }


        return ans;
    }
};