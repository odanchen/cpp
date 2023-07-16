class Solution {
public:
    string distribute(queue<string> &wordQueue, int maxWidth, int curLen) {
        string ans;
        int spaceCnt = maxWidth - curLen + wordQueue.size() - 1;
        int avg = wordQueue.size() == 1 ? spaceCnt : spaceCnt / (wordQueue.size() - 1);
        int cnt = wordQueue.size() == 1 ? 0 : spaceCnt % (wordQueue.size() - 1);
        ans.append(wordQueue.front());
        wordQueue.pop();
        for (int i = wordQueue.size(); i > 0; i--) {
            for (int i = (cnt--) <= 0 ? avg : avg + 1; i > 0; i--) ans.push_back(' ');
            ans.append(wordQueue.front());
            wordQueue.pop();
        }
        while (ans.size() < maxWidth) ans.push_back(' ');
        return ans;
    }
    string justLeft(queue<string> &wordQueue, int maxWidth) {
        string ans;
        ans.append(wordQueue.front());
        wordQueue.pop();
        for (int i = wordQueue.size(); i > 0; i--) {
            ans.push_back(' ');
            ans.append(wordQueue.front());
            wordQueue.pop();
        }
        while (ans.size() < maxWidth) ans.push_back(' ');
        return ans;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        queue<string> wordQueue;
        int curLen = -1;
        for (int i = 0; i < words.size(); i++) {
            if (curLen + words[i].size() + 1 > maxWidth) {
                ans.push_back(distribute(wordQueue, maxWidth, curLen));
                curLen = -1;
            }
            curLen += words[i].size() + 1;
            wordQueue.push(words[i]);
        }
        if (!wordQueue.empty()) ans.push_back(justLeft(wordQueue, maxWidth));
        return ans;
    }
};
