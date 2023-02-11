class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1, t1;
        for (char val : s) {
            if (val == '#' and !s1.empty()) s1.pop_back();
            else if(val != '#') s1.push_back(val);
        }
        for (char val : t) {
            if (val == '#' and !t1.empty()) t1.pop_back();
            else if(val != '#') t1.push_back(val);
        }
        return s1 == t1;
    }
};
