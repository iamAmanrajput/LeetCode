class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Angle of minute hand
        double minuteAngle = minutes * 6.0;

        // Angle of hour hand
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;

        // Difference between the two angles
        double diff = abs(hourAngle - minuteAngle);

        // Return the smaller angle
        return min(diff, 360.0 - diff);
    }
};