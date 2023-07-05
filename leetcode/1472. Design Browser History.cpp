class BrowserHistory {
public:
    vector<string> storage;
    int idx = 0;
    BrowserHistory(string homepage) {
        storage.push_back(homepage);
    }
    
    void visit(string url) {
        if (++idx != storage.size()) for (int i = storage.size(); i > idx; i--) storage.pop_back();
        storage.push_back(url);
    }
    
    string back(int steps) {
        idx = max(0, idx - steps);
        return storage[idx];
    }
    
    string forward(int steps) {
        idx = min(idx + steps, (int) storage.size() - 1);
        return storage[idx];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
