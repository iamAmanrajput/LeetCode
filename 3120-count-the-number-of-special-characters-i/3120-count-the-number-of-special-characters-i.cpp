class Solution {
public:
    int numberOfSpecialChars(string word) {

        unordered_set<char> lowerCaseLetters;
        unordered_set<char> upperCaseLetters;

        // Traverse string and store lowercase & uppercase separately
        for(char ch : word)
        {
            if(islower(ch))
            {
                lowerCaseLetters.insert(ch);
            }
            else if(isupper(ch))
            {
                // Convert uppercase to lowercase before storing
                upperCaseLetters.insert(tolower(ch));
            }
        }

        int count = 0;

        // Check which lowercase letters exist in uppercase set too
        for(char ch : lowerCaseLetters)
        {
            if(upperCaseLetters.find(ch) != upperCaseLetters.end())
            {
                count++;
            }
        }

        return count;
    }
};