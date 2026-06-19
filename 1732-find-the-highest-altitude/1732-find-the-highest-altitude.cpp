class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int highestAltitude = 0;
        int currAltitude = 0;

        for (int i = 0; i < gain.size(); i++) {
            currAltitude += gain[i];
            highestAltitude = max(highestAltitude, currAltitude);
        }

        return highestAltitude;
    }
};