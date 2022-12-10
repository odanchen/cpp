class Solution {
public:
    int count1S(int n)
    {
        int cnt = 0;
        while(n > 0)
        {
            if (n & 1) cnt++;
            n = n >> 1;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        for (int i = 0; i <= n; i++) ans[i] = count1S(i);
        return ans;
    }
};
