    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int cur = 3, prev = 2;
        for (int i = 4; i <= n; i++)
        {
            int temp = cur + prev;
            prev = cur;
            cur = temp;
        }
        return cur;
    }
