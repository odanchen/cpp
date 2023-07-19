class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pQueue(nums.begin(), nums.end());
        for (int i = 1; i < k; i++) pQueue.pop();
        return pQueue.top();
    }
};
