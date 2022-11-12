    void reverse(string &s, int i, int j)
    {
        while(i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++)
        {
            while(s[i] == ' ' && i < s.size()) i++;
            int j = i;
            while(s[j] != ' ' && j < s.size()) j++;

            reverse(s, i, j - 1);
            i = j;
        }

        return s;
    }
