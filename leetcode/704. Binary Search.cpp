class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        if (nums[left] == target) return left;
        return - 1;
    }
};
