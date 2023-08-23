class Solution {
public:
    int countAsterisks(string s) {
        bool isPair = false;
        int ans = 0;
        for (char c: s) {
            if (c == '|') isPair = !isPair;
            if (c == '*' and !isPair) ans++;
        }
        return ans;
    }
};
