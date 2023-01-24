class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ans[numRows];
        int row;
        int i = 1;
        ans[0].insert(ans[0].begin() + ans[0].size(), s[0]);

        while(i < s.size())
        {
            for (row = 1; row < numRows && i < s.size(); row++)
            {
                ans[row].insert(ans[row].begin() + ans[row].size(), s[i]);
                i++;
            }

            for (row = numRows - 2; row >= 0 && i < s.size(); row--)
            {
                ans[row].insert(ans[row].begin() + ans[row].size(), s[i]);
                i++;
            }
        }
        
        string res = "";
        for(int i = 0; i < numRows; i++)
        {
            res += ans[i];
        }
        return res;
    }
};
