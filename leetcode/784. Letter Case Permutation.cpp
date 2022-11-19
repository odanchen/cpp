    void swapCase(string &s, int pos)
    {
        if(isupper(s[pos])) s[pos] = tolower(s[pos]);
        else s[pos] = toupper(s[pos]);
    }
    void addPermutation(int &level, vector<string> &ans, string s)
    {
        if (level == s.size())
        {
            ans.push_back(s);
            return;
        }

        if(isalpha(s[level]))
        {   
            level++;
            addPermutation(level, ans, s);
            level--;
            swapCase(s, level);
            level++;
            addPermutation(level, ans, s);
            level--;
        }
        else
        {
            level++;
            addPermutation(level, ans, s);
            level--;
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        int level = 0;
        addPermutation(level, ans, s);
        return ans;
    }
