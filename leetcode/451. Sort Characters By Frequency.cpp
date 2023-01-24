class Solution {
public:
    struct hashLetter
    {
        char letter = '-';
        int frequency = 0;
    };
    static bool comp(hashLetter &a, hashLetter &b)
    {
        return a.frequency > b.frequency;
    }
    string multiply(char letter, int cnt)
    {
        string ans;
        ans.resize(cnt);
        for (int i = 0; i < ans.size(); i++) ans[i] = letter;
        return ans;
    }
    string frequencySort(string s) {
        vector<hashLetter> frequencies(62);
        for (char letter : s)
        {
            if (islower(letter))
            {
                if (frequencies[letter - 'a'].letter == '-') frequencies[letter - 'a'].letter = letter;
                frequencies[letter - 'a'].frequency++;
            }
            if (isupper(letter))
            {
                if (frequencies[letter - 'A' + 26].letter == '-') frequencies[letter - 'A' + 26].letter = letter;
                frequencies[letter - 'A' + 26].frequency++;
            }
            if (isdigit(letter))
            {
                if (frequencies[letter - '0' + 52].letter == '-') frequencies[letter - '0' + 52].letter = letter;
                frequencies[letter - '0' + 52].frequency++;
            }
        }

        sort(frequencies.begin(), frequencies.end(), comp);
        string ans;
        for (hashLetter cur : frequencies)
        {
            if (cur.frequency != 0) ans += multiply(cur.letter, cur.frequency);
        }
        return ans;
    }
};
