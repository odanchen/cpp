class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        vector<pair<int, int>> pairs(nums1.size());
        long long ans = 0, sum = 0;
        priority_queue<int, vector<int>, greater<>> elements;
        for (int i = 0; i < nums1.size(); i++) pairs[i] = {nums1[i], nums2[i]};
        sort(pairs.begin(), pairs.end(), [](pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; });
        for (auto [a, b]: pairs) {
            sum += a;
            elements.push(a);
            if (elements.size() >= k) {
                if (elements.size() > k) {
                    sum -= elements.top();
                    elements.pop();
                }
                ans = max(ans, sum * b);
            }
        }
        return ans;
    }
}; 
