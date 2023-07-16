class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(128);
        int left = 0, right = 0;
        while (right < s.size()) {
            hash[s[right++]]++;
            if (any_of(hash.begin(), hash.end(), [](int a){return a > 1;})) hash[s[left++]]--;
        }
        return right - left;
    }
};
