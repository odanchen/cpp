    void moveZeroes(vector<int>& nums) {
        queue<int> idxs;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0) idxs.push(i);

            if(nums[i] != 0 && not(idxs.empty()))
            {
                swap(nums[i], nums[idxs.front()]);
                idxs.pop();
                i--;
            }
        }
    }
