class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, int> groupMap;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (groupMap.find(groupSizes[i]) == groupMap.end()) {
                groupMap.insert({groupSizes[i], ans.size()});
                ans.emplace_back();
            }
            ans[groupMap[groupSizes[i]]].push_back(i);
            if (ans[groupMap[groupSizes[i]]].size() == groupSizes[i]) groupMap.erase(groupSizes[i]);
        }
        return ans;
    }
};
