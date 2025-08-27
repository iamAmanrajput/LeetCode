class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        // Step 1: Pair score with index
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++){
            arr.push_back({score[i], i});
        }
        
        // Step 2: Sort by score descending
        sort(arr.begin(), arr.end(), greater<>());
        
        // Step 3: Prepare answer array
        vector<string> ans(n);
        for(int rank=0; rank<n; rank++){
            int idx = arr[rank].second;
            if(rank == 0) ans[idx] = "Gold Medal";
            else if(rank == 1) ans[idx] = "Silver Medal";
            else if(rank == 2) ans[idx] = "Bronze Medal";
            else ans[idx] = to_string(rank+1);
        }
        
        return ans;
    }
};
