class Solution {
public:
    bool repeatedSubstringPattern(string s) {
       string doubled = s + s;
        // remove first and last char
        string check = doubled.substr(1, doubled.size() - 2);
        return check.find(s) != string::npos;
    }
};