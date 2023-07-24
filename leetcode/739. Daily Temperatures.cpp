class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> monoStack;
        vector<int> ans(temperatures.size());
        for (int i = 0; i < temperatures.size(); i++) {
            while (!monoStack.empty() and temperatures[i] > temperatures[monoStack.top()]) {
                ans[monoStack.top()] = i - monoStack.top();
                monoStack.pop();
            }
            monoStack.push(i);
        }
        return ans;
    }
};
