class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Prefix sum of:
        // target -> +1
        // others -> -1
        int offset = n + 2;
        int size = 2 * n + 5;

        vector<int> bit(size, 0);

        auto update = [&](int idx) {
            while (idx < size) {
                bit[idx]++;
                idx += idx & -idx;
            }
        };

        auto query = [&](int idx) {
            int sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & -idx;
            }
            return sum;
        };

        long long ans = 0;
        int prefix = 0;

        // Empty prefix
        update(offset);

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            // Count previous prefix sums smaller than current prefix
            ans += query(prefix + offset - 1);

            update(prefix + offset);
        }

        return (int)ans;
    }
};