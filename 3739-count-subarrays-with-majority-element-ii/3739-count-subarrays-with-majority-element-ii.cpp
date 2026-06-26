class BinaryIndexedTree {
private:
    int n;
    vector<int> bit;

public:
    BinaryIndexedTree(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        // Prefix sums lie in [-n, n], so shift them by (n + 1)
        BinaryIndexedTree bit(2 * n + 1);

        int prefix = n + 1;
        bit.update(prefix, 1);

        long long ans = 0;

        for (int x : nums) {
            if (x == target)
                prefix++;
            else
                prefix--;

            // Count previous prefix sums smaller than current prefix
            ans += bit.query(prefix - 1);

            bit.update(prefix, 1);
        }

        return ans;
    }
};