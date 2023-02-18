class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt = 0;
        for (auto it = arr1.begin(); it != arr1.end(); it++) {
            bool found = false;
            for (auto ar = arr2.begin(); ar != arr2.end() and !found; ar++) {
                if (abs(*it - *ar) <= d) found = true;
            }
            if (!found) cnt++;
        }
        return cnt;
    }
};
