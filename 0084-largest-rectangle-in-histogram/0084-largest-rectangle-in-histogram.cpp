class Solution {
public:
    vector<int> prevSmaller(vector<int>& v) {
        stack<int> st;
        st.push(-1);

        vector<int> ans(v.size());

        for (int i = 0; i < v.size(); i++) {
            int curr = v[i];
            while (st.top() != -1 && v[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> nextSmaller(vector<int>& v) {
        vector<int> ans(v.size());
        stack<int> s;
        s.push(-1);

        for (int i = v.size() - 1; i >= 0; i--) {

            int curr = v[i];

            // apka answer stack me
            while (s.top() != -1 && v[s.top()] >= curr) {
                s.pop();
            }

            // chotta element mil chuka h -> ans store
            ans[i] = s.top();

            // push krdo curr element ko
            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);

        int maxArea = INT_MIN;

        for (int i = 0; i < heights.size(); i++) {
            int length = heights[i];
            if (next[i] == -1) {
                next[i] = next.size();
            }
            int width = next[i] - prev[i] - 1;
            int area = length * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};