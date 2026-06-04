class Solution {
public:
    bool isWaviness(int prevDig, int currDig, int nextDig) {
        if (currDig > prevDig && currDig > nextDig) {
            return true;
        }
        if (currDig < prevDig && currDig < nextDig) {
            return true;
        }
        return false;
    };

    int totalWaviness(int num1, int num2) {
        if (num1 < 100 && num2 < 100) {
            return 0;
        };

        int waviness = 0;
        stack<int> st;
        int cnt = 0;
        int temp = num2;

        while (temp) {
            cnt++;
            temp /= 10;
        }

        vector<int> arr(cnt, -1);

        for (int i = num1; i <= num2; i++) {
            int digit = i;
            while (digit) {
                int lastDig = digit % 10;
                st.push(lastDig);
                digit = digit / 10;
            }
            int arrIndex = 0;
            while (!st.empty()) {
                int top = st.top();
                arr[arrIndex] = top;
                st.pop();
                arrIndex++;
            }

            int index = 1;
            while (index < arr.size() - 1 && arr[index] != -1) {

                if (arr[index + 1] == -1)
                    break;

                if (isWaviness(arr[index - 1], arr[index], arr[index + 1])) {
                    waviness++;
                }

                index++;
            }
        }
        return waviness;
    }
};