class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size(), temp = *nums.rbegin();
        vector<int> ans(size, 1);
        
        for (int i = 1; i < size; i++) ans[i] = ans[i - 1] * nums[i - 1];
        for (int i = size - 2; i >= 0; i--) {
            ans[i] *= temp;
            temp *= nums[i];
        }
      
        return ans;
    }
};
