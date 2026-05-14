class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(char c : s){
            if(!st.empty() && st.top() == c){
                st.pop();        // duplicate mila → remove
            } else {
                st.push(c);      // nahi mila → push
            }
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
