class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, prev = 0;
        do {
            prev = slow;
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
