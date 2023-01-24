class Solution {
public:
    int getArea(int idx1, int idx2, vector<int> &height)
    {
        return (idx2 - idx1) * min(height[idx1], height[idx2]);
    }
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while(left < right)
        {
            ans  = max(ans, getArea(left, right, height));
            if(height[left] < height[right]) left++;
            else right--;
        }

        return ans;
    }
};
