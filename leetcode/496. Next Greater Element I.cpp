    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> idxs;
        vector<int> ans;
        for(int i = 0; i < nums2.size(); i++) idxs.insert(pair<int, int>(nums2[i], i));
        for(int element : nums1)
        {
            bool isFound = false;
            for (int i = idxs.at(element); i < nums2.size(); i++)
            {
                if(nums2[i] > element && not(isFound))
                {
                    isFound = true;
                    ans.push_back(nums2[i]);
                    continue;
                }
            }
            if (not(isFound)) ans.push_back(-1);
        }
        return ans;
    }
