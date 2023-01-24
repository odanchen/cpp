class Solution {
public:
    void fillMap(int map[])
    {
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
    }
    int romanToInt(string s) {
        int map['X' + 1];
        fillMap(map);
        char maxSymbol = 'I';

        int sum = 0;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(map[maxSymbol] < map[s[i]]) maxSymbol = s[i];

            if(maxSymbol == s[i]) sum += map[s[i]];
            else sum -= map[s[i]];
        }

        return sum;
    }
};
