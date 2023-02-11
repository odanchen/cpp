class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> stoneQueue;
        for (int val : stones) stoneQueue.push(val);
        while(!stoneQueue.empty()) {
            int a, b;
            a = stoneQueue.top(); stoneQueue.pop();
            if (stoneQueue.empty()) return a;
            b = stoneQueue.top(); stoneQueue.pop();
            if (abs(a - b) != 0) stoneQueue.push(abs(a - b));
        }
        return 0;
    }
};
