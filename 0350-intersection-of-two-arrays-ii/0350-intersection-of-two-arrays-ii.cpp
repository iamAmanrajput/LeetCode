class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // hamesha chhoti array ko hashmap me store karenge (space optimize)
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int, int> mp;
        vector<int> ans;

        // nums1 ke frequency store karo
        for (int num : nums1) {
            mp[num]++;
        }

        // nums2 traverse karke check karo
        for (int num : nums2) {
            if (mp[num] > 0) {
                ans.push_back(num);
                mp[num]--;
            }
        }
        return ans;
    }
};
