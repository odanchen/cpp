class Solution {
public:
typedef vector<unordered_map<string, int>::iterator> itVec;
typedef unordered_map<string, int> wordMap;
    void checkArr(itVec &words, wordMap &sMap, vector<int> &ans, wordMap &wordsMap, int diff) {
        for (auto &val : sMap) val.second = 0;
        int left = 0, right = 0, toMatch = sMap.size(), match = 0;
        while (right < words.size()) {
            if (words[right] == wordsMap.end()) {
                match = 0;
                while (left < right) sMap[words[left++]->first] = 0;
                left = ++right;
            }
            else {
                auto sIt = sMap.find(words[right]->first);
                sIt->second++;
                if (sMap[words[right]->first] == words[right]->second) match++;
                while (sIt->second > words[right]->second) {
                    if (sMap[words[left]->first] == words[left]->second) match--;
                    sMap[words[left++]->first]--;
                }
                right++;
                if (match == toMatch) {
                    ans.push_back(diff + left * sMap.begin()->first.size());
                }
            }
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> wordsMap, sMap;
        vector<int> ans;
        if (s.size() < words.size() * words[0].size()) return {};
        vector<itVec> subWords(words[0].size());
        
        for (string &word : words) {
            if (wordsMap.find(word) == wordsMap.end()) {
                wordsMap[word] = 1;
                sMap[word] = 0;
            }
            else wordsMap[word]++;
        }
        for (int i = 0; i <= s.size() - words[0].size(); i++) {
            subWords[i % words[0].size()].push_back(wordsMap.find(s.substr(i, words[0].size())));
        }
        for (int i = 0; i < subWords.size(); i++) checkArr(subWords[i], sMap, ans, wordsMap, i);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
