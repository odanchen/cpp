class Solution {
public:
    int mostWordsFound(vector<string> &sentences) {
        auto res = *max_element(sentences.begin(), sentences.end(), [](string &a, string &b) {
            return count(a.begin(), a.end(), ' ') < count(b.begin(), b.end(), ' ');
        });
        return count(res.begin(), res.end(), ' ') + 1;
    }
};
