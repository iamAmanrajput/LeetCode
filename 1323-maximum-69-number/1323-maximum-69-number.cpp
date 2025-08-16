class Solution {
public:
    int maximum69Number (int num) {
        string val = to_string(num);
        for(int i = 0; i < val.size(); i++) {
            if(val[i] == '6') {
                val[i] = '9';
                break;
            }
        }
        return stoi(val);
    }
};
