class Solution {
public:
    int getGrade(int num) {
        int cnt = 0;
        while (num) {
            num /= 10;
            cnt++;
        }
        return cnt;
    }
    int compress(vector<char>& chars) {
        int ans = 0, left = 0, right = 0;
        vector<char> newChars;
        while (right < chars.size()){
            while (right < chars.size() and chars[left] == chars[right]) right++;
            if (right - left == 1) {
                ans++;
                newChars.push_back(chars[left]);
            }
            else {
                ans += 1 + getGrade(right - left);
                newChars.push_back(chars[left]);
                for (char val : to_string(right - left)) {
                    newChars.push_back(val);
                }
            }
            left = right;
        }
        chars = newChars;
        return ans;
    }
};
