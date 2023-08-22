class Solution {
public:
    struct Node {
        explicit Node(int n) : cnt(n + 1) {}

        vector<int> cnt;
    };

    const int mod = 1000000007;

    int numRollsToTarget(int n, int k, int target) {
        vector<Node> ways(target + 1, Node(n));
        for (int i = 1; i <= min(k, target); i++) ways[i].cnt[1] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 1; j <= k; j++) {
                if (j + i <= target) {
                    for (int m = 1; m < n; m++) {
                        ways[j + i].cnt[m + 1] = (ways[j + i].cnt[m + 1] + ways[i].cnt[m]) % mod;
                    }
                }
            }
        }
        return ways.back().cnt.back();
    }
};
