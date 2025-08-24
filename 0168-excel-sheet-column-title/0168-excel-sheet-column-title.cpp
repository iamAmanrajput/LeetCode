class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";
        while (columnNumber > 0) {
            columnNumber--; // Adjust because Excel columns are 1-based, not 0-based
            char c = 'A' + (columnNumber % 26);
            result = c + result; // Prepend the character
            columnNumber /= 26;
        }
        return result;
    }
};
