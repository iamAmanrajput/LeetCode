class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {
        
        int minFinishTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        // Har ek land ride 'i' aur water ride 'j' ka pair check karo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                // ---- Case 1: Pehle Land Ride (i) -> Fir Water Ride (j) ----
                int landFinish1 = landStartTime[i] + landDuration[i];
                int waterStart1 = max(landFinish1, waterStartTime[j]);
                int totalFinish1 = waterStart1 + waterDuration[j];
                
                // ---- Case 2: Pehle Water Ride (j) -> Fir Land Ride (i) ----
                int waterFinish2 = waterStartTime[j] + waterDuration[j];
                int landStart2 = max(waterFinish2, landStartTime[i]);
                int totalFinish2 = landStart2 + landDuration[i];

                // Jo bhi minimum finish time mile, use update karo
                minFinishTime = min({minFinishTime, totalFinish1, totalFinish2});
            }
        }

        return minFinishTime;
    }
};