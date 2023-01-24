class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        queue<int> idxs;
        for(int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                cnt++;
                if (not(idxs.empty()))
                {
                    swap(nums[i], nums[idxs.front()]);
                    idxs.pop();
                    i--;
                }
            }
            else idxs.push(i);
        }


        return cnt;
    }
};
