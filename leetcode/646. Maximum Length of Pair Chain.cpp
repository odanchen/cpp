class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](vector<int> &a, vector<int> &b){return a[0] < b[0];});
        int cnt = 1, lastRight = pairs[0][1];
        for (vector<int> &line: pairs) {
            if (line[0] > lastRight) {
                cnt++;
                lastRight = line[1];
            } else lastRight = min(lastRight, line[1]);
        }
        return cnt;
    }
};
