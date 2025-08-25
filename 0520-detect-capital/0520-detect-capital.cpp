#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        // Check if all letters are uppercase
        if (all_of(word.begin(), word.end(), ::isupper)) return true;
        
        // Check if all letters are lowercase
        if (all_of(word.begin(), word.end(), ::islower)) return true;
        
        // Check if only first is uppercase and rest are lowercase
        if (isupper(word[0]) && all_of(word.begin() + 1, word.end(), ::islower))
            return true;
        
        return false;
    }
};
