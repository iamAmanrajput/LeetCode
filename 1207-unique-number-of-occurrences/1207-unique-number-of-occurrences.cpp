class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {

        unordered_map<int, int> freq;

        // Step 1: Count frequency of each number
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> seen; // set only contain unique value

        // Step 2: Check if any frequency is repeated
        for (auto pair : freq) {
            int count = pair.second;
            if (seen.count(count)) { // count method check the duplicate
                return false; // duplicate frequency found
            }
            seen.insert(count);
        }

        return true; // all frequencies are unique
    }
};
