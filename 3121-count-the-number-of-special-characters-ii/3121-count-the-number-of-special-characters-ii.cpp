class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastLower(26, -1);
        vector<int> firstUpper(26, -1);

        for(int i = 0; i < word.size(); i++) {

            if(islower(word[i])) {
                lastLower[word[i] - 'a'] = i;
            }
            else {
                int idx = word[i] - 'A';

                if(firstUpper[idx] == -1)
                    firstUpper[idx] = i;
            }
        }

        int count = 0;

        for(int i = 0; i < 26; i++) {
            if(lastLower[i] != -1 &&
               firstUpper[i] != -1 &&
               lastLower[i] < firstUpper[i]) {

                count++;
            }
        }

        return count;
    }
};