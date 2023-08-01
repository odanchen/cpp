class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < flowerbed.size(); i++) {
            if ((i == 0 or !flowerbed[i - 1]) and (i == flowerbed.size() - 1 or !flowerbed[i + 1]) and !flowerbed[i]) {
                i++, n--;
            }
            if (n <= 0) return true;
        }        
        return n <= 0;
    }
};
