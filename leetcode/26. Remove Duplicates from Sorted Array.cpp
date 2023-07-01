class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int correctPart = 1, curMax = nums[0];

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] > curMax){
                curMax = nums[i];
                swap(nums[i], nums[correctPart]);
                correctPart++;
            }
        }
        return correctPart;
    }
};
