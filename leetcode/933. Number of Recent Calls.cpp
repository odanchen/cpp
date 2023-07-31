class RecentCounter {
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        calls.push(t);
        while (t - calls.front() > 3000) calls.pop();
        return calls.size();
    }
    queue<int> calls;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
