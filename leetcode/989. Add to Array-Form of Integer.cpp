class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int temp = 0, idx = num.size() - 1;
        while (k != 0 or temp != 0) {
            if (idx >= 0) {
                int add = num[idx] + k % 10 + temp;
                num[idx--] = add % 10;
                temp = add / 10;
                k /= 10;
            } else {
                int add = k % 10 + temp;
                num.insert(num.begin(), add % 10);
                temp = add / 10;
                k /= 10;
            }
        }
        return num;
    }
};
