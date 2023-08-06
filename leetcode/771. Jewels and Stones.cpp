class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        set<char> valuable(jewels.begin(), jewels.end());
        return count_if(stones.begin(), stones.end(), [&](char val){return valuable.find(val) != valuable.end();});
    }
};
