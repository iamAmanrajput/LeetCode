class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       
    if (strs.size() == 1)
        return strs[0]; // Agar sirf ek string hai, wahi prefix hoga

    // Sorting se first aur last string lexicographically sabse alag hongi
    sort(strs.begin(), strs.end());

    string common = ""; // Common prefix store karne ke liye
    int n = strs.size();
    string first = strs[0], last = strs[n - 1]; // Pehli aur aakhri string le rahe hain

    // Dono strings ka common prefix find karna hai
    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] != last[i])
        { // Jaise hi mismatch mile, break kar do
            return common;
        }
        common += first[i]; // Common character ko add karo
    }

    return common; // Final common prefix return karo
    }
};