class Solution {
public:
    string addBinary(string a, string b) {
        int temp = 0, idx1 = a.size() - 1, idx2 = b.size() - 1;
        string s = (a.size() > b.size()) ? a : b;
        for (int i = max(a.size(), b.size()) - 1; i >= 0; i--) {
            int sum = ((idx1 < 0) ? 0 : a[idx1--] - '0') + ((idx2 < 0) ? 0 : b[idx2--] - '0') + temp;
            s[i] = sum % 2 + '0';
            temp = sum / 2;
        }
        if (temp == 1) s.insert(0, "1");
        return s;
    }
};
