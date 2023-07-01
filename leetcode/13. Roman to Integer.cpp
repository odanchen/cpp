class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
                    {'C', 100}, {'D', 500}, {'M', 1000}};
        int maxSymbol = 1, sum = 0;
        for (auto it = s.rbegin(); it != s.rend(); it++) {
            if (maxSymbol < map[*it]) maxSymbol = map[*it];
            sum += map[*it] * (maxSymbol == map[*it] ? 1 : -1);
        }
        return sum;
    }
};
