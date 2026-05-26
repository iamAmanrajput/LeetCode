class Solution {
public:
    bool isLowerCase(char ch) {
        if (ch >= 'a' && ch <= 'z')
            return true;

        return false;
    };
    int numberOfSpecialChars(string& word) {

        sort(word.begin(), word.end());

        int count = 0;
        int i = 0;
        int j = i + 1;

        for (int i = 0; i < word.size(); i++) {
            int charA = word[i] - '0' + 32;
            if (isLowerCase(word[i])) {
                break;
            }
            if (word[i] == word[i + 1] && i + 1 <= word.size()) {
                continue;
            }
            for (int j = i + 1; j < word.size(); j++) {
                int charB = word[j] - '0';
                if (charA == charB) {
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};