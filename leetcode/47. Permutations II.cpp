class Solution {
public:
    void addPermutation(vector<vector<int>> &ans, vector<int> arr, map<int, int> options, optional<int> prevPicked)
    {
        if (prevPicked.has_value()) {
            arr.push_back(prevPicked.value());
            if (options.at(prevPicked.value()) == 1) options.erase(options.find(prevPicked.value()));
            else options.at(prevPicked.value())--;
        }
        if (options.empty()) {
            ans.push_back(arr); return;
        }
        for (auto choice : options) {
            addPermutation(ans, arr, options, optional<int>(choice.first));
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> options;
        for (int element : nums) {
            if(options.find(element) == options.end()) options.insert(pair<int, int>(element, 1));
            else options.at(element)++;
        }
        addPermutation(ans, vector<int>(), options, optional<int>());
        return ans;
    }
};
