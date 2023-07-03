class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        ansQueue.push(x);
        for (int i = 0; i < ansQueue.size() - 1; i++) {
            ansQueue.push(ansQueue.front());
            ansQueue.pop();
        }
    }
    
    int pop() {
        int ans = ansQueue.front();
        ansQueue.pop();
        return ans;
    }
    
    int top() {
        return ansQueue.front();
    }
    
    bool empty() {
        return ansQueue.empty();
    }

private:
    queue<int> ansQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
