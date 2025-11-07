class Solution {
public:
    bool isValid(string &s) {

        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // opening brackets → push
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                // closing bracket but stack empty -> invalid
                if (st.empty())
                    return false;

                char topCh = st.top();

                // matching pairs
                if (ch == ')' && topCh == '(') {
                    st.pop();
                } else if (ch == '}' && topCh == '{') {
                    st.pop();
                } else if (ch == ']' && topCh == '[') {
                    st.pop();
                } else {
                    return false; // mismatch
                }
            }
        }

        // end me stack empty hona chahiye
        return st.empty();
    }
};
