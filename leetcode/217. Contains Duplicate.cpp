class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> mlt;
        for (int element : nums)
        {
            if (mlt.find(element) != mlt.end()) return true;
            else mlt.insert(element);
        }

        return false;
    }
};
