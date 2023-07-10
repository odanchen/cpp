class Solution {
public:
    bool inside(pair<int, int> &range, vector<int> &interval) {
        return (interval[0] >= range.first and interval[0] <= range.second) or
                (interval[1] >= range.first and interval[1] <= range.second);
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){return a.front() < b.front();});
        int ans = 0, first = 0, last = 0;
        while (first < points.size()) {
            last = first + 1;
            pair<int, int> range = {points[first][0], points[first][1]};
            while (last < points.size() and inside(range, points[last])) {
                range.first = max(range.first, points[last][0]);
                range.second = min(range.second, points[last++][1]);
            } 
            first = last;
            ans++;
        }
        return ans;
    }
};
