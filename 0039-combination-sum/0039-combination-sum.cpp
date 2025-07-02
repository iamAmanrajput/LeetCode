class Solution {
public:
    void findCombination(vector<int>& candidates, int target,
                         vector<vector<int>>& ans, vector<int> currAns) {
        if (target == 0) {
            ans.push_back(currAns);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = 0; i < candidates.size(); i++) {
            currAns.push_back(candidates[i]);
            findCombination(candidates, target - candidates[i], ans, currAns);
            currAns.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> currAns;
        findCombination(candidates, target, ans, currAns);
        if (ans.size() > 0) {
            set<vector<int>> uniqueSubarrays;
            for (auto sub : ans) {
                sort(sub.begin(), sub.end()); // sort to ignore order
                uniqueSubarrays.insert(
                    sub); // insert in set to avoid duplicates
            }
            vector<vector<int>> result(uniqueSubarrays.begin(),
                                       uniqueSubarrays.end());
            return result;
        } else {
            return ans;
        }
    }
};