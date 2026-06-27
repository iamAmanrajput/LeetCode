class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        int max_len = 0;

        // Handle the edge case for 1 separately
        if (counts.count(1)) {
            int count1 = counts[1];
            max_len = (count1 % 2 == 0) ? count1 - 1 : count1;
        }

        // Check for all other bases > 1
        for (auto& [val, count] : counts) {
            if (val == 1) continue;

            long long current = val;
            int current_len = 0;

            while (counts.count(current)) {
                // If we have 2 or more instances, it can either be a peak or part of the body
                if (counts[current] >= 2) {
                    // Update max_len assuming 'current' is the peak element
                    max_len = max(max_len, current_len + 1);
                    
                    // Take 2 elements to extend the body and square the current value
                    current_len += 2;
                    
                    // Prevent potential overflow if current squared exceeds reasonable limits
                    if (current > 1000000) break; 
                    current = current * current;
                } 
                // If we only have 1 instance, it MUST be the peak element
                else if (counts[current] == 1) {
                    max_len = max(max_len, current_len + 1);
                    break;
                }
            }
        }

        return max_len;
    }
};