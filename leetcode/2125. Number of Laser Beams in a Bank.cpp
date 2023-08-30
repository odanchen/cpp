class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cnt = 0, ans = 0;
        for (string &s: bank) {
            int temp = count(s.begin(), s.end(), '1');
            ans += cnt * temp;
            if (temp != 0) cnt = temp;
        }
        return ans;
    }
};
