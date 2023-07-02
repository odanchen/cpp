class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k < 0 ? (k + nums.size()) % nums.size() : k % nums.size();
        int left = 0, right = k, numGCD = gcd(nums.size(), k);
        while (left != numGCD) {
            right = (left + k) % nums.size();
            while(left != right) {
                swap(nums[left], nums[right]);
                right = (right + k) % nums.size();
            }
            left++;
        }
    }
};
