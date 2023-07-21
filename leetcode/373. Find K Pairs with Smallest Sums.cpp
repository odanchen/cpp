class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto comp = [](vector<int> &a, vector<int>  &b){return a[0] + a[1] > b[0] + b[1];};
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)> pQueue(comp);
        vector<vector<int>> ans;
        for (int i = 0; i < nums1.size() and i < k; i++) pQueue.push({nums1[i], nums2[0], 0});
        for (int i = 0; i < k and !pQueue.empty(); i++) {
            vector<int> cur = pQueue.top();
            pQueue.pop();
            ans.push_back({cur[0], cur[1]});
            if (cur[2] < nums2.size() - 1) pQueue.push({cur[0], nums2[cur[2] + 1], cur[2] + 1});
        }
        return ans;
    }
};
