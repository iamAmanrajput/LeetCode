class Solution {
public:
    bool compare(string& w1, string& w2, unordered_map<char, int>& rank) {
        int n = w1.size();
        int m = w2.size();
        int len = min(n, m);

        for (int i = 0; i < len; i++) {
            if (w1[i] != w2[i]) {
                return rank[w1[i]] < rank[w2[i]];
            }
        }

        // agar prefix case hai (apple vs app)
        return n <= m;
    }

    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> rank;

        for (int i = 0; i < order.size(); i++) {
            rank[order[i]] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) { 
            string s1 = words[i];
            string s2 = words[i+1];
            if (!compare(s1, s2, rank)) {        
                return false;
            }
        }
        return true;
    }
};
