class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        vector<vector<int>> ans;
        int left = 0, right;
        while (left < intervals.size()) {
            right = left + 1;
            int maxVal = intervals[left][1];
            while (right < intervals.size() and maxVal >= intervals[right][0]) {
                maxVal = max(maxVal, intervals[right][1]);
                right++;
            }
            ans.push_back({intervals[left][0], maxVal});
            left = right;
        }
        return ans;
    }
};
