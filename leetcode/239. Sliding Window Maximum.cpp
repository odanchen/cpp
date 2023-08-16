class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        list<pair<int, int>> monoQueue;
        vector<int> ans(nums.size() - k + 1);
        for (int i = 0; i < nums.size(); i++) {
            if (!monoQueue.empty() and i - monoQueue.front().second >= k) monoQueue.pop_front();
            while (!monoQueue.empty() and nums[i] >= monoQueue.back().first) monoQueue.pop_back();
            monoQueue.emplace_back(nums[i], i);
            if (i - k + 1 >= 0) ans[i - k + 1] = monoQueue.front().first;
        }
        return ans;
    }
};
