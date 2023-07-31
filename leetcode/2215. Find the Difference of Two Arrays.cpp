class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> n1(nums1.begin(), nums1.end()), n2(nums2.begin(), nums2.end());
        vector<vector<int>> ans(2);
        for (auto val: n1) if (n2.find(val) == n2.end()) ans[0].push_back(val);
        for (auto val: n2) if (n1.find(val) == n1.end()) ans[1].push_back(val);
        return ans;
    }
};
