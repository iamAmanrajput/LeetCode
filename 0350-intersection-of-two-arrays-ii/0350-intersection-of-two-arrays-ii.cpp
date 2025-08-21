class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<int> ans;

        unordered_map<int, int> mp;
        if (size1 > size2) {
            for (int i = 0; i < nums1.size(); i++) {
                mp[nums1[i]]++;
            }

            for (int i = 0; i < nums2.size(); i++) {
                if (mp[nums2[i]]) {
                    ans.push_back(nums2[i]);
                    mp[nums2[i]]--;
                }
            }

        } else {
            for (int i = 0; i < nums2.size(); i++) {
                mp[nums2[i]]++;
            }

            for (int i = 0; i < nums1.size(); i++) {
                if (mp[nums1[i]]) {
                    ans.push_back(nums1[i]);
                    mp[nums1[i]]--;
                }
            }
        }
        return ans;
    }
};