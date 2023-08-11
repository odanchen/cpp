class Solution {
public:
    double dist(int x1, int x2, int y1, int y2) {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto &quer: queries) {
            int cnt = 0;
            for (auto point: points) if (dist(quer[0], point[0], quer[1], point[1]) <= quer[2]) cnt++;
            ans.push_back(cnt);
        }
        return ans;
    }
};
