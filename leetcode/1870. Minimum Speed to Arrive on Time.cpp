class Solution {
public:
    bool checkRate(vector<int>& piles, double h, int rate) {
        double cnt = 0;
        for (int val : piles) cnt = ceil(cnt) + (double) val / rate;
        return cnt <= h;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1, right = *max_element(dist.begin(), dist.end()) * 100;
        while(left < right) {
            int mid = (left + right) / 2;
            if (checkRate(dist, hour, mid)) right = mid;
            else left = mid + 1;
        }
        return checkRate(dist, hour, left) ? left : -1;
    }
};
