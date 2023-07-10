class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0;
        while (idx < intervals.size() and intervals[idx][0] < newInterval[0]) ans.push_back(intervals[idx++]);
        if (ans.empty() or ans.back()[1] < newInterval[0]) ans.push_back(newInterval);
        else ans.rbegin()->at(1) = max(ans.back()[1], newInterval[1]);
        while (idx < intervals.size() and intervals[idx][0] <= ans.back()[1])
            ans.rbegin()->at(1) = max(ans.back()[1], intervals[idx++][1]);
        while (idx < intervals.size()) ans.push_back(intervals[idx++]);
        return ans;
    }
};
