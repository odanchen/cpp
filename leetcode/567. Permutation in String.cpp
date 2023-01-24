class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> lettersS1('z' - 'a' + 1), lettersS2('z' - 'a' + 1);

        for (char letter : s1) lettersS1[letter - 'a']++;
        
        for(int i = 0; i < s1.size(); i++) lettersS2[s2[i] - 'a']++;

        for (int i = s1.size(); i < s2.size(); i++)
        {
            if (lettersS1 == lettersS2) return true;

            lettersS2[s2[i] - 'a']++;
            lettersS2[s2[i - s1.size()] - 'a']--;
        }

        return lettersS1 == lettersS2;
    }
};
