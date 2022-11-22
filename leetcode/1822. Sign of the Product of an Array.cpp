    int arraySign(vector<int>& nums) {
        int neg = 0;
        for (int element : nums)
        {
            if (element == 0) return 0;
            if (element < 0) neg++;
        }

        if (neg % 2 == 1) return -1;
        return 1;
    }
