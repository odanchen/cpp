class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0) return 0;
        vector <int> freq(26);
        int left = 0, maxFreq = 0;
        for (int right = 0; right < s.size(); right++) {
            maxFreq = max(maxFreq, ++freq[s[right] - 'A']);
            if (right - left - maxFreq + 1 > k)
                freq[s[left++] - 'A']--;
        }
        return s.length() - left;
    }
};
