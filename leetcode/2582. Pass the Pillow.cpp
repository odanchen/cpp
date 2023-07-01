class Solution {
public:
    int passThePillow(int n, int time) {
        time %= 2 * (n - 1);
        return time < n ? time + 1 : 2 * n - time - 1;
    }
};
