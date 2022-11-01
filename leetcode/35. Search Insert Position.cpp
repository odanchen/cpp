    int searchInsert(vector<int>& nums, int target) {
        int left = -1, right = nums.size();
        while(left < right - 1)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] > target) right = mid;
            else left = mid;
        }
        return left + 1;
    }
