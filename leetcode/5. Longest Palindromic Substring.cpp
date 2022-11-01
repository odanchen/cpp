   int expand(string s, int l, int r)
    {
        int R = r, L = l;
        if(s[R] != s[L]) return 0;
        while(L >= 0 && R < s.size() && s[L] == s[R])
        {
            L--;
            R++;
        }

        return R - L - 1;
    }

    string longestPalindrome(string s) 
    {
        int maxLen = 0, leftIdx = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int curLen = 0;
            curLen = max(expand(s, i, i), expand(s, i, i + 1));
            if(maxLen < curLen)
            {
                maxLen = curLen;
                leftIdx = i - ((curLen - 1) / 2);
            }
        }
        return s.substr(leftIdx, maxLen);
    }
