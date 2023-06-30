class Solution {
public:
    int getArea(vector<int>::iterator a, vector<int>::reverse_iterator b, int len) {
        return min(*a, *b) * len;
    }
    int maxArea(vector<int>& height) {
        auto left = height.begin();
        auto right = height.rbegin();
        int len = height.size() - 1, ans = getArea(left, right, len);
        while(len > 0) {
            if (*left > *right) ans = max(ans, getArea(left, ++right, --len));
            else ans = max(ans, getArea(++left, right, --len));
        }
        return ans;
    }
};
