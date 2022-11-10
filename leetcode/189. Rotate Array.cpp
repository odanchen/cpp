    void rotate(vector<int>& nums, int k) {
        vector<int> ans(nums.size());
        k = k % nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            int idx = (int)nums.size() - k + i;
            ans[i] = nums[idx % nums.size()];
        }

        nums = ans;
    }
