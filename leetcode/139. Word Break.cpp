class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> processed(s.size() + 1);
        queue<int> toProcess({0});
        while (!toProcess.empty()) {
            int left = toProcess.front();
            toProcess.pop();
            if (left == s.size()) return true;
            for (int right = left + 1; right <= s.size(); right++) {
                if (processed[right]) continue;
                if (words.find(s.substr(left, right - left)) != words.end()) {
                    toProcess.push(right);
                    processed[right] = true;
                }
            }
        }
        return false;
    }
};
