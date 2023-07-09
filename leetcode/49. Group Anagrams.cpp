class Solution {
public:
    string sorted(string s) {
        sort(s.begin(), s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> wordMap;
        for (string &s : strs) {
            string sortedS = sorted(s);
            if (wordMap.find(sortedS) != wordMap.end()) wordMap[sortedS].push_back(s);
            else wordMap.insert({sortedS, {s}});
        }
        vector<vector<string>> ans;
        for (auto it = wordMap.begin(); it != wordMap.end(); it++) ans.push_back(it->second);
        return ans;
    }
};
