class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {

        int n = cars.size();

        // answer[i] = time at which ith car collides with next car
        vector<double> answer(n, -1);

        // stack will store indices of cars
        stack<int> st;

        // traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // remove cars ahead which are slower or equal speed
            // because current car can never collide with them
            while (!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }

            // try to find valid collision
            while (!st.empty()) {

                // collision time formula
                double colTime =
                    (double)(cars[st.top()][0] - cars[i][0]) /
                    (cars[i][1] - cars[st.top()][1]);

                /*
                  If the car ahead never collides with anyone (answer = -1)
                  OR current collision happens before that car's collision,
                  then this collision is valid
                */
                if (answer[st.top()] == -1 || colTime <= answer[st.top()]) {
                    answer[i] = colTime;
                    break;
                }

                // otherwise, that car will collide earlier → useless
                st.pop();
            }

            // push current car index
            st.push(i);
        }

        return answer;
    }
};
