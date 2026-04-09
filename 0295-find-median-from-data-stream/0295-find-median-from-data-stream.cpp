class MedianFinder {
public:
    priority_queue<int> maxi;
    priority_queue<int, vector<int>, greater<int>> mini;
    double median;

    MedianFinder() {
        median = 0;
    }

    int signum(int a, int b) {
        if (a == b) return 0;
        else if (a > b) return 1;
        else return -1;
    }

    void addNum(int element) {
        switch (signum(maxi.size(), mini.size())) {

        case 0:
            if (element > median) {
                mini.push(element);
                median = mini.top();
            } else {
                maxi.push(element);
                median = maxi.top();
            }
            break;

        case 1:
            if (element > median) {
                mini.push(element);
            } else {
                mini.push(maxi.top());
                maxi.pop();
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2.0;
            break;

        case -1:
            if (element > median) {
                maxi.push(mini.top());
                mini.pop();
                mini.push(element);
            } else {
                maxi.push(element);
            }
            median = (mini.top() + maxi.top()) / 2.0;
            break;
        }
    }

    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */