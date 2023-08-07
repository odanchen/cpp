class MedianFinder {
private:
    priority_queue<int> leftQueue;
    priority_queue<int, vector<int>, greater<>> rightQueue;
public:

    MedianFinder() = default;

    void addNum(int num) {
        if (leftQueue.empty() or rightQueue.empty()) leftQueue.push(num);
        else num > leftQueue.top() ? rightQueue.push(num) : leftQueue.push(num);

        if (leftQueue.size() > rightQueue.size() and leftQueue.size() == rightQueue.size() + 2) {
            rightQueue.push(leftQueue.top());
            leftQueue.pop();
        } else if (leftQueue.size() < rightQueue.size() and leftQueue.size() + 2 == rightQueue.size()) {
            leftQueue.push(rightQueue.top());
            rightQueue.pop();
        }
    }

    double findMedian() {
        if (leftQueue.size() != rightQueue.size())
            return leftQueue.size() > rightQueue.size() ? leftQueue.top() : rightQueue.top();
        return (rightQueue.top() + leftQueue.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
