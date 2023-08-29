class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int ans = 1;
        for (int i = 0; i < points.size(); i++) {
            int horizontal = 1, vertical = 1;
            unordered_map<double, int> slopes;
            for (int j = 0; j < i; j++) {
                if (points[i][0] == points[j][0]) ans = max(++vertical, ans);
                else if (points[i][1] == points[j][1]) ans = max(++horizontal, ans);
                else {
                    double slope = ((double) points[i][1] - points[j][1]) / ((double) points[i][0] - points[j][0]);
                    ans = max(++slopes[slope] + 1, ans);
                }
            }
        }
        return ans;
    }
};
