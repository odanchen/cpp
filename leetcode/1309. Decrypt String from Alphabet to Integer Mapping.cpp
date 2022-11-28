    string freqAlphabets(string s) {
        string ans;
        for (int i = 0; i < s.size(); i++)
        {
            if(i + 2 < s.size() && s[i + 2] == '#')
            {
                ans += ('a' + stoi(s.substr(i, 2)) - 1);
                i += 2;
            }
            else ans += ('a' + (s[i] - '1'));
        }
        return ans;
    }
