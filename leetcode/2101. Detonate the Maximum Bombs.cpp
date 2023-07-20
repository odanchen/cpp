class Solution {
public:
    double dist(vector<int> &a, vector<int> &b) {
        return sqrt((long long)(a[0] - b[0]) * (a[0] - b[0]) + (long long)(a[1] - b[1]) * (a[1] - b[1]));
    }
    int bfs(vector<vector<int>> &bombs, vector<bool> &hash, int idx) {
        int ans = 1;
        queue<int> toExplode({idx});
        vector<bool> localHash(hash.size());
        localHash[idx] = hash[idx] = true;

        while (!toExplode.empty()) {
            int cur = toExplode.front();
            toExplode.pop();
            
            for (int i = 0; i < bombs.size(); i++) {
                if (bombs[cur][2] >= dist(bombs[i], bombs[cur]) and !localHash[i]) {
                    localHash[i] = hash[i] = true;
                    ans++;
                    toExplode.push(i);
                }
            }
        }
        return ans;
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<bool> hash(bombs.size());
        int ans = 0;
        sort(bombs.begin(), bombs.end(), [](vector<int> &a, vector<int> &b){return a[2] > b[2];});
        for (int i = 0; i < bombs.size(); i++) if (!hash[i]) ans = max(ans, bfs(bombs, hash, i));
        return ans;
    }
};
