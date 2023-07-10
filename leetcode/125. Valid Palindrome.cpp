class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right) {
            if (!isalpha(s[left]) and !isdigit(s[left])) left++;
            else if (!isalpha(s[right]) and !isdigit(s[right])) right--;
            else if (tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};
