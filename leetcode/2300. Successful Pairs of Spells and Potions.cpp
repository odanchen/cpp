class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for (int spell: spells) {
            size_t left = 0, right = potions.size() - 1;
            while (left < right) {
                size_t mid = (left + right) / 2;
                if ((long long) spell * potions[mid] < success) left = mid + 1;
                else right = mid;
            }
            if (left == potions.size() - 1) ans.push_back((long long) spell * potions[left] >= success ? 1 : 0);
            else ans.push_back(potions.size() - left);
        }
        return ans;
    }
};
