class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // n is the size of the array
        int n = nums.size();

        // Calculate the expected sum of numbers from 0 to n using the formula:
        // n*(n+1)/2
        int total = n * (n + 1) / 2;

        // Calculate the sum of all elements present in the array
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // The missing number is the difference between the expected total sum
        // and the actual sum of elements
        return total - sum;
    }
};
