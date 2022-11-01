    bool isTriangle(int a, int b, int c)
    {
        return not(((a + b <= c) || (a + c <= b) || (b + c <= a)));
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 3; i >= 0; i--)
            if(isTriangle(nums[i], nums[i + 1], nums[i + 2]))
                return nums[i] + nums[i + 1] + nums[i + 2];
        return 0;
    }
