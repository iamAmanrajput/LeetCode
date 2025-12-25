class RecentCounter {
public:
    queue<int> q;   // queue to store request times

    // Constructor
    RecentCounter() {
        // initially no requests
    }
    
    int ping(int t) {
        // Step 1: add current request time
        q.push(t);

        // Step 2: remove all requests older than (t - 3000)
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }

        // Step 3: remaining requests are recent
        return q.size();
    }
};
