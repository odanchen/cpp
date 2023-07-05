class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> winPos(n);
        for (int i = 0; i < 3 and i < n; i++) winPos[i] = i & 1;
        for (int i = 3; i < n; i++) {
            for (int div = 1; div <= (i + 1) / 2; div++) {
                if ((i + 1) % div == 0 and !winPos[i - div]) {
                    winPos[i] = true;
                    break;
                }
            }
        }
        return winPos.back();
    }
};
