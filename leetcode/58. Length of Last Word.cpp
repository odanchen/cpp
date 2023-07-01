class Solution {
public:
    int lengthOfLastWord(string s) {
        int right = s.size() - 1, left;

        while(s[right] == ' ') right--;
        left = right;
        while(left >= 0 and s[left] != ' ') left--;
        
        return right - left;
    }
};
