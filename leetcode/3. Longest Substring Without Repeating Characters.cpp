class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, maxLen = 0, curLen = 0;
        while(i != s.size())
        {
            int hash[128][2] = {0};
            while(i != s.size() && hash[s[i]][0] == 0)
            {
                hash[s[i]][0] = 1;
                hash[s[i]][1] = i;
                i++;
                curLen++;
            }

            maxLen = max(maxLen, curLen);
            curLen = 0;
            if(i != s.size()) i = hash[s[i]][1] + 1;
        }

        return maxLen;
    }
};
