class Solution {
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
        return count_if(items.begin(), items.end(), [&](vector<string> &item) {
            if (ruleKey == "type") return item[0] == ruleValue;
            if (ruleKey == "color") return item[1] == ruleValue;
            return item[2] == ruleValue;
        });
    }
};
