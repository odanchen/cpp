    int arraySign(vector<int>& nums) {
        bool neg = false;
        for (int element : nums)
        {
            if (element == 0) return 0;
            if (element < 0) neg = !neg;
        }

        return neg ? -1 : 1;
    }
