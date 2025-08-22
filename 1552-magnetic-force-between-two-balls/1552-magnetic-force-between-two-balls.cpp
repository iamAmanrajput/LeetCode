class Solution {
public:
    bool isPossible(vector<int>& position, int mid, int m) {
        int count = 1; // first ball placed at position[0]
        int lastPos = position[0];

        for (int i = 1; i < position.size(); i++) {
            if (position[i] - lastPos >= mid) {
                count++;
                lastPos = position[i];
                if (count == m)
                    return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int start = 1;
        int end = position.back() - position.front();
        int ans = 0;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (isPossible(position, mid, m)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};
