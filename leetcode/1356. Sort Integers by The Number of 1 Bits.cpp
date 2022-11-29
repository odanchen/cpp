    static int count1Bits(int n)
    {
        int cnt = 0;
        while (n > 0)
        {
            if (n & 1) cnt++;
            n = n >> 1;
        }
        return cnt;
    }
    static bool comp(int a, int b)
    {
        int bitsA = count1Bits(a);
        int bitsB = count1Bits(b);
        return (bitsA == bitsB) ? (a < b) : (bitsA < bitsB);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
