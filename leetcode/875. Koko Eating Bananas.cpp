class Solution {
public:
    bool checkRate(vector<int>& piles, int h, int rate) {
        int cnt = 0;
        for (int val : piles) cnt += val / rate + (val % rate == 0 ? 0 : 1);
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while(left < right) {
            int mid = (left + right) / 2;
            if (checkRate(piles, h, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
