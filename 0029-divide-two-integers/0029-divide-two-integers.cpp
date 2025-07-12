class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long to handle abs(INT_MIN)
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);

        long long start = 0, end = a, ans = 0;

        while (start <= end) {
            long long mid = start + (end - start) / 2;

            if (mid * b == a) {
                ans = mid;
                break;
            }

            if (mid * b < a) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // both values are true then return ans else -ans
        bool isNegative = (dividend < 0) != (divisor < 0);
        return isNegative ? -ans : ans;
    }
};
