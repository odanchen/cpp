class Solution {
public:
    int maxVowels(string s, int k) {
        int ans = 0, left = 0, right = 0, cur = 0;
        unordered_set<char> vovels({'a','e','i','o','u'});
        while (right < s.size()) {
            cur += vovels.find(s[right++]) == vovels.end() ? 0 : 1;
            if (right - left == k) {
                ans = max(ans, cur);
                cur -= vovels.find(s[left++]) == vovels.end() ? 0 : 1;
            }
        }
        return ans;
    }
};
