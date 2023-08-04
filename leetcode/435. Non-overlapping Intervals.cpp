class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });
        int ans = 0;
        auto last = intervals.front();
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last[1]) {
                ans++;
                if (intervals[i][1] < last[1]) last = intervals[i];
            } else last = intervals[i];
        }
        return ans;
    }
};
