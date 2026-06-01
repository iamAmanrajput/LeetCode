class Solution {
public:
    static bool comp(int a, int b) { return a > b; }

    int minimumCost(vector<int>& cost) {
        int minCost = 0;
        sort(cost.begin(), cost.end(), comp);

        int i = 0;
        while (i < cost.size()) {
            int a = cost[i];
            int b = 0;

            if (i + 1 < cost.size()) {
                b = cost[i + 1];
            }

            minCost = minCost + (a + b);
            i = i + 3;
        }

        return minCost;
    }
};