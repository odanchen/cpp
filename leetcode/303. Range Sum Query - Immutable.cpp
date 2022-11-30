class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size() + 1);
        prefix[0] = 0;
        for (int i = 0; i < nums.size(); i++) prefix[i + 1] += (prefix[i] + nums[i]);
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};
