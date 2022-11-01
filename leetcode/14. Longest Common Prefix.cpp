    string longestCommonPrefix(vector<string>& strs) {
        for(int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 0; j < strs.size(); j++)
            {
                if(i == strs[j].size() || strs[0][i] != strs[j][i])
                    return strs[0].substr(0, i);
            }
        }

        return strs[0];
    }
