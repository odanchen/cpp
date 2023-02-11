class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> wordCnt;
        for (string word : words) {
            if (wordCnt.find(word) == wordCnt.end()) {
                wordCnt.insert(pair<string, int>(word, 1));
            }
            else wordCnt.at(word)++;
        }
        vector<pair<string, int>> subAns;
        for (auto &val : wordCnt) subAns.push_back(val);
        auto comp = [](pair<string, int> a, pair<string, int> b){
            return (a.second == b.second) ? a.first < b.first : a.second > b.second;
        };
        sort(subAns.begin(), subAns.end(), comp);
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(subAns[i].first);
        }
        return ans;
    }
};
