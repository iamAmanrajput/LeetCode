class Solution {
public:
    int minElement(vector<int>& nums) {
        int minElement = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int currAns = 0;
            while (num) {
                int lastDig = num % 10;
                currAns = lastDig + currAns;
                num = num / 10;
            }
            if (minElement > currAns) {
                minElement = currAns;
            }
        }

        return minElement;
    }
};