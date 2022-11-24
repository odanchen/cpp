    int getSum(vector<int> &prefixSum, int start, int len)
    {
        return prefixSum[start + len] - prefixSum[start];
    }
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefixSum(arr.size() + 1);
        int sum = 0;
        prefixSum[0] = 0;
        for (int i = 0; i < arr.size(); i++) prefixSum[i + 1] = arr[i] + prefixSum[i];

        for (int len = 1; len <= arr.size(); len += 2)
        {
            for (int start = 0; start + len <= arr.size(); start++)
            {
                sum += getSum(prefixSum, start, len);
            }
        }
        return sum;
    }
