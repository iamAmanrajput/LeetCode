class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int cnt[3] = {0};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {
            cnt[s[right] - 'a']++;

            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                ans += (n - right);
                cnt[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};