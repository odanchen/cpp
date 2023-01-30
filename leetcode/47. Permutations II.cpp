class Solution {
public:
    void addPermutation(vector<vector<int>> &ans, vector<int> arr, map<int, int> options, int prevPicked)
    {
        if (prevPicked != -11) {
            arr.push_back(prevPicked);
            if (options.at(prevPicked) == 1) options.erase(options.find(prevPicked));
            else options.at(prevPicked)--;
        }
        if (options.empty()) {
            ans.push_back(arr); return;
        }
        for (auto choice : options) {
            addPermutation(ans, arr, options, choice.first);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> options;
        for (int element : nums) {
            if(options.find(element) == options.end()) options.insert(pair<int, int>(element, 1));
            else options.at(element)++;
        }
        addPermutation(ans, vector<int>(), options, -11);
        return ans;
    } 
};
