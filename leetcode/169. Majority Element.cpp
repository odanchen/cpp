class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = nums.front(), cnt = 1;
        for (int val : nums) {
            if (val != element) cnt--;
            else cnt++;
            if (cnt == 0) {
                element = val;
                cnt = 1;
            }
        }
        return element;
    }
};
