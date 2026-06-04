class Solution {
public:
    bool isWaviness(int prevDig, int currDig, int nextDig) {
        return (currDig > prevDig && currDig > nextDig) ||
               (currDig < prevDig && currDig < nextDig);
    }

    int totalWaviness(int num1, int num2) {

        int waviness = 0;

        for (int num = num1; num <= num2; num++) {

            string s = to_string(num);

            for (int i = 1; i < s.size() - 1; i++) {

                int prev = s[i - 1] - '0';
                int curr = s[i] - '0';
                int next = s[i + 1] - '0';

                if (isWaviness(prev, curr, next)) {
                    waviness++;
                }
            }
        }

        return waviness;
    }
};