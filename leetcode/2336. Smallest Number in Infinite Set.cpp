class SmallestInfiniteSet {
private:
    priority_queue<int, vector<int>, greater<>> pQueue;
    int ptr = 1;
public:
    SmallestInfiniteSet() = default;

    int popSmallest() {
        if (pQueue.empty() or ptr < pQueue.top()) return ptr++;
        if (ptr == pQueue.top()) {
            while (!pQueue.empty() and ptr == pQueue.top()) pQueue.pop();
            return ptr++;
        }
        int ans = pQueue.top();
        while (!pQueue.empty() and ans == pQueue.top()) pQueue.pop();
        return ans;
    }

    void addBack(int num) {
        pQueue.push(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
