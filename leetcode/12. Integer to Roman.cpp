class Solution {
public:
    string intToRoman(int num) {
        vector<string> map1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII","IX"};
        vector<string> map2 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX","XC"};
        vector<string> map3 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC","CM"};
        vector<string> map4 = {"", "M", "MM", "MMM"};

        return map4[(num / 1000)] + map3[((num % 1000) / 100)] + map2[((num % 100) / 10)] + map1[((num % 10))];
    }
};
