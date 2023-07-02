class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int cnt = 0;
        for (auto it = citations.rbegin(); it != citations.rend(); it++) {
            if (*it - 1 < cnt++) return cnt - 1;
        }
        return cnt;
    }
};
