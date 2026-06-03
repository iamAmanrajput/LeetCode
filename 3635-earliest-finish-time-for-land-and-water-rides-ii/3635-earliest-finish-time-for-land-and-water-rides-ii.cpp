class Solution {
public:
    int solve(vector<int>& start1, vector<int>& dur1,
              vector<int>& start2, vector<int>& dur2) {

        long long minFinishFirst = LLONG_MAX;

        for (int i = 0; i < start1.size(); i++) {
            minFinishFirst = min(
                minFinishFirst,
                (long long)start1[i] + dur1[i]
            );
        }

        long long ans = LLONG_MAX;

        for (int i = 0; i < start2.size(); i++) {
            ans = min(
                ans,
                max(minFinishFirst, (long long)start2[i]) + dur2[i]
            );
        }

        return (int)ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landThenWater =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        int waterThenLand =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return min(landThenWater, waterThenLand);
    }
};