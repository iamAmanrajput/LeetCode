class Solution {
public:
    void findCombination(vector<int>& candidates, int target,
                         vector<vector<int>>& ans, vector<int>& currAns,
                         int index) {
        if (target == 0) {
            ans.push_back(currAns);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            currAns.push_back(candidates[i]);
            findCombination(candidates, target - candidates[i], ans, currAns,
                            i + 1);
            currAns.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> currAns;
        findCombination(candidates, target, ans, currAns, 0);
        set<vector<int>> st;
        for (auto e : ans) {
            st.insert(e);
        }
        ans.clear();
        for (auto e : st) {
            ans.push_back(e); // only unique vectors
        }

        return ans;
    }
};