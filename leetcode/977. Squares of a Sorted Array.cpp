    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        ans.resize(nums.size());
        int left = 0, right = nums.size() - 1;
        int idx = nums.size() - 1;
        while(idx >= 0)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                ans[idx] = nums[left] * nums[left];
                idx--;
                left++;
            }
            else
            {
                ans[idx] = nums[right] * nums[right];
                idx--;
                right--;
            }
        }

        return ans;
    }
