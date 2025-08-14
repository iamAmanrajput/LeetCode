class Solution {
public:
    string largestGoodInteger(string num) {
        string largest = "";
        for (int i = 0; i <= num.size() - 3; i++) {
            string sub = num.substr(i, 3);
            if (sub[0] == sub[1] && sub[1] == sub[2]) {
                if (largest == "" || sub > largest) {
                    largest = sub;
                }
            }
        }
        return largest;
    }
};