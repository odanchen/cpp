class MyQueue {
private:
    stack<int> storage;
    stack<int> imitation;
public:
    MyQueue() {
    }


    void push(int x) {
        storage.push(x);
    }
    
    int pop() {
        if (imitation.empty())
        {
            while(not(storage.empty()))
            {
                imitation.push(storage.top());
                storage.pop();
            }
        }
        int ans = imitation.top();
        imitation.pop();
        return ans;
    }
    
    int peek() {
        if (imitation.empty())
        {
            while(not(storage.empty()))
            {
                imitation.push(storage.top());
                storage.pop();
            }
        }
        return imitation.top();
    }
    
    bool empty() {
        return (storage.empty() && imitation.empty());
    }
};
