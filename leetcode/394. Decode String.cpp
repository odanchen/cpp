class Solution {
public:
    string getSubstr(string s, int start) {
        int brace = 1;
        int right = start + 1;
        while(brace > 0) {
            if (s[right] == '[') brace++;
            if (s[right] == ']') brace--;
            right++;
        }
        return s.substr(start + 1, right - 2 - start);
    }
    string decodeString(string s) {
        if (s.find_first_of("[") == -1) return s;

        int start = 0;
        while (start < s.size()) {
            int left = s.find_first_of("0123456789");
            int right = s.find_first_of("[");
            if (left == -1) return s;

            int cnt = stoi(s.substr(left, right - left));

            string subStrUndec = getSubstr(s, right);
            right += subStrUndec.size() + 2;
            string partSrt = decodeString(subStrUndec);
            string newStr;
            for (int i = 0; i < cnt; i++) {
                newStr += partSrt;
            }
            start = left;
            s.replace(left, right - left, newStr);
        }
        return s;
    }
};
