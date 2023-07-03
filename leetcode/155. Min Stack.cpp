class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        allStack.push(val);
        if (minStack.empty() or minStack.top().first > val) {
            minStack.push({val, allStack.size()});
        }
    }
    
    void pop() {
        if (allStack.size() == minStack.top().second) minStack.pop();
        allStack.pop();
    }
    
    int top() {
        return allStack.top();
    }
    
    int getMin() {
        return minStack.top().first;
    }
private:
    stack<int> allStack;
    stack<pair<int, int>> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
