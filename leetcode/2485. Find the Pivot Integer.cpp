class Solution {
public:
    int pivotInteger(int n) {
        vector<int> left(n + 1), right(n + 1);
        for (int i = 1; i <= n; i++) left[i] = left[i - 1] + i;
        right.back() = n;
        for (int i = right.size() - 2; i > 0; i--) right[i] = right[i + 1] + i;
        for (int i = 1; i <= n; i++) if (right[i] == left[i]) return i;
        return -1;
    }
};
