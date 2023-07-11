class Solution {
public:
    int nextStep(int n) {
        int ans = 0;
        while (n > 0) {
            ans += ((n % 10) * (n % 10));
            n /= 10;
        }

        return ans;
    }
    bool isHappy(int n) {
        set<int> hash;

        while (n != 1 && hash.find(n) == hash.end()) {
            hash.insert(n);
            n = nextStep(n);
        }

        return n == 1;
    }
};
