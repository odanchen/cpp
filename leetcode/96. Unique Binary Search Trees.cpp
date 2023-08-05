class Solution {
public:
    int recurse(int n, unordered_map<int, int> &achieved) {
        if (achieved.find(n) != achieved.end()) return achieved[n];
        int ans = 0;
        for (int i = 1; i <= n; i++) ans += recurse(i - 1, achieved) * recurse(n - i, achieved);
        achieved[n] = ans;
        return ans;
    }
    int numTrees(int n) {
        unordered_map<int, int> achieved = {{0, 1}, {1, 1}, {2, 2}};
        return recurse(n, achieved);
    }
};
