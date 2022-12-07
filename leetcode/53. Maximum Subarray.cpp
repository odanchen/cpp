class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size() + 1;
        vector<int> prefixSum(len);
        prefixSum[0] = 0;

        int maxSub = 1, minSub = 0, potentialMin = 0, maxSum = INT_MIN;
        for (int i = 1; i < len; i++)
        {
            prefixSum[i] = nums[i - 1] + prefixSum[i - 1];

            if (prefixSum[i] - prefixSum[potentialMin] > maxSum)
            {
                maxSub = i;
                minSub = potentialMin;
                maxSum = prefixSum[i] - prefixSum[potentialMin];
            }

            if (prefixSum[i] < prefixSum[potentialMin]) potentialMin = i;
        }

        return maxSum;
    }
};
