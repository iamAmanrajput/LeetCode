class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }

        string word = "abc";
        int pos = s.find(word);
        if (pos != string::npos) {
            s.erase(pos, word.length());
            return isValid(s);
        } else {
            return false;
        }
    }
};