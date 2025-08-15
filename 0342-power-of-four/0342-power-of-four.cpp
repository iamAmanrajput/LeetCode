class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return true;
        }

        while (n % 4 == 0) {
            n = n / 4;
        }
        return n == 1;
    }
};