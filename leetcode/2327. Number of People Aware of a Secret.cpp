class Solution {
public:
    const int mod = 1000000007;
    int fix(int n) {
        if (n < 0) return n + mod;
        return n % mod;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int know = 1, active = 0;
        queue<pair<int, int>> toDelay({{1, 1 + delay}}), toForget({{1, 1 + forget}});
        for (int i = 1; i <= n; i++) {
            while (i == toForget.front().second) {
                know = fix(know - toForget.front().first);
                active = fix(active - toForget.front().first);
                toForget.pop();
            }
            while (i == toDelay.front().second) {
                active = fix(active + toDelay.front().first);
                toDelay.pop();
            }
            toDelay.push({active, i + delay});
            toForget.push({active, i + forget});
            know = fix(active + know);
        }
        return know % mod;
    }
};
