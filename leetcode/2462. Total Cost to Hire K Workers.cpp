class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<>> leftQueue;
        priority_queue<int, vector<int>, greater<>> rightQueue;
        long long ans = 0;
        int left = 0, right = costs.size() - 1;
        while (left < right and left < candidates) {
            leftQueue.push(costs[left++]);
            rightQueue.push(costs[right--]);
        }
        if (left < candidates and left == right) leftQueue.push(costs[left++]);

        for (int i = 0; i < k; i++) {
            if (!leftQueue.empty() and (rightQueue.empty() or leftQueue.top() <= rightQueue.top())) {
                ans += leftQueue.top();
                leftQueue.pop();
                if (left <= right) leftQueue.push(costs[left++]);
            } else {
                ans += rightQueue.top();
                rightQueue.pop();
                if (left <= right) rightQueue.push(costs[right--]);
            }
        }
        return ans;
    } 
};
