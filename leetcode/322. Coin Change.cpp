class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> coinAmount(amount + 1);
        queue<int> toProcess;
        int cnt = 1;
        for (int coin : coins) if (coin <= amount) toProcess.push(coin);
        while(!toProcess.empty()) {
            int step = toProcess.size();
            for (int i = 0; i < step; i++) {
                int val = toProcess.front();
                toProcess.pop();
                if (coinAmount[val] != 0) continue;
                coinAmount[val] = cnt;
                for (int coin : coins) {
                    if ((long long)val + coin <= amount and coinAmount[val + coin] == 0) 
                        toProcess.push(val + coin);
                }
            }
            cnt++;
        }
        return coinAmount.back() == 0 and amount != 0 ? -1 : coinAmount.back();
    }
};
