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

    int maximalRectangle(vector<vector<char>>& matrix) {

        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> v(n, vector<int>(m, 0));

        // convert char matrix to int matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i][j] = matrix[i][j] - '0';
            }
        }

        int area = largestRectangleArea(v[0]);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    v[i][j] = v[i - 1][j] + 1;
                } else {
                    v[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(v[i]));
        }

        return area;
    }
};