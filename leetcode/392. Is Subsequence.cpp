class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<char> checkArr;
        for (char letter : s) checkArr.push_back(letter);

        int curIdx = 0;
        for (char letter : t) if (curIdx < s.size() && letter == checkArr[curIdx]) curIdx++;

        return curIdx == s.size();
    }
};
