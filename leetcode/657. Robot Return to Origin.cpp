class Solution {
public:
    bool judgeCircle(string moves) {
        int row = 0, col = 0;
        unordered_map<char, pair<int, int>> moveSet = {{'U', {-1, 0}}, {'D', {1, 0}}, {'L', {0, -1}}, {'R', {0, 1}}};
        for (char c: moves) row += moveSet[c].first, col += moveSet[c].second;
        return row == 0 and col == 0;
    }
};
