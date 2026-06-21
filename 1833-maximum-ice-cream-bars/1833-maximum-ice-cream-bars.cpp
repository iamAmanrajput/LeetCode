class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());

        vector<int> freq(maxCost + 1, 0);

        // Count frequency of each cost
        for (int cost : costs) {
            freq[cost]++;
        }

        int ans = 0;

        // Buy cheapest bars first
        for (int price = 1; price <= maxCost; price++) {
            while (freq[price] > 0 && coins >= price) {
                coins -= price;
                freq[price]--;
                ans++;
            }
        }

        return ans;
    }
};