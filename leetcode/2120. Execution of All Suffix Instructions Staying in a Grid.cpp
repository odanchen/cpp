class Solution {
public:
    bool outside(int row, int col, int n) {
        return row < 0 or col < 0 or row >= n or col >= n;
    }

    unordered_map<char, pair<int, int>> moves = {{'R', {0,  1}},
                                                {'L', {0,  -1}},
                                                {'U', {-1, 0}},
                                                {'D', {1,  0}}};

    vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
        vector<int> ans(s.size());
        for (int i = 0; i < s.size(); i++) {
            int row = startPos[0], col = startPos[1], cnt = 0;
            for (int j = i; j < s.size() and !outside(row, col, n); j++) {
                row += moves[s[j]].first;
                col += moves[s[j]].second;
                cnt++;
            }
            ans[i] = outside(row, col, n) ? cnt -  1 : cnt;
        }
        return ans;
    }
};
